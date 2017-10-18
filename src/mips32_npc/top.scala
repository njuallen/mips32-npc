package NPC

import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}

import Constants._
import Common._
import Common.Util._
import ReferenceChipBackend._
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap


object ReferenceChipBackend {
  val initMap = new HashMap[Module, Bool]()
}

class Top extends Module 
{
  val io = IO(new Bundle {
    val debug = Flipped(new DebugIO())
  })

  val tile = Module(new NPCTile)
  io.debug <> tile.io.debug
}

object elaborate extends ChiselFlatSpec{
  def main(args: Array[String]): Unit = {
    chisel3.Driver.execute(args, () => new Top)
  }
}
