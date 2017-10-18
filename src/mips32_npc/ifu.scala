//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class IFU_IO extends Bundle()
{
  val instr = DecoupledIO(new IFU_IDU_IO())
  val branch = Flipped(DecoupledIO(new WBU_IFU_BRANCH_IO()))
  val exception = Flipped(DecoupledIO(new WBU_IFU_EXCEPTION_IO()))
  val dmem_stall = Flipped(new LSU_IFU_IO())
  val imem = new MemPortIo(conf.xprlen, conf.xprlen)

  val freeze = Input(Bool())
  val instr_commit = Output(Bool())
  val pc = Output(UInt(32.W))
}

class IFU extends Module
{
  val io = IO(new IFU_IO())

  // Instruction Fetch
  val pc_reg = Reg(init = START_ADDR)
  val pc_next = Wire(UInt(conf.xprlen.W))

  val branch = io.branch.bits
  val exception = io.exception.bits
  pc_next := MuxCase(pc_reg + 4.asUInt(conf.xprlen.W), Array(
    (io.branch.valid && branch.is_taken)  -> branch.pc_branch,
    (io.exception.valid && exception.eret)  -> exception.evec))

  // whenever pc is updated
  // we know that an instruction has committed
  // note that: we can not determine whether an instruction has executed
  // simply by checking pc
  // what if there is a dead loop like this:
  // loop: jal loop
  val stall = io.dmem_stall.dmem_stall
  val update_pc = !stall && !io.freeze
  when (update_pc) { pc_reg := pc_next }
  io.instr_commit := update_pc

  // instruction fetch
  io.imem.req.bits.addr := pc_reg
  io.imem.req.valid := Y

  // IFU_IDU_instr
  val instr = io.instr.bits
  io.instr.valid := Y
  instr.pc := pc_reg 

  /* when we are freezed or reset
   * fesvr may be modifying memory
   * so imem's response may not be consistent
   * so we insert bubbles in these stages
   * BUBBLE will not change processor state
   */
  instr.instr := Mux(io.imem.resp.valid && !io.freeze, io.imem.resp.bits.data, BUBBLE) 

  //// DebugLite DebugModule
  io.pc := pc_reg

  // print out
  // printf("pc= 0x%x instr= 0x%x ", pc_reg, io.imem.resp.bits.data)
}
