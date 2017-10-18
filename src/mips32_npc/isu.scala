//**************************************************************************
// RISCV NJU Out Of Order Processor
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 5

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class ISU_IO extends Bundle() 
{
  val decode = Flipped(DecoupledIO(new IDU_ISU_IO()))
  val reg = new ISU_REG_IO()
  val alu = DecoupledIO(new ISU_ALU_IO())
  val bru = DecoupledIO(new ISU_BRU_IO())
  val lsu = DecoupledIO(new ISU_LSU_IO())
  val csr = DecoupledIO(new ISU_CSR_IO())
}

class ISU extends Module
{
  val io = IO(new ISU_IO())

  val decode = io.decode.bits

  val pc = decode.pc
  val instr = decode.instr
  val rs = decode.rs
  val rt = decode.rt
  val rd = decode.rd
  val op1_sel = decode.op1_sel
  val op2_sel = decode.op2_sel
  val fu_type = decode.fu_type
  val fu_op = decode.fu_op

  // Register File
  io.reg.rs_addr := rs
  io.reg.rt_addr := rt
  val rs_data = io.reg.rs_data
  val rt_data = io.reg.rt_data

  // immediates
  val imm = Cat(instr(15, 0), Fill(16, 0.U))

  // sign-extend immediates

  val op1 = MuxCase(0.U, Array(
    (op1_sel === OP1_RS) -> rs_data,
    (op1_sel === OP1_IMU) -> imm
    )).toUInt

  val op2 = MuxCase(0.U, Array(
    (op2_sel === OP2_RT) -> rt_data
  )).toUInt

  // ALU
  val alu = io.alu.bits
  alu.a := op1
  alu.b := op2
  alu.rd := rd
  alu.fu_op := fu_op
  io.alu.valid := (fu_type === FU_ALU)

  // BRU
  val bru = io.bru.bits
  io.bru.valid := (fu_type === FU_BRU)

  // LSU
  val lsu = io.lsu.bits
  io.lsu.valid := (fu_type === FU_LSU)

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
