//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._
import Common._

class CoreIO extends Bundle 
{
  val imem = new MemPortIo(conf.xprlen, conf.xprlen)
  val dmem = new MemPortIo(conf.xprlen, conf.xprlen)
  val debug = Flipped(new DebugIO())
}

class Core extends Module
{
  val io = IO(new CoreIO())

  val ifu  = Module(new IFU())
  val idu  = Module(new IDU())
  val isu  = Module(new ISU())
  val alu  = Module(new ALU())
  val wbu  = Module(new WBU())
  val regfile = Module(new RegisterFile())
  val debug = Module(new DebugModule())

  // main data path
  io.imem <> ifu.io.imem
  ifu.io.instr <> idu.io.instr
  idu.io.decode <> isu.io.decode
  isu.io.alu <> alu.io.datain
  alu.io.res <> wbu.io.alu


  // write regfile
  regfile.io.waddr := wbu.io.reg.waddr
  regfile.io.wdata := wbu.io.reg.wdata
  regfile.io.wen := wbu.io.reg.wen

  // debug data path
  debug.io.di <> io.debug
  debug.io.reg <> regfile.io.debug
  debug.io.ifu <> ifu.io.debug
}
