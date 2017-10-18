//**************************************************************************
// MIPS32-NPC Processor Constants
//--------------------------------------------------------------------------

package NPC
package constants
{

  import chisel3._
  import chisel3.util._

  trait ScalarOpConstants
  {
    //************************************
    // Control Signals

    val Y      = true.B
    val N      = false.B

    val FU_TYPE_SZ = 3
    val FU_OP_SZ = 5
    val FU_OP_X = 0.asUInt(FU_OP_SZ.W)
    // Functional Unit Select Signal
    val FU_X   = 0.asUInt(FU_TYPE_SZ.W)
    val FU_ALU = 1.asUInt(FU_TYPE_SZ.W)
    val FU_BRU = 2.asUInt(FU_TYPE_SZ.W)
    val FU_LSU = 3.asUInt(FU_TYPE_SZ.W)
    val FU_CSR = 4.asUInt(FU_TYPE_SZ.W)

    // RS Operand Select Signal
    val OP1_SEL_SZ = 2
    val OP1_X   = 0.asUInt(2.W)
    val OP1_RS = 0.asUInt(2.W) // Register Source #1
    val OP1_IMU = 1.asUInt(2.W) // immediate, U-type
    val OP1_IMZ = 2.asUInt(2.W) // Zero-extended rs1 field of inst, for CSRI instructions

    // RT Operand Select Signal
    val OP2_SEL_SZ = 2
    val OP2_X   = 0.asUInt(2.W)
    val OP2_RT = 0.asUInt(2.W) // Register Source #2
    val OP2_IMI = 1.asUInt(2.W) // immediate, I-type
    val OP2_IMS = 2.asUInt(2.W) // immediate, S-type
    val OP2_PC  = 3.asUInt(2.W) // PC

    // Branch Operation Signal
    val BR_NE  = 0.asUInt(FU_OP_SZ.W)  // Branch on NotEqual
    val BR_EQ  = 1.asUInt(FU_OP_SZ.W)  // Branch on Equal
    val BR_GE  = 2.asUInt(FU_OP_SZ.W)  // Branch on Greater/Equal
    val BR_GEU = 3.asUInt(FU_OP_SZ.W)  // Branch on Greater/Equal Unsigned
    val BR_LT  = 4.asUInt(FU_OP_SZ.W)  // Branch on Less Than
    val BR_LTU = 5.asUInt(FU_OP_SZ.W)  // Branch on Less Than Unsigned
    val BR_J   = 6.asUInt(FU_OP_SZ.W)  // Jump
    val BR_JR  = 7.asUInt(FU_OP_SZ.W)  // Jump Register

    // ALU Operation Signal
    val ALU_ADD = 0.asUInt(FU_OP_SZ.W)
    val ALU_SUB = 1.asUInt(FU_OP_SZ.W)
    val ALU_SLL = 2.asUInt(FU_OP_SZ.W)
    val ALU_SRL = 3.asUInt(FU_OP_SZ.W)
    val ALU_SRA = 4.asUInt(FU_OP_SZ.W)
    val ALU_AND = 5.asUInt(FU_OP_SZ.W)
    val ALU_OR  = 6.asUInt(FU_OP_SZ.W)
    val ALU_XOR = 7.asUInt(FU_OP_SZ.W)
    val ALU_SLT = 8.asUInt(FU_OP_SZ.W)
    val ALU_SLTU = 9.asUInt(FU_OP_SZ.W)
    val ALU_COPY1 = 10.asUInt(FU_OP_SZ.W)

    // LSU Operation Signal
    val LSU_LW  = 0.asUInt(FU_OP_SZ.W)
    val LSU_LB  = 1.asUInt(FU_OP_SZ.W)
    val LSU_LBU = 2.asUInt(FU_OP_SZ.W)
    val LSU_LH  = 3.asUInt(FU_OP_SZ.W)
    val LSU_LHU = 4.asUInt(FU_OP_SZ.W)
    val LSU_SW  = 5.asUInt(FU_OP_SZ.W)
    val LSU_SB  = 6.asUInt(FU_OP_SZ.W)
    val LSU_SH  = 7.asUInt(FU_OP_SZ.W)
  }
}
