//**************************************************************************
// MIPS32-NPC
//--------------------------------------------------------------------------

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class WBU_IO extends Bundle() 
{
  val reg = new WBU_REG_IO()
  val alu = Flipped(DecoupledIO(new ALU_WBU_IO()))
}

class WBU extends Module
{
  val io = IO(new WBU_IO())

  // Register File
  val wen = MuxCase(N, Array(
    (io.alu.valid)  -> Y
  ))

  val waddr = MuxCase(0.asUInt(5.W), Array(
    (io.alu.valid)  -> io.alu.bits.rd
  ))

  val wdata = MuxCase(0.asUInt(conf.xprlen.W), Array(
    (io.alu.valid)  -> io.alu.bits.value
  ))

  io.reg.wen := wen
  io.reg.waddr := waddr
  io.reg.wdata := wdata

  /*
  printf("[WBU] wen= %c waddr= 0x%x wdata= 0x%x ",
    Mux(wen, Str("Y"), Str("N")),
    waddr,
    wdata
    )
    */
}
