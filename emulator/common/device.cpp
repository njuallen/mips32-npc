#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "common.h"

static bool finished = false;
static int ret_code = 0;

void init_device(void) {
  finished = false;
  ret_code = 0;
}

bool is_finished(void) {
  return finished;
}

int get_exit_code(void) {
  return ret_code;
}

static const int trap_addr = 0;
static const int putc_addr = 4;

extern "C" void device_tick
(
  unsigned char   in_req_valid,
  int  in_req_bits_addr,
  int  in_req_bits_data,
  unsigned char   in_req_bits_op,
  unsigned char in_req_bits_wstrb
  ) {
  if (in_req_valid) {
    // for now, we only deal with write
    if (in_req_bits_op == 1) {
      switch (in_req_bits_addr) {
        case trap_addr:
          finished = true;
          ret_code = in_req_bits_data;
          break;
        case putc_addr:
          printf("%c", (unsigned char)in_req_bits_data);
          break;
        default:
          fprintf(stderr, "%x\n", in_req_bits_addr);
          app_error("Device: invalid address!");
          break;
      }
    }
    else
      app_error("Device: read not supported!");
  }
}
