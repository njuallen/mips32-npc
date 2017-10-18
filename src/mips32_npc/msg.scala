//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._


import Constants._
import Common._
import Common.Constants._

// from the pov of the datapath
class IFU_IDU_IO extends Bundle 
{
  val instr = Output(UInt(conf.xprlen.W))
}

class IDU_ISU_IO extends Bundle 
{
  val instr = Output(UInt(conf.xprlen.W))
  val rs = Output(UInt(5.W))
  val rt = Output(UInt(5.W))
  val rd = Output(UInt(5.W))
  val op1_sel = Output(UInt(OP1_SEL_SZ.W))
  val op2_sel = Output(UInt(OP2_SEL_SZ.W))
  val fu_type = Output(UInt(FU_TYPE_SZ.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
}

class WBU_REG_IO extends Bundle
{
  val waddr = Output(UInt(5.W))
  val wdata = Output(UInt(conf.xprlen.W))
  val wen = Output(UInt(conf.xprlen.W))
}

class ISU_ALU_IO extends Bundle
{
  val a = Output(UInt(conf.xprlen.W))
  val b = Output(UInt(conf.xprlen.W))
  val rd = Output(UInt(5.W))
  val fu_op = Output(UInt(FU_OP_SZ.W))
}

class ALU_WBU_IO extends Bundle 
{
  val value = Output(UInt(conf.xprlen.W))
  val rd = Output(UInt(5.W))
}
