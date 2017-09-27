//**************************************************************************
// RISCV NJU Out Of Order Processor
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 5

package Sodor

import chisel3._
import chisel3.util._


import Constants._
import Common._
import Common.Constants._

// from the pov of the datapath
class IFU_IDU_IO extends Bundle 
{
  val pc = Output(UInt(XPRLEN.W))
  val instr = Output(UInt(XPRLEN.W))
  override def cloneType = { new IFU_IDU_IO().asInstanceOf[this.type] }
}

class IDU_ISU_IO extends Bundle 
{
  val pc = Output(UInt(XPRLEN.W))
  val instr = Output(UInt(XPRLEN.W))
  val rs1 = Output(UInt(5.W))
  val rs2 = Output(UInt(5.W))
  val rd = Output(UInt(5.W))
  val op1_sel = Output(UInt(OP1_SEL_SZ.W))
  val op2_sel = Output(UInt(OP2_SEL_SZ.W))
  val fu_type = Output(UInt(FU_TYPE_SZ.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
  val exception = Output(Bool())
  override def cloneType = { new IDU_ISU_IO().asInstanceOf[this.type] }
}

class ISU_REG_IO extends Bundle
{
  val rs1_addr = Output(UInt(5.W))
  val rs2_addr = Output(UInt(5.W))
  val rs1_data = Input(UInt(XPRLEN.W))
  val rs2_data = Input(UInt(XPRLEN.W))
  override def cloneType = { new ISU_REG_IO().asInstanceOf[this.type] }
}

class WBU_REG_IO extends Bundle
{
  val waddr = Output(UInt(5.W))
  val wdata = Output(UInt(XPRLEN.W))
  val wen = Output(UInt(XPRLEN.W))
  override def cloneType = { new WBU_REG_IO().asInstanceOf[this.type] }
}

class ISU_ALU_IO extends Bundle
{
  val a = Output(UInt(XPRLEN.W))
  val b = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
  override def cloneType = { new ISU_ALU_IO().asInstanceOf[this.type] }
}

class ISU_BRU_IO extends Bundle 
{
  val a = Output(UInt(XPRLEN.W))
  val b = Output(UInt(XPRLEN.W))
  val pc = Output(UInt(XPRLEN.W))
  val offset = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
  override def cloneType = { new ISU_BRU_IO().asInstanceOf[this.type] }
}

class ISU_LSU_IO extends Bundle 
{
  val base = Output(UInt(XPRLEN.W))
  val offset = Output(UInt(XPRLEN.W))
  val wdata = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
  override def cloneType = { new ISU_LSU_IO().asInstanceOf[this.type] }
}

class ISU_CSR_IO extends Bundle 
{
  val wdata = Output(UInt(XPRLEN.W))
  val pc = Output(UInt(XPRLEN.W))
  val instr = Output(UInt(XPRLEN.W))
  val rs1 = Output(UInt(5.W))
  val rd = Output(UInt(5.W))
  val exception = Output(Bool())
  val fu_op = Output(UInt(FU_OP_SZ.W))
  override def cloneType = { new ISU_CSR_IO().asInstanceOf[this.type] }
}

class ALU_WBU_IO extends Bundle 
{
  val value = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  override def cloneType = { new ALU_WBU_IO().asInstanceOf[this.type] }
}

class BRU_WBU_IO extends Bundle 
{
  val value = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val wen = Output(Bool())
  val target = Output(UInt(XPRLEN.W))
  val is_taken = Output(Bool())
  override def cloneType = { new BRU_WBU_IO().asInstanceOf[this.type] }
}

class LSU_WBU_IO extends Bundle 
{
  val value = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val wen = Output(Bool())
  override def cloneType = { new LSU_WBU_IO().asInstanceOf[this.type] }
}

class CSR_WBU_IO extends Bundle 
{
  val value = Output(UInt(XPRLEN.W))
  val rd = Output(UInt(5.W))
  val wen = Output(Bool())
  // new pc when raising an exception or eret
  val evec = Output(UInt(XPRLEN.W))
  // whether an exception or eret is raised
  val eret = Output(Bool())
  override def cloneType = { new CSR_WBU_IO().asInstanceOf[this.type] }
}

class WBU_IFU_BRANCH_IO extends Bundle 
{
  val pc_branch = Output(UInt(XPRLEN.W))
  val is_taken = Output(Bool())
  override def cloneType = { new WBU_IFU_BRANCH_IO().asInstanceOf[this.type] }
}

class WBU_IFU_EXCEPTION_IO extends Bundle 
{
  val evec = Output(UInt(XPRLEN.W))
  val eret = Output(Bool())
  override def cloneType = { new WBU_IFU_EXCEPTION_IO().asInstanceOf[this.type] }
}

class LSU_IFU_IO extends Bundle 
{
  val dmem_stall = Output(Bool())
  override def cloneType = { new LSU_IFU_IO().asInstanceOf[this.type] }
}
