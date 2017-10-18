package Common
package constants
{

import chisel3._
import chisel3.util._
import scala.math._

trait MIPS32Constants
{
   // abstract out instruction decode magic numbers
   val RS_MSB = 25
   val RS_LSB = 21
   val RT_MSB = 20
   val RT_LSB = 16
   val RD_MSB  = 15
   val RD_LSB  = 11

   val CSR_ADDR_MSB = 31
   val CSR_ADDR_LSB = 20

   // location of the fifth bit in the shamt (for checking for illegal ops for SRAIW,etc.)
   val SHAMT_5_BIT = 25
   val LONGEST_IMM_SZ = 20
   val X0 = 0.U

   // The Bubble Instruction (Machine generated NOP)
   // Insert (XOR x0,x0,x0) which is different from software compiler
   // generated NOPs which are (ADDI x0, x0, 0).
   // Reasoning for this is to let visualizers and stat-trackers differentiate
   // between software NOPs and machine-generated Bubbles in the pipeline.
   val BUBBLE  = Bits(0x4033, 32)
}

trait PrivilegedConstants
{
   val MTVEC = 0x100
   val START_ADDR = "h10000000".U //MTVEC + 0x100

   val SZ_PRV = 2
   val PRV_U = 0
   val PRV_S = 1
   val PRV_H = 2
   val PRV_M = 3
}

trait AddressConstants
{
   // 32 bit address space (4 kB pages)
   val PADDR_BITS = 32
   val VADDR_BITS = 32
   val PGIDX_BITS = 12
   val PPN_BITS = PADDR_BITS-PGIDX_BITS
   val VPN_BITS = VADDR_BITS-PGIDX_BITS
   val ASID_BITS = 7
   val PERM_BITS = 6
}

}


