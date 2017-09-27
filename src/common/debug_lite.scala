package Common

import chisel3._
import chisel3.util._
import Common._
import Common.Util._
import Util._
import Constants._

// our own debug interface, much more simple than the original interface
// Debug Lite Message Constants
object DLMConsts {
  def DataSize = 32
  def AddrSize = 32
  def OpSize = 2
  def OP_NONE            = "b00".U
  def OP_READ            = "b01".U
  def OP_WRITE           = "b10".U

  def RespSize = 2
  def RESP_SUCCESS     = "b00".U
  def RESP_FAILURE     = "b01".U
  def RESP_HW_FAILURE  = "b10".U
}

object DLMRegAddrs {
  def REGS_START = 0
  def REGS_END = 31
  def PC = 32
}

// Debug Lite Message Interface Request
class DLMIReq extends Bundle {
  val op   = Output(UInt(DLMConsts.OpSize.W))
  val addr = Output(UInt(DLMConsts.AddrSize.W))
  val data = Output(UInt(DLMConsts.DataSize.W))
  override def cloneType = new DLMIReq().asInstanceOf[this.type]
}

class DLMIResp extends Bundle {
  val data = Output(UInt(DLMConsts.DataSize.W))
  val resp = Output(UInt(DLMConsts.RespSize.W))
}

class DLMIIO extends Bundle {
  val req = new DecoupledIO(new DLMIReq)
  val resp = Flipped(new DecoupledIO(new DLMIResp))
}

class DebugLiteRegIo extends Bundle
{
  // REG access
  val addr = Output(UInt(5.W))
  val rdata = Input(UInt(32.W))
}

class DebugLiteIo extends Bundle
{
  val dl = Flipped(new DLMIIO())
  val reg = new DebugLiteRegIo()
  // read pc
  val pc = Input(UInt(32.W))
}

// for now, we only support read regs and pc
class DebugLiteModule extends Module {
  val io = IO(new DebugLiteIo())
  val req = io.dl.req.bits
  val resp = io.dl.resp.bits
  io.dl.req.ready := true.B
  // we can read out register content in a cycle
  io.dl.resp.valid := io.dl.req.valid

  resp.resp := DLMConsts.RESP_SUCCESS

  when (req.op === DLMConsts.OP_READ) {
    when (req.addr <= DLMRegAddrs.REGS_END) {
      io.reg.addr := req.addr
      resp.data := io.reg.rdata
      } .elsewhen (req.addr === DLMRegAddrs.PC.U) {
        resp.data := io.pc
      }
  }
}
