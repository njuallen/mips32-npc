//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class ISU_IO extends Bundle() 
{
  val decode = Flipped(DecoupledIO(new IDU_ISU_IO()))
  val alu = DecoupledIO(new ISU_ALU_IO())
}

class ISU extends Module
{
  val io = IO(new ISU_IO())

  val decode = io.decode.bits

  val instr = decode.instr
  val rs = decode.rs
  val rt = decode.rt
  val rd = decode.rd
  val op1_sel = decode.op1_sel
  val op2_sel = decode.op2_sel
  val fu_type = decode.fu_type
  val fu_op = decode.fu_op

  // immediates
  val imm = Cat(instr(15, 0), Fill(16, 0.U))

  val op1 = MuxCase(0.U, Array(
    (op1_sel === OP1_IMU) -> imm
  )).toUInt

  val op2 = 0.U

  // ALU
  val alu = io.alu.bits
  alu.a := op1
  alu.b := op2
  alu.rd := rd
  alu.fu_op := fu_op
  io.alu.valid := (fu_type === FU_ALU)

  // Printout
  /*
  printf("[ISU] PC= 0x%x instr= 0x%x fu_type= %d fu_op= %d\n",
    pc,
    instr,
    fu_type,
    fu_op
    )
    */
}
