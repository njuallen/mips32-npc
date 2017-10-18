//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class ALU_IO extends Bundle() 
{
  val datain = Flipped(DecoupledIO(new ISU_ALU_IO()))
  val res = DecoupledIO(new ALU_WBU_IO())
}

class ALU extends Module
{
  val io = IO(new ALU_IO())

  val datain = io.datain.bits
  val alu_op1 = datain.a
  val alu_op2 = datain.b
  val alu_op = datain.fu_op
  val alu_out = MuxCase(0.U, Array(
    (alu_op === ALU_COPY1)-> alu_op1
  ))

  val res = io.res.bits
  io.res.valid := io.datain.valid
  res.value := alu_out
  res.rd := io.datain.bits.rd

  /*
  printf("[ALU] valid= %c alu_op1= 0x%x alu_op2= 0x%x alu_op=%d alu_out= 0x%x ",
    Mux(io.datain.valid, Str("Y"), Str("N")),
    alu_op1,
    alu_op2,
    alu_op,
    alu_out
    )
    */
}
