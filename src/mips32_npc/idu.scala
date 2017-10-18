//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------


package NPC

import chisel3._
import chisel3.util._

import Common._
import Common.Instructions._
import Constants._

class IDU_IO extends Bundle() 
{
  val instr = Flipped(DecoupledIO(new IFU_IDU_IO()))
  val decode = DecoupledIO(new IDU_ISU_IO())
}

class IDU extends Module
{
  val io = IO(new IDU_IO())
  val instr = io.instr.bits.instr
  val csignals = ListLookup(instr,
    List(N, FU_X, FU_OP_X, OP1_X, OP2_X), Array(
      /* instr | fu_type  |  fu_op  |  op1_sel  |  op2_sel */
     LUI     -> List(Y, FU_ALU,  ALU_COPY1,  OP1_IMU,  OP2_X)
     ))

  val (val_inst: Bool) :: fu_type :: fu_op :: op1_sel :: op2_sel :: Nil = csignals

  // here, we do not decode instr, we leave that to ISU
  val decode = io.decode.bits
  decode.instr := instr
  decode.rs := instr(RS_MSB, RS_LSB)
  decode.rt := instr(RT_MSB, RT_LSB)
  decode.rd := instr(RD_MSB, RD_LSB)
  decode.op1_sel := op1_sel
  decode.op2_sel := op2_sel
  decode.fu_type := fu_type
  decode.fu_op := fu_op
}
