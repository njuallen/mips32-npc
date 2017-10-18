//**************************************************************************
// RISCV Processor Tile
//--------------------------------------------------------------------------
//

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._   
import Common.Util._   


class SodorTile extends Module
{
  val io = IO(new Bundle {
    val dl = Flipped(new DLMIIO())
    val freeze = Input(Bool())
    val instr_commit = Output(Bool())
    // whether the core has been reset either by debug module or by reset signal
    val core_reset = Output(Bool())
  })

  // notice that while the core is put into reset, the scratchpad needs to be
  // alive so that the HTIF can load in the program.
  val dl_debug = Module(new DebugLiteModule())
  val core   = Module(new Core())
  val memory = Module(new AsyncScratchPadMemory(num_core_ports = 2))

  val core_reset = reset.toBool
  core.io.dmem <> memory.io.core_ports(0)
  core.io.imem <> memory.io.core_ports(1)
  core.reset := core_reset
  // whether the core has been reseted by debug module
  // htif reset the core when it loads the program
  // we use this to check whether program loading has finished
  io.core_reset := core_reset

  dl_debug.io.dl <> io.dl
  dl_debug.io.reg <> core.io.reg
  dl_debug.io.pc := core.io.pc
  core.io.freeze := io.freeze
  io.instr_commit := core.io.instr_commit
}
