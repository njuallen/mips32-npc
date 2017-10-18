// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop___024unit.h"    // For This
#include "VTop__Syms.h"

#include "verilated_dpi.h"

//--------------------
// Internal Methods

VL_INLINE_OPT void VTop___024unit::__Vdpiimwrap_device_tick_TOP____024unit(CData in_req_valid, IData in_req_bits_addr, IData in_req_bits_data, CData in_req_bits_op, CData in_req_bits_wstrb) {
    VL_DEBUG_IF(VL_PRINTF("        VTop___024unit::__Vdpiimwrap_device_tick_TOP____024unit\n"); );
    // Body
    unsigned char in_req_valid__Vcvt;
    in_req_valid__Vcvt = in_req_valid;
    int in_req_bits_addr__Vcvt;
    in_req_bits_addr__Vcvt = in_req_bits_addr;
    int in_req_bits_data__Vcvt;
    in_req_bits_data__Vcvt = in_req_bits_data;
    unsigned char in_req_bits_op__Vcvt;
    in_req_bits_op__Vcvt = in_req_bits_op;
    char in_req_bits_wstrb__Vcvt;
    in_req_bits_wstrb__Vcvt = in_req_bits_wstrb;
    device_tick(in_req_valid__Vcvt, in_req_bits_addr__Vcvt, in_req_bits_data__Vcvt, in_req_bits_op__Vcvt, in_req_bits_wstrb__Vcvt);
}
