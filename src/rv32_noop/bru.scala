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

class BRU_IO extends Bundle()
{
  val datain = Flipped(DecoupledIO(new ISU_BRU_IO()))
  val res = DecoupledIO(new BRU_WBU_IO())
}

class BRU extends Module
{
  val io = IO(new BRU_IO())

  val datain = io.datain.bits
  val res = io.res.bits

  val op1 = datain.a
  val op2 = datain.b
  val pc = datain.pc
  val offset = datain.offset
  val rd = datain.rd
  val bru_op = datain.fu_op

  val is_taken = MuxCase(N, Array(
    (bru_op === BR_NE)  -> (op1 != op2).toBool,
    (bru_op === BR_EQ)  -> (op1 === op2).toBool,
    (bru_op === BR_GE)  -> (op1.toSInt >= op2.toSInt).toBool,
    (bru_op === BR_GEU) -> (op1.toUInt >= op2.toUInt).toBool,
    (bru_op === BR_LT)  -> (op1.toSInt < op2.toSInt).toBool,
    (bru_op === BR_LTU) -> (op1.toUInt < op2.toUInt).toBool,
    (bru_op === BR_J)   -> Y,
    (bru_op === BR_JR)  -> Y
  ))

  io.res.valid := io.datain.valid
  res.value := (pc + 4.asUInt(XPRLEN.W)) // instruction after the current instruction
  res.rd := rd
  res.wen := (bru_op === BR_J || bru_op === BR_JR)
  // JAL/Branch or JALR
  res.target := Mux(bru_op === BR_JR, op1 + offset, pc + offset)
  res.is_taken := is_taken

  /*
  printf("[BRU] valid= %c op1= 0x%x op2= 0x%x bru_op= %d pc= 0x%x offset= 0x%x target= 0x%x taken= %c\n",
    Mux(io.datain.valid, Str("Y"), Str("N")),
    op1,
    op2,
    bru_op,
    pc,
    offset,
    res.target,
    Mux(is_taken, Str("Y"), Str("N"))
    )
  */
}
