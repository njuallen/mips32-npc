// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef _VTop___024unit_H_
#define _VTop___024unit_H_

#include "verilated.h"
#include "VTop__Dpi.h"

class VTop__Syms;

//----------

VL_MODULE(VTop___024unit) {
  public:
    // CELLS
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    //char	__VpadToAlign12[4];
    VTop__Syms*	__VlSymsp;		// Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VTop___024unit& operator= (const VTop___024unit&);	///< Copying not allowed
    VTop___024unit(const VTop___024unit&);	///< Copying not allowed
  public:
    VTop___024unit(const char* name="TOP");
    ~VTop___024unit();
    
    // USER METHODS
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VTop__Syms* symsp, bool first);
    void	__Vdpiimwrap_device_tick_TOP____024unit(CData in_req_valid, IData in_req_bits_addr, IData in_req_bits_data, CData in_req_bits_op, CData in_req_bits_wstrb);
  private:
    void	_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
