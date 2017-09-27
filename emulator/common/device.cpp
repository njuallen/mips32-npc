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
  unsigned char   reset,
  unsigned char*   in_req_ready,
  unsigned char   in_req_valid,
  int  in_req_bits_addr,
  int  in_req_bits_data,
  unsigned char   in_req_bits_op,
  unsigned char in_req_bits_wstrb,
  unsigned char*   in_resp_valid,
  int*   in_resp_bits_data
  ) {
  // we are always ready
  *in_req_ready = 1;
  if (reset)
    *in_resp_valid = 0;
  else {
    if (in_req_valid) {
      *in_resp_valid = 1;
      *in_resp_bits_data = 0;
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
    else
      *in_resp_valid = 0;
  }
}
