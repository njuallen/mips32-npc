//**************************************************************************
// RISCV Processor 
//--------------------------------------------------------------------------
//
// Christopher Celio
// 2011 Jul 30
//
// Describes a simple RISCV 1-stage processor
//   - No div/mul/rem
//   - No FPU
//   - implements a minimal supervisor mode (can trap to handle the
//       above instructions)
//
// The goal of the 1-stage is to provide the simpliest, easiest-to-read code to
// demonstrate the RISC-V ISA.

package Sodor

import chisel3._
import chisel3.util._
import Common._

class CoreIo(implicit conf: SodorConfiguration) extends Bundle 
{
  val imem = new MemPortIo(conf.xprlen, conf.xprlen)
  val dmem = new MemPortIo(conf.xprlen, conf.xprlen)
  val reset = Input(Bool())

  // for debugging purpose
  val freeze = Input(Bool())
  val instr_commit = Output(Bool())
  val reg = Flipped(new DebugLiteRegIo())
  val pc = Output(UInt(32.W))
  val instr = Output(UInt(32.W))
  val imem_resp_valid = Output(Bool())
  val dmem_resp_valid = Output(Bool())
}

class Core(implicit conf: SodorConfiguration) extends Module
{
  val io = IO(new CoreIo())
  val c  = Module(new CtlPath())
  val d  = Module(new DatPath())
  c.io.ctl  <> d.io.ctl
  c.io.dat  <> d.io.dat

  io.imem <> c.io.imem
  io.imem <> d.io.imem

  io.dmem <> c.io.dmem
  io.dmem <> d.io.dmem
  io.dmem.req.valid := c.io.dmem.req.valid
  io.dmem.req.bits.typ := c.io.dmem.req.bits.typ
  io.dmem.req.bits.fcn := c.io.dmem.req.bits.fcn

  // all the registers are in dpath
  // so we only need to freeze dpath
  d.io.freeze := io.freeze
  d.io.reg <> io.reg
  io.pc := d.io.pc
  io.instr_commit := d.io.instr_commit
  io.instr := d.io.instr
  io.imem_resp_valid := d.io.imem_resp_valid
  io.dmem_resp_valid := d.io.dmem_resp_valid
}
