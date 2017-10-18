#include <cstdio>
#include <cstdlib>
#include <cassert>

#if VM_TRACE
#include <memory>
#include <verilated_vcd_c.h>
#include "verilator.h"
#include "verilated.h"
#endif

#include "VTop__Dpi.h"
#include "common.h"
#include "VTop.h" // chisel-generated code...

VTop *dut_ptr = nullptr; // design under test, aka, your chisel code

// control the number of cycles the processor can run
uint64_t max_cycles = 0;
uint64_t cycle_count = 0;

bool interactive = false;

FILE *vcdfile = nullptr;

#if VM_TRACE
std::unique_ptr<VerilatedVcdFILE> vcdfd;
std::unique_ptr<VerilatedVcdC> tfp;
#endif

double sc_time_stamp () {
  return double(cycle_count);
}

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    // run in interactive mode
    if (arg.substr(0, 2) == "-d")
      interactive = true;
    else if (arg.substr(0, 2) == "-v")
      vcdfile = fopen(argv[i]+2,(const char*)"w+");
    else if (arg.substr(0, 12) == "+max-cycles=")
      max_cycles = atoll(argv[i]+12);
  }

  VTop dut; // design under test, aka, your chisel code
  dut_ptr = &dut;

#if VM_TRACE
  vcdfd = std::unique_ptr<VerilatedVcdFILE>(new VerilatedVcdFILE(vcdfile));
  tfp = std::unique_ptr<VerilatedVcdC>(new VerilatedVcdC(vcdfd.get()));
  Verilated::traceEverOn(true); // Verilator must compute traced signals
  if (vcdfile) {
    dut.trace(tfp.get(), 99);  // Trace 99 levels of hierarchy
    tfp->open("");
  }
#endif

  // reset for a few cycles to support pipelined reset
  for (int i = 0; i < 10; i++) {
    // reset为何需要反复再0和1之间切换？
    // 不应该直接置高电平就可以了嘛？
    dut_ptr->reset = 1;
    dut_ptr->clock = 0;
    dut_ptr->eval();
    dut_ptr->clock = 1;
    dut_ptr->eval();
    dut_ptr->reset = 0;
  }

  init_device();

  int ret = 0;
  int ret_code;
  if (interactive) {
    // run in interactive mode, call the monitor
    ret = monitor();
  }
  else {
    // run until program ends
    ret = sc(-1, &ret_code);
    if (ret == -1) {
      printf("*** FAILED *** (timeout) after %lld cycles\n", (long long)cycle_count);
      ret = -1;
    }
    else if (ret_code == 0) {
      printf("*** PASSED ***\n");
      ret = 0;
    }
    else 
      ret = ret_code;
  }

#if VM_TRACE
  if (tfp)
    tfp->close();
  if (vcdfile)
    fclose(vcdfile);
#endif   
  return ret;
}

// the number of cycles to step
// -1 means run until it ends
// return value:
// 0: success     <0: error
int sc(unsigned int ncycle, int *ret_code) {
  bool timeout = false;
  for(int i = 0; i < ncycle && !is_finished(); i++) {
    // fprintf(stderr, "before clock 0\n");
    dut_ptr->clock = 0;
    dut_ptr->eval();
    /*
    fprintf(stderr, "pc= 0x%x instr= 0x%x imem_valid= %d dmem_valid= %d\n",
        dut_ptr->io_pc, dut_ptr->io_instr, dut_ptr->io_imem_resp_valid, dut_ptr->io_dmem_resp_valid);
    fprintf(stderr, "after clock 0\n\n");
    */

#if VM_TRACE
    tfp->dump(static_cast<vluint64_t>(cycle_count * 2));
#endif
    // fprintf(stderr, "before clock 1\n");
    dut_ptr->clock = 1;
    dut_ptr->eval();
    /*
    fprintf(stderr, "pc= 0x%x instr= 0x%x imem_valid= %d dmem_valid= %d\n",
        dut_ptr->io_pc, dut_ptr->io_instr, dut_ptr->io_imem_resp_valid, dut_ptr->io_dmem_resp_valid);
    fprintf(stderr, "after clock 1\n\n");
    */

#if VM_TRACE
    tfp->dump(static_cast<vluint64_t>(cycle_count * 2 + 1));
#endif
    cycle_count++;
    if (max_cycles != 0 && cycle_count == max_cycles) {
      timeout = true;
      break;
    }
  }

  if (timeout)
    return -1;

  if(is_finished()) {
    *ret_code = get_exit_code();
    return 1;
  }

  // ran n cycles and not finished
  return 0;
}

// the number of instructions to step
// -1 means run until it ends
// return value:
// 0: success     <0: error
// if the program ends, return code will be put in *ret_code
int si(unsigned int ninstr, int *ret_code) {
    /*
       int ret = 0;
       for(int i = 0; i < ninstr;) {
       ret = sc(1, ret_code);
    // program ended
    if (ret)
    break;
    // check whether an instruction has committed
    if (dut_ptr->io_instr_commit)
    i++;
    }
    return ret;
    */
    return 0;
}

// DebugLite Message Interface
unsigned int send_dlmi_req(int op, int addr, int data) {
    /*
       assert(dut_ptr->io_dl_req_ready);
       dut_ptr->io_dl_req_valid = 1;
       dut_ptr->io_dl_req_bits_op = op;
       dut_ptr->io_dl_req_bits_addr = addr;
       dut_ptr->io_dl_req_bits_data = data;
       dut_ptr->io_dl_resp_ready = 1;
    // run one cycle
    // cycles used to debug does not count into cycle_count
    dut_ptr->clock = 0;
    dut_ptr->eval();
    dut_ptr->clock = 1;
    dut_ptr->eval();
    assert(dut_ptr->io_dl_resp_valid && dut_ptr->io_dl_resp_bits_resp == RESP_SUCCESS);
    dut_ptr->io_dl_req_valid = 0;
    return dut_ptr->io_dl_resp_bits_data;
    */
    return 0;
}

// read the content of a register(GPRs and PC)
// -1 means run until it ends
// return value:
// 0: success     <0: error
// if the program ends, return code will be put in *ret_code
unsigned int read_reg(int reg_no) {
    /*
    // first, we need to freeze the processor
    // so that the state of the processor will not be modified
    // while we reading these registers
    dut_ptr->io_freeze = 1;
    int ret = send_dlmi_req(OP_READ, reg_no, 0);
    // unfreeze the processor
    dut_ptr->io_freeze = 0;
    return ret;
    */
    return 0;
}
