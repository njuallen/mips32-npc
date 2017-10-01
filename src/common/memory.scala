//**************************************************************************
// MemPortIO
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 14

package Common

import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import chisel3.experimental._

import Constants._
import Common._
import Common.Util._

trait MemoryOpConstants 
{
  // for MemPortIo
  val MT_X  = 0.asUInt(3.W)
  val MT_B  = 1.asUInt(3.W)
  val MT_H  = 2.asUInt(3.W)
  val MT_W  = 3.asUInt(3.W)
  val MT_D  = 4.asUInt(3.W)
  val MT_BU = 5.asUInt(3.W)
  val MT_HU = 6.asUInt(3.W)
  val MT_WU = 7.asUInt(3.W)

  val M_X   = "b0".asUInt(1.W)
  val M_XRD = "b0".asUInt(1.W) // int load
  val M_XWR = "b1".asUInt(1.W) // int store

  val DPORT = 0
  val IPORT = 1

  // for SMem
  val S_X   = "b0".asUInt(1.W)
  val S_XRD = "b0".asUInt(1.W)
  val S_XWR = "b1".asUInt(1.W)

  // memory write strobe signals
  /* There is one write strobe for each eight bits of the write data bus,
   * so WSTRB[n] corresponds to WDATA[(8 * n) + 7: (8 * n)].
   */
  val STRB_X  = 0.asUInt(2.W)
  val STRB_B  = 0.asUInt(2.W)
  val STRB_H  = 1.asUInt(2.W)
  val STRB_W  = 3.asUInt(2.W)
}

// ============================== MemPortIo ==============================
// the old memory interface
// for backward compatibility

// from the pov of the datapath
class MemPortIo(addr_width:Int, data_width: Int) extends Bundle 
{
  val req    = new DecoupledIO(new MemReq(addr_width, data_width))
  val resp   = Flipped(new ValidIO(new MemResp(data_width)))
  override def cloneType = { new MemPortIo(addr_width, data_width).asInstanceOf[this.type] }
}

class MemReq(addr_width:Int, data_width: Int) extends Bundle
{
  val addr = Output(UInt(addr_width.W))
  val data = Output(UInt(data_width.W))
  val fcn  = Output(UInt(M_X.getWidth.W))  // memory function code
  val typ  = Output(UInt(MT_X.getWidth.W)) // memory type
  override def cloneType = { new MemReq(addr_width, data_width).asInstanceOf[this.type] }
}

class MemResp(data_width: Int) extends Bundle
{
  val data = Output(UInt(data_width.W))
  override def cloneType = { new MemResp(data_width).asInstanceOf[this.type] }
}

// ============================== Simple Memory Interface ==============================
// the new memory interface(currently, I haven't thought out a better name)

class SMemIO(addr_width:Int, data_width: Int) extends Bundle 
{
  val req    = new DecoupledIO(new SMemReq(addr_width, data_width))
  val resp   = Flipped(new ValidIO(new SMemResp(data_width)))
  override def cloneType = { new SMemIO(addr_width, data_width).asInstanceOf[this.type] }
}

class SMemReq(addr_width:Int, data_width: Int) extends Bundle
{
  val addr = Output(UInt(addr_width.W))
  val data = Output(UInt(data_width.W))
  val op  = Output(UInt(S_X.getWidth.W))  // memory operation code
  val wstrb = Output(UInt(STRB_X.getWidth.W))  // write strobe
  override def cloneType = { new SMemReq(addr_width, data_width).asInstanceOf[this.type] }
}

class SMemResp(data_width: Int) extends Bundle
{
  val data = Output(UInt(data_width.W))
  override def cloneType = { new SMemResp(data_width).asInstanceOf[this.type] }
}

// a Naive Memport Crossbar
class SMemCrossbar(addr_width:Int, data_width: Int) extends Module
{
  val io = IO(new Bundle {
    val in = Flipped(new SMemIO(addr_width, data_width))
    val out_1 = new SMemIO(addr_width, data_width) // dcache
    val out_2 = new SMemIO(addr_width, data_width) // device mapped
    val out_3 = new SMemIO(addr_width, data_width) // counter
  })

  // memory mapping
  val MemoryStart = "h10000000".asUInt(addr_width.W) // 128MB memory
  val MemoryEnd = "h18000000".asUInt(addr_width.W)
  val DeviceStart = MemoryEnd // 1MB device mapped memory
  val DeviceEnd = "h18100000".asUInt(addr_width.W)
  val CounterStart = DeviceEnd // 4KB counter
  val CounterEnd = "h18101000".asUInt(addr_width.W)

  val addr = io.in.req.bits.addr
  val req_valid = io.in.req.valid

  when (!req_valid) {
    io.in.req.ready := io.out_1.req.ready && io.out_2.req.ready && io.out_3.req.ready 
  }

  val to_1 = req_valid && addr >= MemoryStart && addr < MemoryEnd
  val to_2 = req_valid && addr >= DeviceStart && addr < DeviceEnd
  val to_3 = req_valid && addr >= CounterStart && addr < CounterEnd

