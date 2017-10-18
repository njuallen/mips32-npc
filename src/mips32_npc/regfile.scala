//**************************************************************************
// RISCV Processor Register File
//--------------------------------------------------------------------------
//

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._

class RFileIo extends Bundle()
{
  // two read ports
  val rs_addr = Input(UInt(5.W))
  val rs_data = Output(UInt(conf.xprlen.W))
  val rt_addr = Input(UInt(5.W))
  val rt_data = Output(UInt(conf.xprlen.W))

  // one write port
  val waddr    = Input(UInt(5.W))
  val wdata    = Input(UInt(conf.xprlen.W))
  val wen      = Input(Bool())

  // debug module interface
  val debug = Flipped(new DebugRegIO())
}

class RegisterFile extends Module
{
  val io = IO(new RFileIo())

  val regfile = Mem(UInt(conf.xprlen.W), 32)

  printf("waddr= %d wdata= 0x%x ", io.waddr, io.wdata)

  when (io.wen && (io.waddr != 0.U))
  {
    regfile(io.waddr) := io.wdata
  }

  io.rs_data := Mux((io.rs_addr != 0.U), regfile(io.rs_addr), 0.U)
  io.rt_data := Mux((io.rt_addr != 0.U), regfile(io.rt_addr), 0.U)

  //// DebugLite DebugModule
  io.debug.reg.zipWithIndex.map { case(t, i) => t := regfile(i.U) }
}
