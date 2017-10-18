// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop.h"              // For This
#include "VTop__Syms.h"

#include "verilated_dpi.h"

//--------------------


void VTop::eval() {
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VTop::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VTop::_eval_initial_loop(VTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VTop::_combo__TOP__2(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__2\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_dl_resp_valid = vlTOPp->io_dl_req_valid;
    vlTOPp->io_core_reset = vlTOPp->reset;
}

VL_INLINE_OPT void VTop::_sequent__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_sequent__TOP__4\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0,4,0);
    VL_SIG8(__Vdlyvset__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0,0,0);
    VL_SIG8(__Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0,7,0);
    VL_SIG8(__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1,7,0);
    VL_SIG8(__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1,0,0);
    VL_SIG8(__Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2,7,0);
    VL_SIG8(__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2,0,0);
    VL_SIG8(__Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3,7,0);
    VL_SIG8(__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3,0,0);
    //char	__VpadToAlign34[2];
    VL_SIG(__Vdlyvval__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0,31,0);
    VL_SIG(__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0,20,0);
    VL_SIG(__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1,20,0);
    VL_SIG(__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2,20,0);
    VL_SIG(__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3,20,0);
    // Body
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/Device.v:37
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	// Function: device_tick at /home/liuzhigang/npc/mips32-npc/emulator/common/Device.v:41
	vlSymsp->TOP____024unit.__Vdpiimwrap_device_tick_TOP____024unit(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2, 
									((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
									 - (IData)(0x18000000U)), vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37, 
									((0U 
									  != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
									 & ((1U 
									     != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
									    & ((2U 
										!= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
									       & ((3U 
										!= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
										& ((4U 
										!= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
										& ((5U 
										== (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
										| ((6U 
										== (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
										| (7U 
										== (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))))))))), (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93));
    }
    __Vdlyvset__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0 = 0U;
    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0 = 0U;
    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1 = 0U;
    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2 = 0U;
    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3 = 0U;
    // ALWAYS at generated-src/Top.v:1118
    if (vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_22) {
	__Vdlyvval__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0 
	    = ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))
	        ? ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
		       + vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
		    : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		        ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
			   - vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
		        : ((5U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
			    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
			       & vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
			    : ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
			        ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
				   | vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
			        : ((7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
				    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
				       ^ vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
				    : ((8U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
				        ? VL_LTS_III(32,32,32, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
				        : ((9U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
					    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
					       < vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
					    : ((2U 
						== (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
					        ? (IData)(
							  (VL_ULL(0x7fffffffffffffff) 
							   & ((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1)) 
							      << 
							      (0x1fU 
							       & vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2))))
					        : (
						   (4U 
						    == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						    ? 
						   VL_SHIFTRS_III(32,32,5, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1, 
								  (0x1fU 
								   & vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2))
						    : 
						   ((3U 
						     == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						     ? 
						    (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
						     >> 
						     (0x1fU 
						      & vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2))
						     : 
						    ((0xaU 
						      == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						      ? vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1
						      : 0U)))))))))))
	        : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))
		    ? ((IData)(4U) + (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg))))
		    : ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110)
		        ? ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
			    ? ((((0x80U & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20)
				  ? 0xffffffU : 0U) 
				<< 8U) | (0xffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20))
			    : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
			        ? ((((0x8000U & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20)
				      ? 0xffffU : 0U) 
				    << 0x10U) | (0xffffU 
						 & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20))
			        : ((5U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
				    ? (0xffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20)
				    : ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
				        ? (0xffffU 
					   & vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20)
				        : vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20))))
		        : 0U)));
	__Vdlyvset__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0 = 1U;
	__Vdlyvdim0__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0 
	    = vlTOPp->Top__DOT__tile__DOT__core___DOT__wbu__DOT__waddr;
    }
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:31
    if (vlTOPp->Top__DOT__tile__DOT__memory__DOT__dw_en) {
	if ((1U & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_157))) {
	    __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0 
		= (0xffU & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_143));
	    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0 
		= (0x1ffffcU & ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
				- (IData)(0x10000000U)));
	}
    }
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:31
    if (vlTOPp->Top__DOT__tile__DOT__memory__DOT__dw_en) {
	if ((2U & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_157))) {
	    __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1 
		= (0xffU & (IData)((vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_143 
				    >> 8U)));
	    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1 = 1U;
	    __Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1 
		= (0x1fffffU & ((IData)(1U) + (0x1ffffcU 
					       & ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
						  - (IData)(0x10000000U)))));
	}
    }
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:31
    if (vlTOPp->Top__DOT__tile__DOT__memory__DOT__dw_en) {
	if ((4U & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_157))) {
	    __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2 
		= (0xffU & (IData)((vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_143 
				    >> 0x10U)));
	    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2 = 1U;
	    __Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2 
		= (0x1fffffU & ((IData)(2U) + (0x1ffffcU 
					       & ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
						  - (IData)(0x10000000U)))));
	}
    }
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:31
    if (vlTOPp->Top__DOT__tile__DOT__memory__DOT__dw_en) {
	if ((8U & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_157))) {
	    __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3 
		= (0xffU & (IData)((vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_143 
				    >> 0x18U)));
	    __Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3 = 1U;
	    __Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3 
		= (0x1fffffU & ((IData)(3U) + (0x1ffffcU 
					       & ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
						  - (IData)(0x10000000U)))));
	}
    }
    // ALWAYSPOST at generated-src/Top.v:1120
    if (__Vdlyvset__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0) {
	vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile[__Vdlyvdim0__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0] 
	    = __Vdlyvval__Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile__v0;
    }
    // ALWAYSPOST at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:34
    if (__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0) {
	vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0] 
	    = __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v0;
    }
    if (__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1) {
	vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1] 
	    = __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v1;
    }
    if (__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2) {
	vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2] 
	    = __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v2;
    }
    if (__Vdlyvset__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3) {
	vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[__Vdlyvdim0__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3] 
	    = __Vdlyvval__Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem__v3;
    }
    // ALWAYS at generated-src/Top.v:90
    vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg 
	= (0x1fffffffU & ((IData)(vlTOPp->reset) ? 0x10000000U
			   : vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___GEN_0));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_2 
	= ((0x18000000U <= vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg) 
	   & (0x18100000U > vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_3 
	= ((0x18100000U <= vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg) 
	   & (0x18101000U > vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:41
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data 
	= ((0xffffff00U & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data) 
	   | vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	   [(0x1fffffU & (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg))))]);
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:41
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data 
	= ((0xffff00ffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(1U) + (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg)))))] 
	      << 8U));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:41
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data 
	= ((0xff00ffffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(2U) + (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg)))))] 
	      << 0x10U));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:41
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data 
	= ((0xffffffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(3U) + (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg)))))] 
	      << 0x18U));
}