  val in_req = io.in.req.bits

  io.out_1.req.valid := to_1
  io.out_2.req.valid := to_2
  io.out_3.req.valid := to_3

  when (to_1) {
    val out_1_req = io.out_1.req.bits
    io.in.req.ready := io.out_1.req.ready
    out_1_req.addr := in_req.addr - MemoryStart
    out_1_req.data := in_req.data
    out_1_req.op := in_req.op
    out_1_req.wstrb := in_req.wstrb
    io.out_1.resp <> io.in.resp
  }
  when (to_2) {
    val out_2_req = io.out_2.req.bits
    io.in.req.ready := io.out_2.req.ready
    out_2_req.addr := in_req.addr - DeviceStart
    out_2_req.data := in_req.data
    out_2_req.op := in_req.op
    out_2_req.wstrb := in_req.wstrb
    io.out_2.resp <> io.in.resp
  }
  when (to_3) {
    val out_3_req = io.out_3.req.bits
    io.in.req.ready := io.out_3.req.ready
    out_3_req.addr := in_req.addr - CounterStart
    out_3_req.data := in_req.data
    out_3_req.op := in_req.op
    out_3_req.wstrb := in_req.wstrb
    io.out_3.resp <> io.in.resp
  }
}

// ============================== Memory ==============================
class Rport(val addrWidth : Int,val dataWidth : Int) extends Bundle{
  val addr = Input(UInt(addrWidth.W))
  val data = Output(UInt(dataWidth.W))
  override def cloneType = { new Rport(addrWidth,dataWidth).asInstanceOf[this.type] }
}

class Wport(val addrWidth : Int,val dataWidth : Int) extends Bundle{
  val maskWidth = dataWidth/8
  val addr = Input(UInt(addrWidth.W))
  val data = Input(UInt(dataWidth.W))
  val mask = Input(UInt(maskWidth.W))
  val en = Input(Bool())
  override def cloneType = { new Wport(addrWidth,dataWidth).asInstanceOf[this.type] }
}

class d2h2i1(val addrWidth : Int) extends Bundle{
  val dataInstr = Vec(2,new  Rport(addrWidth,32))
  val dw = new  Wport(addrWidth,32)
  val clk = Input(Clock()) 
  val reset = Input(Bool())
}

class AsyncReadMem(val addrWidth : Int) extends BlackBox{
  val io = IO(new d2h2i1(addrWidth))
}

class SyncMem(val addrWidth : Int) extends BlackBox{
  val io = IO(new d2h2i1(addrWidth))
}

// memory with AXI interface
class Device extends BlackBox {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val reset = Input(Bool())
    val in = Flipped(new SMemIO(addr_width = 32, data_width = 32))
  })
}

class AsyncScratchPadMemory(num_core_ports: Int)(implicit conf: SodorConfiguration) extends Module {
  val io = IO(new Bundle {
    val core_ports = Vec(num_core_ports,
      Flipped(new MemPortIo(conf.xprlen, conf.xprlen)) )
  })

  // bridges
  // convert MemPortIo to SMemIO
  val smem_bridges = Seq.fill(num_core_ports)(
    Module(new MemPort2SMemBridge(conf.xprlen, conf.xprlen)))

  // crossbars
  val crossbars = Seq.fill(num_core_ports)(
    Module(new SMemCrossbar(conf.xprlen, conf.xprlen)))

  val async_data = Module(new AsyncReadMem(log2Ceil(1 << 21)))
  async_data.io.clk := clock
  async_data.io.reset := reset

  for (i <- 0 until num_core_ports) {
    io.core_ports(i) <> smem_bridges(i).io.in
    smem_bridges(i).io.out <> crossbars(i).io.in
    async_data.io.dataInstr(i).addr := crossbars(i).io.out_1.req.bits.addr
    crossbars(i).io.out_1.resp.valid := crossbars(i).io.in.req.valid
    crossbars(i).io.out_1.resp.bits.data := async_data.io.dataInstr(i).data
  }

  /*
  printf("addr= 0x%x data= 0x%x ", async_data.io.dataInstr(DPORT).addr,
    async_data.io.dataInstr(DPORT).data)
  */

  val dmem_req = crossbars(DPORT).io.out_1.req.bits

  async_data.io.dw.en := (dmem_req.op === S_XWR)

  when (crossbars(DPORT).io.out_1.req.valid && (dmem_req.op === S_XWR))
  {
    async_data.io.dw.data := dmem_req.data
    async_data.io.dw.addr := Cat(dmem_req.addr(31,2), 0.asUInt(2.W))
    async_data.io.dw.mask := Mux(dmem_req.wstrb === MT_B, 1.U << dmem_req.addr(1,0),
      Mux(dmem_req.wstrb === MT_H, 3.U << dmem_req.addr(1,0), 15.U))
  }

  // DPORT
  // only dport crossbar needs to be connected to device and perf counters
  val dev = Module(new Device())
  dev.io.clk := clock
  dev.io.reset := reset
  dev.io.in <> crossbars(DPORT).io.out_2
}
