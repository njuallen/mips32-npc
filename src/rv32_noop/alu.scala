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
  val alu_shamt = alu_op2(4,0).toUInt
  val alu_out = MuxCase(0.U, Array(
    (alu_op === ALU_ADD)  -> (alu_op1 + alu_op2).toUInt,
    (alu_op === ALU_SUB)  -> (alu_op1 - alu_op2).toUInt,
    (alu_op === ALU_AND)  -> (alu_op1 & alu_op2).toUInt,
    (alu_op === ALU_OR)   -> (alu_op1 | alu_op2).toUInt,
    (alu_op === ALU_XOR)  -> (alu_op1 ^ alu_op2).toUInt,
    (alu_op === ALU_SLT)  -> (alu_op1.toSInt < alu_op2.toSInt).toUInt,
    (alu_op === ALU_SLTU) -> (alu_op1 < alu_op2).toUInt,
    (alu_op === ALU_SLL)  -> ((alu_op1 << alu_shamt)(XPRLEN - 1, 0)).toUInt,
    (alu_op === ALU_SRA)  -> (alu_op1.toSInt >> alu_shamt).toUInt,
    (alu_op === ALU_SRL)  -> (alu_op1 >> alu_shamt).toUInt,
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