VL_INLINE_OPT void VTop::_combo__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__5\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_43_data 
	= vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile
	[(0x1fU & vlTOPp->io_dl_req_bits_addr)];
}

VL_INLINE_OPT void VTop::_combo__TOP__7(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__7\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_dl_resp_bits_data = ((0x1fU >= vlTOPp->io_dl_req_bits_addr)
				     ? vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_43_data
				     : vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg);
    vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
	= ((1U & (((~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_3)) 
		   & (~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_2))) 
		  & (~ (IData)(vlTOPp->io_freeze))))
	    ? ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_3)
	        ? 0U : ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_2)
			 ? 0U : vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data))
	    : 0x4033U);
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_b 
	= (((0x800U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
		       >> 0x14U)) | (0x400U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
					       << 3U))) 
	   | ((0x3f0U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
			 >> 0x15U)) | (0xfU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
					       >> 8U))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_j 
	= (((0x80000U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
			 >> 0xcU)) | (0x7f800U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
						  >> 1U))) 
	   | ((0x400U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
			 >> 0xaU)) | (0x3ffU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
						>> 0x15U))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2 
	= ((0x2003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
	    ? 0U : ((3U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
		     ? 1U : ((0x4003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
			      ? 2U : ((0x1003U == (0x707fU 
						   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
				       ? 3U : ((0x5003U 
						== 
						(0x707fU 
						 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
					        ? 4U
					        : (
						   (0x2023U 
						    == 
						    (0x707fU 
						     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						    ? 5U
						    : 
						   ((0x23U 
						     == 
						     (0x707fU 
						      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						     ? 6U
						     : 
						    ((0x1023U 
						      == 
						      (0x707fU 
						       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						      ? 7U
						      : 
						     ((0x17U 
						       == 
						       (0x7fU 
							& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						       ? 0U
						       : 
						      ((0x37U 
							== 
							(0x7fU 
							 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						        ? 0xaU
						        : 
						       ((0x13U 
							 == 
							 (0x707fU 
							  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							 ? 0U
							 : 
							((0x7013U 
							  == 
							  (0x707fU 
							   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							  ? 5U
							  : 
							 ((0x6013U 
							   == 
							   (0x707fU 
							    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							   ? 6U
							   : 
							  ((0x4013U 
							    == 
							    (0x707fU 
							     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							    ? 7U
							    : 
							   ((0x2013U 
							     == 
							     (0x707fU 
							      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							     ? 8U
							     : 
							    ((0x3013U 
							      == 
							      (0x707fU 
							       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							      ? 9U
							      : 
							     ((0x1013U 
							       == 
							       (0xfc00707fU 
								& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							       ? 2U
							       : 
							      ((0x40005013U 
								== 
								(0xfc00707fU 
								 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							        ? 4U
							        : 
							       ((0x5013U 
								 == 
								 (0xfc00707fU 
								  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								 ? 3U
								 : 
								((0x1033U 
								  == 
								  (0xfe00707fU 
								   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								  ? 2U
								  : 
								 ((0x33U 
								   == 
								   (0xfe00707fU 
								    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								   ? 0U
								   : 
								  ((0x40000033U 
								    == 
								    (0xfe00707fU 
								     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								    ? 1U
								    : 
								   ((0x2033U 
								     == 
								     (0xfe00707fU 
								      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								     ? 8U
								     : 
								    ((0x3033U 
								      == 
								      (0xfe00707fU 
								       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								      ? 9U
								      : 
								     ((0x7033U 
								       == 
								       (0xfe00707fU 
									& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								       ? 5U
								       : 
								      ((0x6033U 
									== 
									(0xfe00707fU 
									 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								        ? 6U
								        : 
								       ((0x4033U 
									 == 
									 (0xfe00707fU 
									  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									 ? 7U
									 : 
									((0x40005033U 
									  == 
									  (0xfe00707fU 
									   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									  ? 4U
									  : 
									 ((0x5033U 
									   == 
									   (0xfe00707fU 
									    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									   ? 3U
									   : 
									  ((0x6fU 
									    == 
									    (0x7fU 
									     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									    ? 6U
									    : 
									   ((0x67U 
									     == 
									     (0x707fU 
									      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									     ? 7U
									     : 
									    ((0x63U 
									      == 
									      (0x707fU 
									       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									      ? 1U
									      : 
									     ((0x1063U 
									       == 
									       (0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									       ? 0U
									       : 
									      ((0x5063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									        ? 2U
									        : 
									       ((0x7063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 3U
										 : 
										((0x4063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x6063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 5U
										 : 
										((0x5073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 0U
										 : 
										((0x6073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 1U
										 : 
										((0x7073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x1073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 3U
										 : 
										((0x2073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x3073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 5U
										 : 
										((0x73U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 6U
										 : 
										((0x30200073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 7U
										 : 
										((0x7b200073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 8U
										 : 
										((0x100073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 9U
										 : 0U)))))))))))))))))))))))))))))))))))))))))))))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1 
	= ((0x2003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
	    ? 3U : ((3U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
		     ? 3U : ((0x4003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
			      ? 3U : ((0x1003U == (0x707fU 
						   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
				       ? 3U : ((0x5003U 
						== 
						(0x707fU 
						 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
					        ? 3U
					        : (
						   (0x2023U 
						    == 
						    (0x707fU 
						     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						    ? 3U
						    : 
						   ((0x23U 
						     == 
						     (0x707fU 
						      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						     ? 3U
						     : 
						    ((0x1023U 
						      == 
						      (0x707fU 
						       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						      ? 3U
						      : 
						     ((0x17U 
						       == 
						       (0x7fU 
							& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						       ? 1U
						       : 
						      ((0x37U 
							== 
							(0x7fU 
							 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						        ? 1U
						        : 
						       ((0x13U 
							 == 
							 (0x707fU 
							  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							 ? 1U
							 : 
							((0x7013U 
							  == 
							  (0x707fU 
							   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							  ? 1U
							  : 
							 ((0x6013U 
							   == 
							   (0x707fU 
							    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							   ? 1U
							   : 
							  ((0x4013U 
							    == 
							    (0x707fU 
							     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							    ? 1U
							    : 
							   ((0x2013U 
							     == 
							     (0x707fU 
							      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							     ? 1U
							     : 
							    ((0x3013U 
							      == 
							      (0x707fU 
							       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							      ? 1U
							      : 
							     ((0x1013U 
							       == 
							       (0xfc00707fU 
								& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							       ? 1U
							       : 
							      ((0x40005013U 
								== 
								(0xfc00707fU 
								 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							        ? 1U
							        : 
							       ((0x5013U 
								 == 
								 (0xfc00707fU 
								  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								 ? 1U
								 : 
								((0x1033U 
								  == 
								  (0xfe00707fU 
								   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								  ? 1U
								  : 
								 ((0x33U 
								   == 
								   (0xfe00707fU 
								    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								   ? 1U
								   : 
								  ((0x40000033U 
								    == 
								    (0xfe00707fU 
								     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								    ? 1U
								    : 
								   ((0x2033U 
								     == 
								     (0xfe00707fU 
								      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								     ? 1U
								     : 
								    ((0x3033U 
								      == 
								      (0xfe00707fU 
								       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								      ? 1U
								      : 
								     ((0x7033U 
								       == 
								       (0xfe00707fU 
									& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								       ? 1U
								       : 
								      ((0x6033U 
									== 
									(0xfe00707fU 
									 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								        ? 1U
								        : 
								       ((0x4033U 
									 == 
									 (0xfe00707fU 
									  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									 ? 1U
									 : 
									((0x40005033U 
									  == 
									  (0xfe00707fU 
									   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									  ? 1U
									  : 
									 ((0x5033U 
									   == 
									   (0xfe00707fU 
									    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									   ? 1U
									   : 
									  ((0x6fU 
									    == 
									    (0x7fU 
									     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									    ? 2U
									    : 
									   ((0x67U 
									     == 
									     (0x707fU 
									      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									     ? 2U
									     : 
									    ((0x63U 
									      == 
									      (0x707fU 
									       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									      ? 2U
									      : 
									     ((0x1063U 
									       == 
									       (0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									       ? 2U
									       : 
									      ((0x5063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									        ? 2U
									        : 
									       ((0x7063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x4063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x6063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x5073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x6073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x7073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x1073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x2073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x3073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 4U
										 : 
										((0x73U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 4U
										 : 
										((0x30200073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 4U
										 : 
										((0x7b200073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 4U
										 : 
										((0x100073U 
										== vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
										 ? 4U
										 : 0U)))))))))))))))))))))))))))))))))))))))))))))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3 
	= ((0x2003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
	    ? 0U : ((3U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
		     ? 0U : ((0x4003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
			      ? 0U : ((0x1003U == (0x707fU 
						   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
				       ? 0U : ((0x5003U 
						== 
						(0x707fU 
						 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
					        ? 0U
					        : (
						   (0x2023U 
						    == 
						    (0x707fU 
						     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						    ? 0U
						    : 
						   ((0x23U 
						     == 
						     (0x707fU 
						      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						     ? 0U
						     : 
						    ((0x1023U 
						      == 
						      (0x707fU 
						       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						      ? 0U
						      : 
						     ((0x17U 
						       == 
						       (0x7fU 
							& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						       ? 1U
						       : 
						      ((0x37U 
							== 
							(0x7fU 
							 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						        ? 1U
						        : 
						       ((0x13U 
							 == 
							 (0x707fU 
							  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							 ? 0U
							 : 
							((0x7013U 
							  == 
							  (0x707fU 
							   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							  ? 0U
							  : 
							 ((0x6013U 
							   == 
							   (0x707fU 
							    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							   ? 0U
							   : 
							  ((0x4013U 
							    == 
							    (0x707fU 
							     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							    ? 0U
							    : 
							   ((0x2013U 
							     == 
							     (0x707fU 
							      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							     ? 0U
							     : 
							    ((0x3013U 
							      == 
							      (0x707fU 
							       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							      ? 0U
							      : 
							     ((0x1013U 
							       == 
							       (0xfc00707fU 
								& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							       ? 0U
							       : 
							      ((0x40005013U 
								== 
								(0xfc00707fU 
								 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							        ? 0U
							        : 
							       ((0x5013U 
								 == 
								 (0xfc00707fU 
								  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								 ? 0U
								 : 
								((0x1033U 
								  == 
								  (0xfe00707fU 
								   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								  ? 0U
								  : 
								 ((0x33U 
								   == 
								   (0xfe00707fU 
								    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								   ? 0U
								   : 
								  ((0x40000033U 
								    == 
								    (0xfe00707fU 
								     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								    ? 0U
								    : 
								   ((0x2033U 
								     == 
								     (0xfe00707fU 
								      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								     ? 0U
								     : 
								    ((0x3033U 
								      == 
								      (0xfe00707fU 
								       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								      ? 0U
								      : 
								     ((0x7033U 
								       == 
								       (0xfe00707fU 
									& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								       ? 0U
								       : 
								      ((0x6033U 
									== 
									(0xfe00707fU 
									 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								        ? 0U
								        : 
								       ((0x4033U 
									 == 
									 (0xfe00707fU 
									  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									 ? 0U
									 : 
									((0x40005033U 
									  == 
									  (0xfe00707fU 
									   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									  ? 0U
									  : 
									 ((0x5033U 
									   == 
									   (0xfe00707fU 
									    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									   ? 0U
									   : 
									  ((0x6fU 
									    == 
									    (0x7fU 
									     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									    ? 0U
									    : 
									   ((0x67U 
									     == 
									     (0x707fU 
									      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									     ? 0U
									     : 
									    ((0x63U 
									      == 
									      (0x707fU 
									       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									      ? 0U
									      : 
									     ((0x1063U 
									       == 
									       (0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									       ? 0U
									       : 
									      ((0x5063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									        ? 0U
									        : 
									       ((0x7063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 0U
										 : 
										((0x4063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 0U
										 : 
										((0x6063U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 0U
										 : 
										((0x5073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x6073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 
										((0x7073U 
										== 
										(0x707fU 
										& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
										 ? 2U
										 : 0U))))))))))))))))))))))))))))))))))))))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_30_data 
	= vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile
	[(0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
		   >> 0xfU))];
    vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4 
	= ((0x2003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
	    ? 1U : ((3U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
		     ? 1U : ((0x4003U == (0x707fU & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
			      ? 1U : ((0x1003U == (0x707fU 
						   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
				       ? 1U : ((0x5003U 
						== 
						(0x707fU 
						 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
					        ? 1U
					        : (
						   (0x2023U 
						    == 
						    (0x707fU 
						     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						    ? 2U
						    : 
						   ((0x23U 
						     == 
						     (0x707fU 
						      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						     ? 2U
						     : 
						    ((0x1023U 
						      == 
						      (0x707fU 
						       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						      ? 2U
						      : 
						     ((0x17U 
						       == 
						       (0x7fU 
							& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						       ? 3U
						       : 
						      ((0x37U 
							== 
							(0x7fU 
							 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
						        ? 0U
						        : 
						       ((0x13U 
							 == 
							 (0x707fU 
							  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							 ? 1U
							 : 
							((0x7013U 
							  == 
							  (0x707fU 
							   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							  ? 1U
							  : 
							 ((0x6013U 
							   == 
							   (0x707fU 
							    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							   ? 1U
							   : 
							  ((0x4013U 
							    == 
							    (0x707fU 
							     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							    ? 1U
							    : 
							   ((0x2013U 
							     == 
							     (0x707fU 
							      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							     ? 1U
							     : 
							    ((0x3013U 
							      == 
							      (0x707fU 
							       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							      ? 1U
							      : 
							     ((0x1013U 
							       == 
							       (0xfc00707fU 
								& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							       ? 1U
							       : 
							      ((0x40005013U 
								== 
								(0xfc00707fU 
								 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
							        ? 1U
							        : 
							       ((0x5013U 
								 == 
								 (0xfc00707fU 
								  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								 ? 1U
								 : 
								((0x1033U 
								  == 
								  (0xfe00707fU 
								   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								  ? 0U
								  : 
								 ((0x33U 
								   == 
								   (0xfe00707fU 
								    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								   ? 0U
								   : 
								  ((0x40000033U 
								    == 
								    (0xfe00707fU 
								     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								    ? 0U
								    : 
								   ((0x2033U 
								     == 
								     (0xfe00707fU 
								      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								     ? 0U
								     : 
								    ((0x3033U 
								      == 
								      (0xfe00707fU 
								       & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								      ? 0U
								      : 
								     ((0x7033U 
								       == 
								       (0xfe00707fU 
									& vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								       ? 0U
								       : 
								      ((0x6033U 
									== 
									(0xfe00707fU 
									 & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
								        ? 0U
								        : 
								       ((0x4033U 
									 == 
									 (0xfe00707fU 
									  & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									 ? 0U
									 : 
									((0x40005033U 
									  == 
									  (0xfe00707fU 
									   & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									  ? 0U
									  : 
									 ((0x5033U 
									   == 
									   (0xfe00707fU 
									    & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									   ? 0U
									   : 
									  ((0x6fU 
									    == 
									    (0x7fU 
									     & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									    ? 0U
									    : 
									   ((0x67U 
									     == 
									     (0x707fU 
									      & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189))
									     ? 1U
									     : 0U)))))))))))))))))))))))))))))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_s 
	= ((0xfe0U & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
		      >> 0x14U)) | (0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
					     >> 7U)));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_i_sext 
	= ((((0x80000000U & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
	      ? 0xfffffU : 0U) << 0xcU) | (0xfffU & 
					   (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
					    >> 0x14U)));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_35_data 
	= vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile
	[(0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
		   >> 0x14U))];
}

VL_INLINE_OPT void VTop::_combo__TOP__9(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__9\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ 
	= ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
	    ? 3U : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		     ? 1U : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
			      ? 5U : ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
				       ? 2U : ((4U 
						== (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
					        ? 6U
					        : (
						   (5U 
						    == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						    ? 3U
						    : 
						   ((6U 
						     == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						     ? 1U
						     : 
						    ((7U 
						      == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
						      ? 2U
						      : 0U))))))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
	= ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3))
	    ? ((0U != (0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
				>> 0xfU))) ? vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_30_data
	        : 0U) : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3))
			  ? (0xfffff000U & vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189)
			  : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3))
			      ? (0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
					  >> 0xfU))
			      : 0U)));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT___T_213 
	= ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
	    ? ((((0x80000U & vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_j)
		  ? 0x7ffU : 0U) << 0x15U) | (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_j 
					      << 1U))
	    : ((7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
	        ? vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_i_sext
	        : ((((0x800U & (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_b))
		      ? 0x7ffffU : 0U) << 0xdU) | ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_b) 
						   << 1U))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37 
	= ((0U != (0x1fU & (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
			    >> 0x14U))) ? vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_35_data
	    : 0U);
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93 
	= ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
	    ? 0U : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
		     ? 1U : ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ))
			      ? 3U : 0U)));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2 
	= ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4))
	    ? vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37
	    : ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4))
	        ? vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg
	        : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4))
		    ? vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_i_sext
		    : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4))
		        ? ((((0x800U & (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_s))
			      ? 0xfffffU : 0U) << 0xcU) 
			   | (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_s))
		        : 0U))));
}

VL_INLINE_OPT void VTop::_combo__TOP__11(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__11\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1)) 
				  + (QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2))));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_143 
	= (VL_ULL(0x7fffffffffffffff) & ((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37)) 
					 << (0x18U 
					     & ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76) 
						<< 3U))));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT___T_157 
	= (0x1fU & ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93))
		     ? (0xfU & ((IData)(1U) << (3U 
						& (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))))
		     : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93))
			 ? ((IData)(3U) << (3U & (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)))
			 : 0xfU)));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__dw_en 
	= ((((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	     & (0x10000000U <= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))) 
	    & (0x18000000U > (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))) 
	   & ((0U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
	      & ((1U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
		 & ((2U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
		    & ((3U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
		       & ((4U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
			  & ((5U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
			     | ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
				| (7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))))))))));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:40
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data 
	= ((0xffffff00U & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data) 
	   | vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	   [(0x1fffffU & (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))]);
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:40
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data 
	= ((0xffff00ffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(1U) + (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)))] 
	      << 8U));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:40
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data 
	= ((0xff00ffffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(2U) + (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)))] 
	      << 0x10U));
    // ALWAYS at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:40
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data 
	= ((0xffffffU & vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data) 
	   | (vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
	      [(0x1fffffU & ((IData)(3U) + (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)))] 
	      << 0x18U));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2 
	= (((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	    & (0x18000000U <= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))) 
	   & (0x18100000U > (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3 
	= (((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	    & (0x18100000U <= (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76))) 
	   & (0x18101000U > (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76)));
}

VL_INLINE_OPT void VTop::_combo__TOP__13(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__13\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20 
	= ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3)
	    ? 0U : ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
		     ? 0U : vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21 
	= ((~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3)) 
	   & ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
	       ? (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
	       : (3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc 
	= (1U & ((~ ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
		     & (~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21)))) 
		 & (~ (IData)(vlTOPp->io_freeze))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110 
	= ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	   & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21));
}

VL_INLINE_OPT void VTop::_combo__TOP__15(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_combo__TOP__15\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_instr_commit = vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc;
    vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___GEN_0 
	= ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc)
	    ? (((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
		& ((0U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
		       != vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
		    : ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		        ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
			   == vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
		        : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
			    ? VL_GTES_III(1,32,32, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
			    : ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
			        ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
				   >= vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
			        : ((4U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
				    ? VL_LTS_III(1,32,32, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1, vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
				    : ((5U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
				        ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
					   < vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2)
				        : ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
					   | (7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))))))))))
	        ? ((7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))
		    ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 
		       + vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT___T_213)
		    : ((IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg))) 
		       + vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT___T_213))
	        : ((IData)(4U) + (IData)((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg)))))
	    : vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg);
    vlTOPp->Top__DOT__tile__DOT__core___DOT__wbu__DOT__waddr 
	= (0x1fU & ((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))
		     ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
			>> 7U) : ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))
				   ? (vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
				      >> 7U) : ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110)
						 ? 
						(vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 
						 >> 7U)
						 : 0U))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_22 
	= (((1U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	    | ((2U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))
	        ? ((6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
		   | (7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)))
	        : ((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110) 
		   & (~ (((5U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2)) 
			  | (6U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))) 
			 | (7U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2))))))) 
	   & (0U != (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__wbu__DOT__waddr)));
}

void VTop::_eval(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    vlTOPp->_combo__TOP__7(vlSymsp);
    vlTOPp->_combo__TOP__9(vlSymsp);
    vlTOPp->_combo__TOP__11(vlSymsp);
    vlTOPp->_combo__TOP__13(vlSymsp);
    vlTOPp->_combo__TOP__15(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VTop::_change_request(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_change_request\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
