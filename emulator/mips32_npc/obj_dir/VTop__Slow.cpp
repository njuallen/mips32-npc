// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop.h"              // For This
#include "VTop__Syms.h"

#include "verilated_dpi.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VTop) {
    VTop__Syms* __restrict vlSymsp = __VlSymsp = new VTop__Syms(this, name());
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL (__PVT____024unit, VTop___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VTop::__Vconfigure(VTop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VTop::~VTop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------
// Internal Methods

void VTop::_initial__TOP__1(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_initial__TOP__1\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at generated-src/Top.v:2073
    vlTOPp->io_success = 0U;
    // INITIAL at generated-src/Top.v:2074
    vlTOPp->io_dl_req_ready = 1U;
    // INITIAL at generated-src/Top.v:2077
    vlTOPp->io_dl_resp_bits_resp = 0U;
    // INITIAL at /home/liuzhigang/npc/mips32-npc/emulator/common/AsyncReadMem.sv:24
    VL_READMEM_Q (true,8,2097152, 0,2, VL_ULL(0x62696e2e747874)
		  , vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem
		  ,0,~0);
}

void VTop::_settle__TOP__6(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__6\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_43_data 
	= vlTOPp->Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile
	[(0x1fU & vlTOPp->io_dl_req_bits_addr)];
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
}

void VTop::_settle__TOP__8(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__8\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

void VTop::_settle__TOP__10(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__10\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op1)) 
				  + (QData)((IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__isu__DOT__op2))));
}

void VTop::_settle__TOP__12(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__12\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20 
	= ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3)
	    ? 0U : ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
		     ? 0U : vlTOPp->Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data));
    vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21 
	= ((~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3)) 
	   & ((IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
	       ? (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2)
	       : (3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1))));
}

void VTop::_settle__TOP__14(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__14\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc 
	= (1U & ((~ ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
		     & (~ (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21)))) 
		 & (~ (IData)(vlTOPp->io_freeze))));
    vlTOPp->Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110 
	= ((3U == (IData)(vlTOPp->Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1)) 
	   & (IData)(vlTOPp->Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21));
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
}

void VTop::_settle__TOP__16(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_settle__TOP__16\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void VTop::_eval_initial(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval_initial\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VTop::final() {
    VL_DEBUG_IF(VL_PRINTF("    VTop::final\n"); );
    // Variables
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTop::_eval_settle(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_eval_settle\n"); );
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
    vlTOPp->_settle__TOP__8(vlSymsp);
    vlTOPp->_settle__TOP__10(vlSymsp);
    vlTOPp->_settle__TOP__12(vlSymsp);
    vlTOPp->_settle__TOP__14(vlSymsp);
    vlTOPp->_settle__TOP__16(vlSymsp);
}

void VTop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_success = VL_RAND_RESET_I(1);
    io_dl_req_ready = VL_RAND_RESET_I(1);
    io_dl_req_valid = VL_RAND_RESET_I(1);
    io_dl_req_bits_op = VL_RAND_RESET_I(2);
    io_dl_req_bits_addr = VL_RAND_RESET_I(32);
    io_dl_req_bits_data = VL_RAND_RESET_I(32);
    io_dl_resp_ready = VL_RAND_RESET_I(1);
    io_dl_resp_valid = VL_RAND_RESET_I(1);
    io_dl_resp_bits_data = VL_RAND_RESET_I(32);
    io_dl_resp_bits_resp = VL_RAND_RESET_I(2);
    io_freeze = VL_RAND_RESET_I(1);
    io_instr_commit = VL_RAND_RESET_I(1);
    io_core_reset = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__core___DOT__ifu__DOT__pc_reg = VL_RAND_RESET_I(29);
    Top__DOT__tile__DOT__core___DOT__ifu__DOT__update_pc = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__core___DOT__ifu__DOT___GEN_0 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__ifu__DOT___T_189 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_1 = VL_RAND_RESET_I(3);
    Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_2 = VL_RAND_RESET_I(5);
    Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_3 = VL_RAND_RESET_I(2);
    Top__DOT__tile__DOT__core___DOT__idu__DOT__csignals_4 = VL_RAND_RESET_I(2);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_s = VL_RAND_RESET_I(12);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_b = VL_RAND_RESET_I(12);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_j = VL_RAND_RESET_I(20);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__imm_i_sext = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__op1 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__isu__DOT__op2 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__isu__DOT___T_213 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_76 = VL_RAND_RESET_Q(33);
    Top__DOT__tile__DOT__core___DOT__lsu__DOT__typ = VL_RAND_RESET_I(3);
    Top__DOT__tile__DOT__core___DOT__lsu__DOT___T_110 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__core___DOT__wbu__DOT__waddr = VL_RAND_RESET_I(5);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_30_data = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_35_data = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__regfile__DOT__regfile___05FT_43_data = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_22 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__core___DOT__regfile__DOT___T_37 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_0_data = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__memory__DOT__async_data_dataInstr_1_data = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__memory__DOT__dw_en = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__memory__DOT___T_143 = VL_RAND_RESET_Q(63);
    Top__DOT__tile__DOT__memory__DOT___T_157 = VL_RAND_RESET_I(5);
    Top__DOT__tile__DOT__memory__DOT__smem_bridges_0__DOT___T_93 = VL_RAND_RESET_I(2);
    Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_2 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT__to_3 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_20 = VL_RAND_RESET_I(32);
    Top__DOT__tile__DOT__memory__DOT__crossbars_0__DOT___GEN_21 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_2 = VL_RAND_RESET_I(1);
    Top__DOT__tile__DOT__memory__DOT__crossbars_1__DOT__to_3 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2097152; ++__Vi0) {
	    Top__DOT__tile__DOT__memory__DOT__async_data__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
}

void VTop::_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VTop::_configure_coverage\n"); );
}
