//**************************************************************************
// RISCV NJU Out Of Order Processor
//--------------------------------------------------------------------------
//
// Zhigang Liu
// 2017 Sep 5

package NPC

import chisel3._
import chisel3.util._

import Common._
import Common.Instructions._
import Constants._

class IDU_IO extends Bundle() 
{
  val instr = Flipped(DecoupledIO(new IFU_IDU_IO()))
  val decode = DecoupledIO(new IDU_ISU_IO())
}

class IDU extends Module
{
  val io = IO(new IDU_IO())
  val instr = io.instr.bits.instr
  val pc = io.instr.bits.pc
  val csignals = ListLookup(instr,
    List(N, FU_X, FU_OP_X, OP1_X, OP2_X), Array(
      /* instr | fu_type  |  fu_op  |  op1_sel  |  op2_sel */
     LW      -> List(Y, FU_LSU,  LSU_LW,     OP1_RS1,  OP2_IMI),
     LB      -> List(Y, FU_LSU,  LSU_LB,     OP1_RS1,  OP2_IMI),
     LBU     -> List(Y, FU_LSU,  LSU_LBU,    OP1_RS1,  OP2_IMI),
     LH      -> List(Y, FU_LSU,  LSU_LH,     OP1_RS1,  OP2_IMI),
     LHU     -> List(Y, FU_LSU,  LSU_LHU,    OP1_RS1,  OP2_IMI),
     SW      -> List(Y, FU_LSU,  LSU_SW,     OP1_RS1,  OP2_IMS),
     SB      -> List(Y, FU_LSU,  LSU_SB,     OP1_RS1,  OP2_IMS),
     SH      -> List(Y, FU_LSU,  LSU_SH,     OP1_RS1,  OP2_IMS),

     AUIPC   -> List(Y, FU_ALU,  ALU_ADD,    OP1_IMU,  OP2_PC),
     LUI     -> List(Y, FU_ALU,  ALU_COPY1,  OP1_IMU,  OP2_X),

     ADDI    -> List(Y, FU_ALU,  ALU_ADD,    OP1_RS1,  OP2_IMI),
     ANDI    -> List(Y, FU_ALU,  ALU_AND,    OP1_RS1,  OP2_IMI),
     ORI     -> List(Y, FU_ALU,  ALU_OR,     OP1_RS1,  OP2_IMI),
     XORI    -> List(Y, FU_ALU,  ALU_XOR,    OP1_RS1,  OP2_IMI),
     SLTI    -> List(Y, FU_ALU,  ALU_SLT,    OP1_RS1,  OP2_IMI),
     SLTIU   -> List(Y, FU_ALU,  ALU_SLTU,   OP1_RS1,  OP2_IMI),
     SLLI    -> List(Y, FU_ALU,  ALU_SLL,    OP1_RS1,  OP2_IMI),
     SRAI    -> List(Y, FU_ALU,  ALU_SRA,    OP1_RS1,  OP2_IMI),
     SRLI    -> List(Y, FU_ALU,  ALU_SRL,    OP1_RS1,  OP2_IMI),

     SLL     -> List(Y, FU_ALU,  ALU_SLL,    OP1_RS1,  OP2_RS2),
     ADD     -> List(Y, FU_ALU,  ALU_ADD,    OP1_RS1,  OP2_RS2),
     SUB     -> List(Y, FU_ALU,  ALU_SUB,    OP1_RS1,  OP2_RS2),
     SLT     -> List(Y, FU_ALU,  ALU_SLT,    OP1_RS1,  OP2_RS2),
     SLTU    -> List(Y, FU_ALU,  ALU_SLTU,   OP1_RS1,  OP2_RS2),
     AND     -> List(Y, FU_ALU,  ALU_AND,    OP1_RS1,  OP2_RS2),
     OR      -> List(Y, FU_ALU,  ALU_OR,     OP1_RS1,  OP2_RS2),
     XOR     -> List(Y, FU_ALU,  ALU_XOR,    OP1_RS1,  OP2_RS2),
     SRA     -> List(Y, FU_ALU,  ALU_SRA,    OP1_RS1,  OP2_RS2),
     SRL     -> List(Y, FU_ALU,  ALU_SRL,    OP1_RS1,  OP2_RS2),

     JAL     -> List(Y, FU_BRU,  BR_J,       OP1_X,    OP2_X),
     JALR    -> List(Y, FU_BRU,  BR_JR,      OP1_RS1,  OP2_IMI),
     BEQ     -> List(Y, FU_BRU,  BR_EQ,      OP1_X,    OP2_X),
     BNE     -> List(Y, FU_BRU,  BR_NE,      OP1_X,    OP2_X),
     BGE     -> List(Y, FU_BRU,  BR_GE,      OP1_X,    OP2_X),
     BGEU    -> List(Y, FU_BRU,  BR_GEU,     OP1_X,    OP2_X),
     BLT     -> List(Y, FU_BRU,  BR_LT,      OP1_X,    OP2_X),
     BLTU    -> List(Y, FU_BRU,  BR_LTU,     OP1_X,    OP2_X),

     CSRRWI  -> List(Y, FU_CSR,  CSR_CSRRWI, OP1_IMZ,  OP2_X),
     CSRRSI  -> List(Y, FU_CSR,  CSR_CSRRSI, OP1_IMZ,  OP2_X),
     CSRRCI  -> List(Y, FU_CSR,  CSR_CSRRCI, OP1_IMZ,  OP2_X),
     CSRRW   -> List(Y, FU_CSR,  CSR_CSRRW,  OP1_RS1,  OP2_X),
     CSRRS   -> List(Y, FU_CSR,  CSR_CSRRS,  OP1_RS1,  OP2_X),
     CSRRC   -> List(Y, FU_CSR,  CSR_CSRRC,  OP1_RS1,  OP2_X),

     ECALL   -> List(Y, FU_CSR,  CSR_ECALL,  OP1_X,    OP2_X),
     MRET    -> List(Y, FU_CSR,  CSR_MRET,   OP1_X,    OP2_X),
     DRET    -> List(Y, FU_CSR,  CSR_DRET,   OP1_X,    OP2_X),
     EBREAK  -> List(Y, FU_CSR,  CSR_EBREAK, OP1_X,    OP2_X),
     WFI     -> List(Y, FU_X,    FU_OP_X,    OP1_X,    OP2_X), // implemented as a NOP

     FENCE_I -> List(Y, FU_X,    FU_OP_X,    OP1_X,    OP2_X),
     FENCE   -> List(Y, FU_X,    FU_OP_X,    OP1_X,    OP2_X)
     // we are already sequentially consistent, so no need to honor the fence instruction
     ))

  val (val_inst: Bool) :: fu_type :: fu_op :: op1_sel :: op2_sel :: Nil = csignals

  // here, we do not decode instr, we leave that to ISU
  val decode = io.decode.bits
  decode.pc := pc
  decode.instr := instr
  decode.rs1 := instr(RS1_MSB, RS1_LSB)
  decode.rs2 := instr(RS2_MSB, RS2_LSB)
  decode.rd := instr(RD_MSB, RD_LSB)
  decode.op1_sel := op1_sel
  decode.op2_sel := op2_sel
  decode.fu_type := fu_type
  decode.fu_op := fu_op
  decode.exception := !val_inst
}
