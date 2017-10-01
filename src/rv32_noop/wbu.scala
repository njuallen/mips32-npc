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

class WBU_IO extends Bundle() 
{
  val reg = new WBU_REG_IO()
  val branch = DecoupledIO(new WBU_IFU_BRANCH_IO())
  val exception = DecoupledIO(new WBU_IFU_EXCEPTION_IO())
  val alu = Flipped(DecoupledIO(new ALU_WBU_IO()))
  val bru = Flipped(DecoupledIO(new BRU_WBU_IO()))
  val lsu = Flipped(DecoupledIO(new LSU_WBU_IO()))
  val csr = Flipped(DecoupledIO(new CSR_WBU_IO()))
}

class WBU extends Module
{
  val io = IO(new WBU_IO())

  // Register File
  val wen = MuxCase(N, Array(
    (io.alu.valid)  -> Y,
    (io.bru.valid)  -> io.bru.bits.wen,
    (io.lsu.valid)  -> io.lsu.bits.wen,
    (io.csr.valid)  -> io.csr.bits.wen))

  val waddr = MuxCase(0.asUInt(5.W), Array(
    (io.alu.valid)  -> io.alu.bits.rd,
    (io.bru.valid)  -> io.bru.bits.rd,
    (io.lsu.valid)  -> io.lsu.bits.rd,
    (io.csr.valid)  -> io.csr.bits.rd))

  val wdata = MuxCase(0.asUInt(XPRLEN.W), Array(
    (io.alu.valid)  -> io.alu.bits.value,
    (io.bru.valid)  -> io.bru.bits.value,
    (io.lsu.valid)  -> io.lsu.bits.value,
    (io.csr.valid)  -> io.csr.bits.value))

  io.reg.wen := wen
  io.reg.waddr := waddr
  io.reg.wdata := wdata

  io.branch.valid := io.bru.valid
  io.branch.bits.pc_branch := io.bru.bits.target
  io.branch.bits.is_taken := io.bru.bits.is_taken

  io.exception.valid := io.csr.valid
  io.exception.bits.evec := io.csr.bits.evec
  io.exception.bits.eret := io.csr.bits.eret

  /*
  printf("[WBU] wen= %c waddr= 0x%x wdata= 0x%x ",
    Mux(wen, Str("Y"), Str("N")),
    waddr,
    wdata
    )

  printf("branch_valid= %c branch= 0x%x taken= %c ",
    Mux(io.bru.valid, Str("Y"), Str("N")),
    io.bru.bits.target,
    Mux(io.bru.bits.is_taken, Str("Y"), Str("N"))
    )

  printf("exception_valid= %c evec= 0x%x eret= %c ",
    Mux(io.exception.valid, Str("Y"), Str("N")),
    io.exception.bits.evec,
    Mux(io.exception.bits.eret, Str("Y"), Str("N"))
    )
  */
}
