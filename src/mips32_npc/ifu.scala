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
  val imem = new MemPortIo(conf.xprlen, conf.xprlen)
  val debug = Flipped(new DebugIFUIO())
}

class IFU extends Module
{
  val io = IO(new IFU_IO())

  // Instruction Fetch
  val pc_reg = Reg(init = START_ADDR)
  val pc_next = Wire(UInt(conf.xprlen.W))

  pc_next := pc_reg + 4.asUInt(conf.xprlen.W)

  when (!io.debug.freeze) { pc_reg := pc_next }

  // instruction fetch
  io.imem.req.bits.addr := pc_reg
  io.imem.req.valid := Y

  // IFU_IDU_instr
  val instr = io.instr.bits
  io.instr.valid := Y

  instr.instr := Mux(io.imem.resp.valid && !io.debug.freeze, io.imem.resp.bits.data, BUBBLE)

  //// DebugModule IO
  io.debug.pc := pc_reg

  // print out
  printf("pc= 0x%x instr= 0x%x\n", pc_reg, io.imem.resp.bits.data)
}
