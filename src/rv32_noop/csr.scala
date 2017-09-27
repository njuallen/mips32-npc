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

class CSR_IO(implicit conf: SodorConfiguration) extends Bundle()
{
  val datain = Flipped(DecoupledIO(new ISU_CSR_IO()))
  val res = DecoupledIO(new CSR_WBU_IO())
}

class CSR(implicit conf: SodorConfiguration) extends Module
{
  val io = IO(new CSR_IO())

  val datain = io.datain.bits
  val wdata = datain.wdata
  val instr = datain.instr
  val pc = datain.pc
  val rs1 = datain.rs1
  val rd = datain.rd
  val exception = datain.exception
  val csr_op = datain.fu_op

  val csr_cmd = MuxCase(CSR.N, Array(
    (csr_op === CSR_CSRRWI)  ->   CSR.W,
    (csr_op === CSR_CSRRSI)  ->   CSR.S,
    (csr_op === CSR_CSRRCI)  ->   CSR.C,
    (csr_op === CSR_CSRRW)   ->   CSR.W,
    (csr_op === CSR_CSRRS)   ->   CSR.S,
    (csr_op === CSR_CSRRC)   ->   CSR.C,
    (csr_op === CSR_ECALL)   ->   CSR.I,
    (csr_op === CSR_MRET)    ->   CSR.I,
    (csr_op === CSR_DRET)    ->   CSR.I,
    (csr_op === CSR_EBREAK)  ->   CSR.I
  ))

  // convert CSR instructions with raddr1 == 0 to read-only CSR commands
  val csr_ren = (csr_cmd === CSR.S || csr_cmd === CSR.C) && rs1 === 0.U
  val cmd = Mux(csr_ren, CSR.R, csr_cmd)

  // Control Status Registers
  val csr = Module(new CSRFile())
  csr.io.hartid := 0.U
  csr.io.decode.csr := instr(CSR_ADDR_MSB,CSR_ADDR_LSB)
  csr.io.rw.cmd := Mux(io.datain.valid, cmd, CSR.N)
  csr.io.rw.wdata := wdata
  csr.io.exception := exception
  csr.io.pc := pc

  // register wen
  val wen = MuxCase(N, Array(
    (csr_op === CSR_CSRRWI)  ->   Y,
    (csr_op === CSR_CSRRSI)  ->   Y,
    (csr_op === CSR_CSRRCI)  ->   Y,
    (csr_op === CSR_CSRRW)   ->   Y,
    (csr_op === CSR_CSRRS)   ->   Y,
    (csr_op === CSR_CSRRC)   ->   Y,
    (csr_op === CSR_ECALL)   ->   N,
    (csr_op === CSR_MRET)    ->   N,
    (csr_op === CSR_DRET)    ->   N,
    (csr_op === CSR_EBREAK)  ->   N
  ))

  val res = io.res.bits
  io.res.valid := io.datain.valid
  res.value := csr.io.rw.rdata
  res.rd := rd
  res.wen := wen
  res.evec := csr.io.evec
  res.eret := csr.io.eret

  /*
  printf("[CSR] valid= %c cmd= %d evec= 0x%x eret= 0x%x ",
    Mux(io.datain.valid, Str("Y"), Str("N")),
    csr.io.rw.cmd,
    res.evec,
    res.eret
    )
  */
}
