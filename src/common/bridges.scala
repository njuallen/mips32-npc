//**************************************************************************
// Bridges
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

// ============================== Bridges ==============================

class MemPort2SMemBridge(addr_width:Int, data_width: Int) extends Module
{
  val io = IO(new Bundle {
    val in = Flipped(new MemPortIo(addr_width, data_width))
    val out = new SMemIO(addr_width, data_width)
  })

  // request
  val smem_req = io.out.req.bits
  val mem_req = io.in.req.bits
  val fcn = mem_req.fcn
  val typ = mem_req.typ
  io.out.req.valid := io.in.req.valid
  io.in.req.ready := io.out.req.ready
  smem_req.addr := mem_req.addr
  smem_req.data := mem_req.data
  smem_req.op := MuxCase(STRB_X, Array(
    (typ === MT_B) -> STRB_B,
    (typ === MT_H) -> STRB_H,
    (typ === MT_W) -> STRB_W
  ))

  smem_req.wstrb := MuxCase(S_X, Array(
    (fcn === M_XRD) -> S_XRD,
    (fcn === M_XWR) -> S_XWR
  ))

  // response
  val smem_resp = io.out.resp.bits
  val mem_resp = io.in.resp.bits
  val resp_data = io.out.resp.bits.data
  io.in.resp.valid := io.out.resp.valid
  io.in.resp.bits.data := MuxCase(resp_data, Array(
    (typ === MT_B) -> Cat(Fill(24, resp_data(7)), resp_data(7,0)),
    (typ === MT_H) -> Cat(Fill(16, resp_data(15)), resp_data(15,0)),
    (typ === MT_BU) -> Cat(Fill(24, 0.U), resp_data(7,0)),
    (typ === MT_HU) -> Cat(Fill(16, 0.U), resp_data(15,0))
  ))
}

// translate directly from naive_axilite_bridge.v
class SMem2AXI4LiteBridge(addr_width:Int, data_width: Int) extends Module
{
  val io = IO(new Bundle {
    val in = Flipped(new SMemIO(addr_width, data_width))
    val out = new AXI4LiteIO(data_width)
  })

  val req_valid = io.in.req.valid
  val resp_valid = io.in.resp.valid
  val req = io.in.req.bits
  val resp = io.in.resp.bits
  val out = io.out
  val ren = req_valid && (req.op === M_XRD)
  val wen = req_valid && (req.op === M_XWR)

  // rdata, raddr
  val r_score_board = Reg(init = 0.asUInt(2.W))
  val r_shake = Wire(UInt(2.W))
  val r_status = Wire(UInt(2.W))

  r_shake := Cat(out.rvalid & out.rready, out.arvalid & out.arready)
  r_status := r_score_board | r_shake

  when (r_status === "b11".U) {
    r_score_board := 0.U
  } .otherwise { r_score_board := r_status }

  // wresponse, wdata, waddr
  val w_score_board = Reg(init = 0.asUInt(3.W))
  val w_shake = Wire(UInt(3.W))
  val w_status = Wire(UInt(3.W))

  w_shake := Cat(out.bvalid & out.bready,
    Cat(out.wvalid & out.wready, out.awvalid & out.awready))
  w_status := w_score_board | w_shake;

  when (w_status === "b111".U) {
    w_score_board := 0.U
  } .otherwise { w_score_board := w_status }

  out.araddr := req.addr
  out.arvalid := ren & (!r_score_board(0))
  out.awaddr := req.addr
  out.awvalid := wen & (~w_score_board(0))
  out.bready := wen & (~w_score_board(2))
  resp.data := out.rdata
  out.rready := ren & (~r_score_board(1))
  out.wdata := req.data
  out.wvalid := wen & (~w_score_board(1))
  out.wstrb := req.wstrb
  out.awprot := 0.asUInt(3.W)
  out.arprot := 0.asUInt(3.W)
  resp_valid := (ren && (r_status === "b11".U)) || (wen && (w_status === "b111".U))
}

class AXI4Lite2AXI4Bridge(axi4lite_data_width: Int, id_width: Int, axi4_data_width: Int) extends Module
{
  val io = IO(new Bundle {
    val in = Flipped(new AXI4LiteIO(axi4lite_data_width))
    val out = new AXI4IO(id_width, axi4_data_width)
  })

  val in = io.in
  val out = io.out

  // write address channel signals
  out.awid := 0.asUInt(id_width.W)
  out.awaddr := in.awaddr
  out.awlen := 0.asUInt(8.W)  // write once
  out.awsize := "b010".U       // write 4bytes each time
  out.awburst := "b01".U       // normal sequential memory
  out.awlock := 0.asUInt(1.W)
  out.awcache := 0.asUInt(4.W)
  out.awprot := in.awprot
  in.awready := out.awready
  out.awvalid := in.awvalid

  // write data channel signals
  out.wid := 0.asUInt(id_width.W)
  out.wdata := in.wdata
  out.wstrb := in.wstrb
  out.wlast := in.wvalid
  out.wvalid := in.wvalid
  in.wready := out.wready

  // write response channel signals
  in.bresp := out.bresp
  in.bvalid := out.bvalid
  out.bready := in.bready


  // read address channel signals
  out.arid := 0.asUInt(id_width.W)
  out.araddr := in.araddr
  out.arlen := 0.asUInt(8.W)  // read once
  out.arsize := "b010".U  // read 4bytes each time
  out.arburst := "b01".U // normal sequential memory
  out.arlock := 0.asUInt(1.W)
  out.arcache := 0.asUInt(4.W)
  out.arprot := in.arprot
  out.arvalid := in.arvalid
  in.arready := out.arready

  // read data channel signals
  in.rdata := out.rdata
  in.rresp := out.rresp
  in.rvalid := out.rvalid
  out.rready := in.rready
}
