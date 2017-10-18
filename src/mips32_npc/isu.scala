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
  val rs1 = decode.rs1
  val rs2 = decode.rs2
  val rd = decode.rd
  val op1_sel = decode.op1_sel
  val op2_sel = decode.op2_sel
  val fu_type = decode.fu_type
  val fu_op = decode.fu_op

  // Register File
  io.reg.rs1_addr := rs1
  io.reg.rs2_addr := rs2
  val rs1_data = io.reg.rs1_data
  val rs2_data = io.reg.rs2_data

  // immediates
  val imm_i = instr(31, 20) 
  val imm_s = Cat(instr(31, 25), instr(11,7))
  val imm_b = Cat(instr(31), instr(7), instr(30,25), instr(11,8))
  val imm_u = instr(31, 12)
  val imm_j = Cat(instr(31), instr(19,12), instr(20), instr(30,21))
  val imm_z = Cat(Fill(27,0.U), instr(19,15))

  // sign-extend immediates
  val imm_i_sext = Cat(Fill(20,imm_i(11)), imm_i)
  val imm_s_sext = Cat(Fill(20,imm_s(11)), imm_s)
  val imm_b_sext = Cat(Fill(19,imm_b(11)), imm_b, 0.U)
  val imm_u_sext = Cat(imm_u, Fill(12,0.U))
  val imm_j_sext = Cat(Fill(11,imm_j(19)), imm_j, 0.U)

  val op1 = MuxCase(0.U, Array(
    (op1_sel === OP1_RS1) -> rs1_data,
    (op1_sel === OP1_IMU) -> imm_u_sext,
    (op1_sel === OP1_IMZ) -> imm_z
  )).toUInt

  val op2 = MuxCase(0.U, Array(
    (op2_sel === OP2_RS2) -> rs2_data,
    (op2_sel === OP2_PC)  -> pc,
    (op2_sel === OP2_IMI) -> imm_i_sext,
    (op2_sel === OP2_IMS) -> imm_s_sext
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
  bru.a := op1
  bru.b := op2
  bru.pc := pc
  bru.offset := MuxCase(imm_b_sext, Array(
    (fu_op === BR_J)   -> imm_j_sext,
    (fu_op === BR_JR)  -> imm_i_sext
  ))
  bru.rd := rd
  bru.fu_op := fu_op
  io.bru.valid := (fu_type === FU_BRU)

  // LSU
  val lsu = io.lsu.bits
  lsu.base := op1
  lsu.offset := op2
  lsu.wdata := rs2_data // strore
  lsu.rd := rd // load
  lsu.fu_op := fu_op
  io.lsu.valid := (fu_type === FU_LSU)

  // CSR
  val csr = io.csr.bits
  csr.wdata := op1
  csr.instr := instr
  csr.pc := pc
  csr.rs1 := rs1
  csr.rd := rd
  csr.exception := io.decode.bits.exception
  csr.fu_op := fu_op
  io.csr.valid := (fu_type === FU_CSR)

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
