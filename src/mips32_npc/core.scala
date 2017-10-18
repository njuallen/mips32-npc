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

package NPC

import chisel3._
import chisel3.util._
import Common._

class CoreIo extends Bundle 
{
  val imem = new MemPortIo(conf.xprlen, conf.xprlen)
  val dmem = new MemPortIo(conf.xprlen, conf.xprlen)
  val reset = Input(Bool())

  // for debugging purpose
  val freeze = Input(Bool())
  val instr_commit = Output(Bool())
  val reg = Flipped(new DebugLiteRegIo())
  val pc = Output(UInt(32.W))
}

class Core extends Module
{
  val io = IO(new CoreIo())

  val ifu  = Module(new IFU())
  val idu  = Module(new IDU())
  val isu  = Module(new ISU())
  val alu  = Module(new ALU())
  val bru  = Module(new BRU())
  val lsu  = Module(new LSU())
  val wbu  = Module(new WBU())
  val regfile = Module(new RegisterFile())

  // main data path
  io.imem <> ifu.io.imem
  io.dmem <> lsu.io.dmem
  ifu.io.instr <> idu.io.instr
  idu.io.decode <> isu.io.decode
  isu.io.alu <> alu.io.datain
  isu.io.bru <> bru.io.datain
  isu.io.lsu <> lsu.io.datain
  alu.io.res <> wbu.io.alu
  bru.io.res <> wbu.io.bru
  lsu.io.res <> wbu.io.lsu


  // branch data path
  ifu.io.branch <> wbu.io.branch

  // stall
  ifu.io.dmem_stall <> lsu.io.stall

  // exceptional data path
  wbu.io.exception <> ifu.io.exception

  // regfile access
  regfile.io.rs1_addr := isu.io.reg.rs1_addr
  regfile.io.rs2_addr := isu.io.reg.rs2_addr
  isu.io.reg.rs1_data := regfile.io.rs1_data
  isu.io.reg.rs2_data := regfile.io.rs2_data

  regfile.io.waddr := wbu.io.reg.waddr
  regfile.io.wdata := wbu.io.reg.wdata
  regfile.io.wen := wbu.io.reg.wen

  // debug path
  ifu.io.freeze := io.freeze
  io.pc := ifu.io.pc
  io.instr_commit := ifu.io.instr_commit
  regfile.io.reg <> io.reg
}
