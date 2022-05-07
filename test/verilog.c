#include "cgraph.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  cgraph_verilog_fsm_gray(stdout, "", 8);
  cgraph_verilog_clkgen_even(stdout, 2);
  cgraph_verilog_clkgen_odd(stdout, 2);
  cgraph_verilog_clkgen(stdout, 2);
  cgraph_verilog_sync(stdout, 2);
  cgraph_verilog_filter(stdout, 2);
  cgraph_verilog_simple(stdout, 2);
  cgraph_verilog_edgedect(stdout);
  cgraph_verilog_fifo(stdout, 8, 16);
  cgraph_verilog_shift(stdout, 8);
  cgraph_verilog_crc(stdout, 8);
  cgraph_verilog_tbench(stdout, 1000000);

  return 0;
}