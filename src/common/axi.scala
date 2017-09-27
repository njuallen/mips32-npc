//**************************************************************************
// AXIIO
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 5

package Common

import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import chisel3.experimental._

import Constants._
import Common._
import Common.Util._

class AXI4LiteIO(data_width: Int) extends Bundle
{
  // write address channel signals
  val awaddr = Output(UInt(32.W))
  val awprot = Output(UInt(3.W))
  val awvalid = Output(UInt(1.W))
  val awready = Input(UInt(1.W))

  // write data channel signals
  val wdata = Output(UInt(data_width.W))
  val wstrb = Output(UInt((data_width / 8).W))
  val wvalid = Output(UInt(1.W))
  val wready = Input(UInt(1.W))

  // write response channel signals
  val bresp = Input(UInt(2.W))
  val bvalid = Input(UInt(1.W))
  val bready = Output(UInt(1.W))

  // read address channel signals
  val araddr = Output(UInt(32.W))
  val arprot = Output(UInt(3.W))
  val arvalid = Output(UInt(1.W))
  val arready = Input(UInt(1.W))

  // read data channel signals
  val rdata = Input(UInt(data_width.W))
  val rresp = Input(UInt(2.W))
  val rvalid = Input(UInt(1.W))
  val rready = Output(UInt(1.W))

  override def cloneType = { new AXI4LiteIO(data_width).asInstanceOf[this.type] }
}

class AXI4IO(id_width: Int, data_width: Int) extends Bundle
{
  // write address channel signals
  val awid = Output(UInt(id_width.W))
  val awaddr = Output(UInt(32.W))
  val awlen = Output(UInt(8.W))
  val awsize = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))
  val awlock = Output(UInt(1.W))
  val awcache = Output(UInt(4.W))
  val awprot = Output(UInt(3.W))
  val awvalid = Output(UInt(1.W))
  val awready = Input(UInt(1.W))

  // write data channel signals
  val wid = Output(UInt(id_width.W))
  val wdata = Output(UInt(data_width.W))
  val wstrb = Output(UInt((data_width / 8).W))
  val wlast = Output(UInt(1.W))
  val wvalid = Output(UInt(1.W))
  val wready = Input(UInt(1.W))

  // write response channel signals
  val bid = Input(UInt(id_width.W))
  val bresp = Input(UInt(2.W))
  val bvalid = Input(UInt(1.W))
  val bready = Output(UInt(1.W))

  // read address channel signals
  val arid = Output(UInt(id_width.W))
  val araddr = Output(UInt(32.W))
  val arlen = Output(UInt(8.W))
  val arsize = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))
  val arlock = Output(UInt(1.W))
  val arcache = Output(UInt(4.W))
  val arprot = Output(UInt(3.W))
  val arvalid = Output(UInt(1.W))
  val arready = Input(UInt(1.W))

  // read data channel signals
  val rid = Input(UInt(id_width.W))
  val rdata = Input(UInt(data_width.W))
  val rresp = Input(UInt(2.W))
  val rlast = Input(UInt(1.W))
  val rvalid = Input(UInt(1.W))
  val rready = Output(UInt(1.W))

  override def cloneType = { new AXI4IO(id_width, data_width).asInstanceOf[this.type] }
}
