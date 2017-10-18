// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTop_H_
#define _VTop_H_

#include "verilated.h"
#include "VTop__Dpi.h"

class VTop__Syms;
class VTop___024unit;

//----------

VL_MODULE(VTop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    VTop___024unit*    	__PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_success,0,0);
    VL_OUT8(io_dl_req_ready,0,0);
    VL_IN8(io_dl_req_valid,0,0);
    VL_IN8(io_dl_req_bits_op,1,0);
    VL_IN8(io_dl_resp_ready,0,0);
    VL_OUT8(io_dl_resp_valid,0,0);
    VL_OUT8(io_dl_resp_bits_resp,1,0);
    VL_IN8(io_freeze,0,0);
    VL_OUT8(io_instr_commit,0,0);
    VL_OUT8(io_core_reset,0,0);
    VL_IN(io_dl_req_bits_addr,31,0);
    VL_IN(io_dl_req_bits_data,31,0);
    VL_OUT(io_dl_resp_bits_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc,0,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1,2,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2,4,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3,1,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4,1,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ,2,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110,0,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__wbu__DOT__waddr,4,0);
    VL_SIG8(Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_22,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__dw_en,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT___T_157,4,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93,1,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_2,0,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_3,0,0);
    //char	__VpadToAlign45[1];
    VL_SIG16(Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_s,11,0);
    VL_SIG16(Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_b,11,0);
    //char	__VpadToAlign50[2];
    VL_SIG(Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg,28,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__ifu__DOT___GEN_0,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_j,19,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_i_sext,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__isu__DOT__op1,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__isu__DOT__op2,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__isu__DOT___T_213,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_30_data,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_35_data,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_43_data,31,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37,31,0);
    VL_SIG(Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data,31,0);
    VL_SIG(Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data,31,0);
    VL_SIG(Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20,31,0);
    VL_SIG64(Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76,32,0);
    VL_SIG64(Top__DOT__tile__DOT__memory__DOT___T_143,62,0);
    VL_SIG(Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile[32],31,0);
    VL_SIG8(Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[2097152],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign2097413[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign2097420[4];
    VTop__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VTop& operator= (const VTop&);	///< Copying not allowed
    VTop(const VTop&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VTop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VTop();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VTop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VTop__Syms* symsp, bool first);
  private:
    static QData	_change_request(VTop__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__11(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__13(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__15(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__2(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__7(VTop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__9(VTop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VTop__Syms* __restrict vlSymsp);
    static void	_eval_initial(VTop__Syms* __restrict vlSymsp);
    static void	_eval_settle(VTop__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(VTop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__10(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__12(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__14(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__16(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(VTop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(VTop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
