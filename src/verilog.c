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