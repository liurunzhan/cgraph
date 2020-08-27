#include <stdio.h>
#include "cgraph_math.h"
#include "cgraph_verilog.h"

void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len)
{
  if((NULL != fp) && (!ferror(fp)))
  {
    cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max-1, len_1 = len-1;
    fprintf(fp, "module clkgen (\n");
    fprintf(fp, "   rstn,\n");
    fprintf(fp, "   clki,\n");
    fprintf(fp, "   cnten,\n");
    fprintf(fp, "   clken,\n");
    fprintf(fp, "   br,\n");
    fprintf(fp, "   clko\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input              rstn;\n");
    fprintf(fp, "input              clki;\n");
    fprintf(fp, "input              cnten;\n");
    fprintf(fp, "input              clken;\n");
    fprintf(fp, "input      [%ld:0] br;\n", len_1);
    fprintf(fp, "output reg         clko;\n\n");
    fprintf(fp, "reg [%ld:0] clk_cnt;\n\n", max_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "      clk_cnt <= {%ld{1'b0}};\n", max);
    fprintf(fp, "    else if(cnten)\n");
    fprintf(fp, "      clk_cnt <= (clk_cnt + %ld'b1);\n", max);
    fprintf(fp, "  end\n\n");
    fprintf(fp, "always @(*)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(clken)\n");
    fprintf(fp, "      begin\n");
    fprintf(fp, "        case(dr)\n");
    for(i=0; i<max; i++)
    { fprintf(fp, "        %ld : clko = clk_cnt[%ld];\n", i, i); }
    fprintf(fp, "        default : clko = 1'bx;\n");
    fprintf(fp, "        endcase\n");
    fprintf(fp, "      end\n");
    fprintf(fp, "    else\n");
    fprintf(fp, "      clko = 1'b0;\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t len_1 = len-1, len_2 = len-2;
    fprintf(fp, "module sync (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clki,\n");
    fprintf(fp, "  signi,\n");
    fprintf(fp, "  signo\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  signi;\n");
    fprintf(fp, "output signo;\n\n");
    fprintf(fp, "reg [%ld:0] signs;\n\n", len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};\n", len_1, len);
    fprintf(fp, "    else\n");
    fprintf(fp, "      begin\n");
    fprintf(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};\n", len_1, len_2);
    fprintf(fp, "      end\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "assign signo = signs[%ld];\n\n", len_1);
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t len_1 = len-1, len_2 = len-2;
    fprintf(fp, "module sync (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clki,\n");
    fprintf(fp, "  signi,\n");
    fprintf(fp, "  signo\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  signi;\n");
    fprintf(fp, "output signo;\n\n");
    fprintf(fp, "reg [1:0] sync;\n");
    fprintf(fp, "reg [%ld:0] signs;\n", len_1);
    fprintf(fp, "reg reg_signo;\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "        sync[1:0] <= {2{1'b0}};\n");
    fprintf(fp, "    else\n");
    fprintf(fp, "        sync[1:0] <= {sync[0], signi};\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "        signs[%ld:0] <= {%ld{1'b0}};\n", len_1, len);
    fprintf(fp, "    else\n");
    fprintf(fp, "        signs[%ld:0] <= {signs[%ld:0], sync[1]};\n", len_1, len_2);
    fprintf(fp, "  end\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "        reg_signo <= 1'b0;\n");
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1, len);
    fprintf(fp, "        reg_signo <= 1'b0;\n");
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1, len);
    fprintf(fp, "        reg_signo <= 1'b1;\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "assign signo = reg_signo;\n\n");
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t len_1 = len-1;
    fprintf(fp, "module sync (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clki,\n");
    fprintf(fp, "  signi,\n");
    fprintf(fp, "  signo\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  signi;\n");
    fprintf(fp, "output signo;\n\n");
    fprintf(fp, "reg [%ld:0] signs;\n", len_1);
    fprintf(fp, "reg         sign_last;\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};\n", len_1, len);
    fprintf(fp, "    else\n");
    fprintf(fp, "      begin\n");
    fprintf(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};\n", len_1, len-2);
    fprintf(fp, "      end\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "       sign_last <= 1'b0;\n");
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})\n", len_1, len);
    fprintf(fp, "       sign_last <= 1'b0;\n");
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})\n", len_1, len);
    fprintf(fp, "       sign_last <= 1'b1;\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_edgedet(FILE *fp)
{
  if(NULL != fp && !ferror(fp))
  {
    fprintf(fp, "module edgedect (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clki,\n");
    fprintf(fp, "  signi,\n");
    fprintf(fp, "  signp,\n");
    fprintf(fp, "  signn\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  signi;\n");
    fprintf(fp, "output signp;\n");
    fprintf(fp, "output signn;\n\n");
    fprintf(fp, "reg [2:0] signs;\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "      signs[2:0] <= {3{1'b0}};\n");
    fprintf(fp, "    else\n");
    fprintf(fp, "      signs[2:0] <= {signs[1:0], signi};\n");
    fprintf(fp, "  end\n\n");
    fprintf(fp, "assign signp = (~signs[2] & sign[1]);\n");
    fprintf(fp, "assign signn = (signs[2] & ~sign[1]);\n\n");
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_handshake(FILE *fp)
{
  
}

void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t vlen_1 = vlen-1, len_1 = len-1;
    fprintf(fp, "module fifo (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clk,\n");
    fprintf(fp, "  write,\n");
    fprintf(fp, "  read,\n");
    fprintf(fp, "  big,\n");
    fprintf(fp, "  din,\n");
    fprintf(fp, "  dout\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  write;\n");
    fprintf(fp, "input  read;\n");
    fprintf(fp, "input  big;\n");
    fprintf(fp, "input  [%ld:0] din;\n", vlen_1);
    fprintf(fp, "output [%ld:0] dout;\n\n", vlen_1);
    fprintf(fp, "reg [%ld:0] reg_fifo;\n\n", len_1);
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t i, len_1 = len-1, len_2 = len-2;
    fprintf(fp, "module shift (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clk,\n");
    fprintf(fp, "  write,\n");
    fprintf(fp, "  read,\n");
    fprintf(fp, "  msb,\n");
    fprintf(fp, "  din,\n");
    fprintf(fp, "  dout\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  write;\n");
    fprintf(fp, "input  read;\n");
    fprintf(fp, "input  msb;\n");
    fprintf(fp, "input  [%ld:0] din;\n", len_1);
    fprintf(fp, "output dout;\n\n");
    fprintf(fp, "reg [%ld:0] reg_shift;\n", len_1);
    fprintf(fp, "reg [%ld:0] reg_cnt;\n\n", len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};\n", len_1, len);
    fprintf(fp, "    else if(read)\n");
    fprintf(fp, "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, 1'b1};\n", len_1, len_1, len_1);
    fprintf(fp, "  end\n\n");
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};\n", len_1, len);
    fprintf(fp, "    else if(write)\n");
    fprintf(fp, "      begin\n");
    fprintf(fp, "        if(msb)\n");
    fprintf(fp, "            reg_shift[%ld:0] <= din[%ld:0];\n", len_1, len_1);
    fprintf(fp, "        else\n");
    fprintf(fp, "            reg_shift[%ld:0] <= {reg_shift[0]", len_1);
    for(i = 1; i < len; i++)
    { fprintf(fp, ", reg_shift[%ld]", i); }
    fprintf(fp, "};\n");
    fprintf(fp, "      end\n");
    fprintf(fp, "    else if(read)\n");
    fprintf(fp, "        reg_shift[%ld:0] <= {reg_shift[%ld:0], 1'b0};\n", len_1, len_2);
    fprintf(fp, "  end\n\n");
    fprintf(fp, "assign dout = reg_shift[%ld];\n\n", len_1);
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len)
{
  if(NULL != fp && !ferror(fp))
  {
    cgraph_size_t len_1 = len-1;
    fprintf(fp, "module crc (\n");
    fprintf(fp, "  rstn,\n");
    fprintf(fp, "  clk,\n");
    fprintf(fp, "  write,\n");
    fprintf(fp, "  read,\n");
    fprintf(fp, "  msb,\n");
    fprintf(fp, "  din,\n");
    fprintf(fp, "  dout\n");
    fprintf(fp, ");\n");
    fprintf(fp, "input  rstn;\n");
    fprintf(fp, "input  clki;\n");
    fprintf(fp, "input  write;\n");
    fprintf(fp, "input  read;\n");
    fprintf(fp, "input  msb;\n");
    fprintf(fp, "input  [%ld:0] din;\n", len_1);
    fprintf(fp, "output dout;\n\n");
    fprintf(fp, "reg [%ld:0] reg_crc;\n\n", len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)\n");
    fprintf(fp, "  begin\n");
    fprintf(fp, "    if(!rstn)\n");
    fprintf(fp, "    else\n");
    fprintf(fp, "  end\n");
    fprintf(fp, "endmodule\n");
  }
}

void cgraph_verilog_test(void)
{
#ifdef DEBUG
  cgraph_verilog_clkgen(stdout, 2);
  cgraph_verilog_sync(stdout, 2);
  cgraph_verilog_filter(stdout, 2);
  cgraph_verilog_simple(stdout, 2);
  cgraph_verilog_edgedet(stdout);
  cgraph_verilog_fifo(stdout, 8, 16);
  cgraph_verilog_shift(stdout, 8);
  cgraph_verilog_crc(stdout, 8);
#endif
}
