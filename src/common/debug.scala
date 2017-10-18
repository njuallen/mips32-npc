package Common

import chisel3._
import chisel3.util._
import Common._
import Common.Util._
import Util._
import Constants._

// for now, we directly connect these signals out
// we may need a DebugModule later

// internal debug interface
// register file debug interface
class DebugRegIO extends Bundle
{
  val reg = Input(Vec(32, UInt(conf.xprlen.W)))
}

class DebugIFUIO extends Bundle
{
  val pc = Input(UInt(conf.xprlen.W))
  // number of instruction retired
  val ninstr_retired = Input(UInt(64.W))
  val freeze = Output(Bool())
}

// external debug interface
class DebugIO extends Bundle
{
  val reg = Input(Vec(32, UInt(conf.xprlen.W)))
  val pc = Input(UInt(conf.xprlen.W))
  // number of instruction retired
  val ninstr_retired = Input(UInt(64.W))
  val freeze = Output(Bool())
}

// a trivial DebugModule
// it only wire things together
class DebugModule extends Module {
  val io = IO(new Bundle {
    val di = Flipped(new DebugIO())
    val reg = new DebugRegIO()
    val ifu = new DebugIFUIO()
  })
  val di = io.di
  val reg = io.reg
  val ifu = io.ifu

  di.reg := reg.reg
  di.pc := ifu.pc
  di.ninstr_retired := ifu.ninstr_retired
  ifu.freeze := di.freeze
}
