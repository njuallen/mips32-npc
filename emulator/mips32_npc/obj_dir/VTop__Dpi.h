// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to insure
// the C functions match the expectations of the DPI imports.

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    
    // DPI IMPORTS
    // DPI Import at /home/liuzhigang/npc/mips32-npc/emulator/common/Device.v:2
    extern void device_tick (unsigned char in_req_valid, int in_req_bits_addr, int in_req_bits_data, unsigned char in_req_bits_op, char in_req_bits_wstrb);
    
#ifdef __cplusplus
}
#endif
