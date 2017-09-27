package Sodor

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
  val io = IO(new Bundle{
    val success = Output(Bool())
    val dl = Flipped(new DLMIIO())
    // freeze register(general register and pc) update in the processor
    // so that we can easily check it with debug module
    val freeze = Input(Bool())
    val instr_commit = Output(Bool())
    val core_reset = Output(Bool())
  })

  implicit val sodor_conf = SodorConfiguration()
  val tile = Module(new SodorTile)
  tile.io.dl <> io.dl
  tile.io.freeze := io.freeze
  io.instr_commit := tile.io.instr_commit
  io.core_reset := tile.io.core_reset
}

object elaborate extends ChiselFlatSpec{
  def main(args: Array[String]): Unit = {
    chisel3.Driver.execute(args, () => new Top)
  }
}
