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

class LSU_IO(implicit conf: SodorConfiguration) extends Bundle()
{
  val dmem = new MemPortIo(conf.xprlen, conf.xprlen)
  val datain = Flipped(DecoupledIO(new ISU_LSU_IO()))
  val res = DecoupledIO(new LSU_WBU_IO())
  val stall = new LSU_IFU_IO()
}

class LSU(implicit conf: SodorConfiguration) extends Module
{
  val io = IO(new LSU_IO())

  val datain = io.datain.bits
  val addr = datain.base + datain.offset
  val wdata = datain.wdata
  val rd = datain.rd
  val lsu_op = datain.fu_op

  val fcn = MuxCase(M_X, Array(
    (lsu_op === LSU_LW)  ->  M_XRD,
    (lsu_op === LSU_LB)  ->  M_XRD,
    (lsu_op === LSU_LBU) ->  M_XRD,
    (lsu_op === LSU_LH)  ->  M_XRD,
    (lsu_op === LSU_LHU) ->  M_XRD,
    (lsu_op === LSU_SW)  ->  M_XWR,
    (lsu_op === LSU_SB)  ->  M_XWR,
    (lsu_op === LSU_SH)  ->  M_XWR
  ))

  val typ = MuxCase(MT_X, Array(
    (lsu_op === LSU_LW)  ->   MT_W,
    (lsu_op === LSU_LB)  ->   MT_B,
    (lsu_op === LSU_LBU)  ->  MT_BU,
    (lsu_op === LSU_LH) ->    MT_H,
    (lsu_op === LSU_LHU)  ->  MT_HU,
    (lsu_op === LSU_SW) ->    MT_W,
    (lsu_op === LSU_SB)   ->  MT_B,
    (lsu_op === LSU_SH)  ->   MT_H
  ))

  // lsu to data memory outputs
  val dmem_req = io.dmem.req.bits
  io.dmem.req.valid := io.datain.valid
  // printf("valid= %d ", io.datain.valid)
  dmem_req.addr  := addr
  dmem_req.data := wdata
  dmem_req.fcn := fcn
  dmem_req.typ := typ

  // stall
  io.stall.dmem_stall := (io.datain.valid && !io.dmem.resp.valid)

  // res
  io.res.valid := (io.datain.valid && io.dmem.resp.valid)
  val res = io.res.bits
  res.value := io.dmem.resp.bits.data
  res.rd := rd
  res.wen := !(lsu_op === LSU_SW || lsu_op === LSU_SB || lsu_op === LSU_SH)

  /*
  printf("[LSU] valid= %c addr= 0x%x data= 0x%x fcn= %d typ= 0x%x resp_valid= %c\n",
    Mux(io.datain.valid, Str("Y"), Str("N")),
    addr,
    wdata,
    fcn,
    typ,
    Mux(io.dmem.resp.valid, Str("Y"), Str("N"))
    )
   */
}
