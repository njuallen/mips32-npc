//**************************************************************************
// RISCV NJU Out Of Order Processor
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 5

package NPC

import chisel3._
import chisel3.util._

import Constants._
import Common._
import Common.Constants._

class BRU_IO extends Bundle()
{
}

class BRU extends Module
{
  val io = IO(new BRU_IO())
}
