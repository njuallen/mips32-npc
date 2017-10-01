//**************************************************************************
// RISCV Processor Register File
//--------------------------------------------------------------------------
//

package Sodor

import chisel3._
import chisel3.util._

import Constants._
import Common._

class RFileIo(implicit conf: SodorConfiguration) extends Bundle()
{
  val rs1_addr = Input(UInt(5.W))
  val rs1_data = Output(UInt(conf.xprlen.W))
  val rs2_addr = Input(UInt(5.W))
  val rs2_data = Output(UInt(conf.xprlen.W))
  val dm_addr = Input(UInt(5.W))
  val dm_rdata = Output(UInt(conf.xprlen.W))
  val dm_wdata = Input(UInt(conf.xprlen.W))
  val dm_en = Input(Bool())

  val waddr    = Input(UInt(5.W))
  val wdata    = Input(UInt(conf.xprlen.W))
  val wen      = Input(Bool())

  // debug
  val reg = Flipped(new DebugLiteRegIo())
}

class RegisterFile(implicit conf: SodorConfiguration) extends Module
{
  val io = IO(new RFileIo())

  val regfile = Mem(UInt(conf.xprlen.W), 32)

  // printf("waddr= %d wdata= 0x%x\n", io.waddr, io.wdata)

  when (io.wen && (io.waddr != 0.U))
  {
    regfile(io.waddr) := io.wdata
  }

  when (io.dm_en && (io.dm_addr != 0.U))
  {
    regfile(io.dm_addr) := io.dm_wdata
  }

  io.rs1_data := Mux((io.rs1_addr != 0.U), regfile(io.rs1_addr), 0.U)
  io.rs2_data := Mux((io.rs2_addr != 0.U), regfile(io.rs2_addr), 0.U)
  io.dm_rdata := Mux((io.dm_addr != 0.U), regfile(io.dm_addr), 0.U)

  //// DebugLite DebugModule
  io.reg.rdata := regfile(io.reg.addr)
  ///
}
