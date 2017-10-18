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


class NPCTile extends Module
{
  val io = IO(new Bundle {
    val debug = Flipped(new DebugIO())
  })

  val core   = Module(new Core())
  val memory = Module(new AsyncScratchPadMemory(num_core_ports = 2))

  core.io.dmem <> memory.io.core_ports(0)
  core.io.imem <> memory.io.core_ports(1)

  io.debug <> core.io.debug
}
