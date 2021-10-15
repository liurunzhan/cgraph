#include "cgraph_file.h"
#include "cgraph_math.h"
#include "cgraph_verilog.h"

void cgraph_verilog_clkgen_even(FILE *fp, const cgraph_size_t len) {
  if ((NULL != fp) && (!ferror(fp))) {
    cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                     len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_NLINE "   rstn," __PLAT_NLINE
        "   clki," __PLAT_NLINE "   cnten," __PLAT_NLINE
        "   clken," __PLAT_NLINE "   br," __PLAT_NLINE "   clko" __PLAT_NLINE
        ");" __PLAT_NLINE "input              rstn;" __PLAT_NLINE
        "input              clki;" __PLAT_NLINE
        "input              cnten;" __PLAT_NLINE "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" __PLAT_NLINE, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "always @(*)" __PLAT_NLINE "begin" __PLAT_NLINE
                              "    if(clken)" __PLAT_NLINE
                              "    begin" __PLAT_NLINE "        case(dr)");
    for (i = 0; i < max; i++) {
      cgraph_file_fprintfln(fp, "        0x%lx : clko = clk_cnt[%ld];", i, i);
    }
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" __PLAT_NLINE
                              "        endcase" __PLAT_NLINE
                              "    end" __PLAT_NLINE "    else" __PLAT_NLINE
                              "      clko = 1'b0;" __PLAT_NLINE
                              "end" __PLAT_NLINE __PLAT_NLINE "endmodule");
  }
}

void cgraph_verilog_clkgen_odd(FILE *fp, const cgraph_size_t len) {
  if ((NULL != fp) && (!ferror(fp))) {
    cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                     len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_NLINE "   rstn," __PLAT_NLINE
        "   clki," __PLAT_NLINE "   cnten," __PLAT_NLINE
        "   clken," __PLAT_NLINE "   br," __PLAT_NLINE "   clko" __PLAT_NLINE
        ");" __PLAT_NLINE "input          rstn;" __PLAT_NLINE
        "input          clki;" __PLAT_NLINE "input          cnten;" __PLAT_NLINE
        "input          clken;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_p;" __PLAT_NLINE, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= (clk_cnt_p + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "reg clko_p;" __PLAT_NLINE __PLAT_NLINE
                              "always @(*)" __PLAT_NLINE "begin" __PLAT_NLINE
                              "    if(clken)" __PLAT_NLINE
                              "    begin" __PLAT_NLINE "        case(dr)");
    for (i = 0; i < max; i++) {
      cgraph_file_fprintfln(fp, "        0x%lx : clko_p = clk_cnt_p[%ld];", i,
                            i);
    }
    cgraph_file_fprintfln(fp, "        default : clko_p = 1'bx;" __PLAT_NLINE
                              "        endcase" __PLAT_NLINE
                              "    end" __PLAT_NLINE "    else" __PLAT_NLINE
                              "      clko_p = 1'b0;" __PLAT_NLINE "end");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_n;" __PLAT_NLINE, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(negedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= (clk_cnt_n + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "reg clko_n;" __PLAT_NLINE __PLAT_NLINE
                              "always @(*)" __PLAT_NLINE "begin" __PLAT_NLINE
                              "    if(clken)" __PLAT_NLINE
                              "    begin" __PLAT_NLINE "        case(dr)");
    for (i = 0; i < max; i++) {
      cgraph_file_fprintfln(fp, "        0x%lx : clko_n = clk_cnt_n[%ld];", i,
                            i);
    }
    cgraph_file_fprintfln(
        fp,
        "        default : clko_n = 1'bx;" __PLAT_NLINE
        "        endcase" __PLAT_NLINE "    end" __PLAT_NLINE
        "    else" __PLAT_NLINE "      clko_n = 1'b0;" __PLAT_NLINE
        "end" __PLAT_NLINE __PLAT_NLINE
        "assign clko = clko_p | clk_n;" __PLAT_NLINE __PLAT_NLINE "endmodule");
  }
}

void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len) {
  if ((NULL != fp) && (!ferror(fp))) {
    cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                     len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_NLINE "   rstn," __PLAT_NLINE
        "   clki," __PLAT_NLINE "   cnten," __PLAT_NLINE
        "   clken," __PLAT_NLINE "   br," __PLAT_NLINE "   clko" __PLAT_NLINE
        ");" __PLAT_NLINE "input              rstn;" __PLAT_NLINE
        "input              clki;" __PLAT_NLINE
        "input              cnten;" __PLAT_NLINE "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" __PLAT_NLINE, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "always @(*)" __PLAT_NLINE "begin" __PLAT_NLINE
                              "    if(clken)" __PLAT_NLINE
                              "    begin" __PLAT_NLINE "        case(dr)");
    for (i = 0; i < max; i++) {
      cgraph_file_fprintfln(fp, "        0x%lx : clko = clk_cnt[%ld];", i, i);
    }
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" __PLAT_NLINE
                              "        endcase" __PLAT_NLINE
                              "    end" __PLAT_NLINE "    else" __PLAT_NLINE
                              "      clko = 1'b0;" __PLAT_NLINE
                              "end" __PLAT_NLINE __PLAT_NLINE "endmodule");
  }
}

void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module sync (" __PLAT_NLINE
                              "  rstn," __PLAT_NLINE "  clki," __PLAT_NLINE
                              "  signi," __PLAT_NLINE "  signo" __PLAT_NLINE
                              ");" __PLAT_NLINE "input  rstn;" __PLAT_NLINE
                              "input  clki;" __PLAT_NLINE
                              "input  signi;" __PLAT_NLINE "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;" __PLAT_NLINE, len_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" __PLAT_NLINE "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "    end" __PLAT_NLINE "end");
    cgraph_file_fprintfln(fp, "assign signo = signs[%ld];" __PLAT_NLINE, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }
}

void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(
        fp, "module sync (" __PLAT_NLINE "  rstn," __PLAT_NLINE
            "  clki," __PLAT_NLINE "  signi," __PLAT_NLINE
            "  signo" __PLAT_NLINE ");" __PLAT_NLINE "input  rstn;" __PLAT_NLINE
            "input  clki;" __PLAT_NLINE "input  signi;" __PLAT_NLINE
            "output signo;" __PLAT_NLINE __PLAT_NLINE "reg [1:0] sync;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(fp,
                          "reg reg_signo;" __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)" __PLAT_NLINE
                          "        sync[1:0] <= {2{1'b0}};" __PLAT_NLINE
                          "    else" __PLAT_NLINE
                          "        sync[1:0] <= {sync[0], signi};" __PLAT_NLINE
                          "end" __PLAT_NLINE __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else");
    cgraph_file_fprintfln(fp,
                          "        signs[%ld:0] <= {signs[%ld:0], "
                          "sync[1]};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp,
                          "end" __PLAT_NLINE __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)" __PLAT_NLINE
                          "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1,
                          len);
    cgraph_file_fprintfln(
        fp, "        reg_signo <= 1'b1;" __PLAT_NLINE
            "end" __PLAT_NLINE __PLAT_NLINE
            "assign signo = reg_signo;" __PLAT_NLINE __PLAT_NLINE "endmodule");
  }
}

void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1;
    cgraph_file_fprintfln(fp, "module sync (" __PLAT_NLINE
                              "  rstn," __PLAT_NLINE "  clki," __PLAT_NLINE
                              "  signi," __PLAT_NLINE "  signo" __PLAT_NLINE
                              ");" __PLAT_NLINE "input  rstn;" __PLAT_NLINE
                              "input  clki;" __PLAT_NLINE
                              "input  signi;" __PLAT_NLINE "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(fp,
                          "reg         sign_last;" __PLAT_NLINE __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" __PLAT_NLINE "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len - 2);
    cgraph_file_fprintfln(fp,
                          "    end" __PLAT_NLINE "end" __PLAT_NLINE __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)" __PLAT_NLINE
                          "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b1;" __PLAT_NLINE
                              "end" __PLAT_NLINE __PLAT_NLINE "endmodule");
  }
}

void cgraph_verilog_edgedet(FILE *fp) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_file_fprintfln(
        fp, "module edgedect (" __PLAT_NLINE "  rstn," __PLAT_NLINE
            "  clki," __PLAT_NLINE "  signi," __PLAT_NLINE
            "  signp," __PLAT_NLINE "  signn" __PLAT_NLINE ");" __PLAT_NLINE
            "input  rstn;" __PLAT_NLINE "input  clki;" __PLAT_NLINE
            "input  signi;" __PLAT_NLINE "output signp;" __PLAT_NLINE
            "output signn;" __PLAT_NLINE __PLAT_NLINE "reg [2:0] signs;");
    cgraph_file_fprintfln(
        fp,
        "always @(posedge clki or negedge rstn)" __PLAT_NLINE
        "begin" __PLAT_NLINE "    if(!rstn)" __PLAT_NLINE
        "      signs[2:0] <= {3{1'b0}};" __PLAT_NLINE "    else" __PLAT_NLINE
        "      signs[2:0] <= {signs[1:0], signi};" __PLAT_NLINE
        "end" __PLAT_NLINE __PLAT_NLINE
        "assign signp = (~signs[2] & sign[1]);" __PLAT_NLINE
        "assign signn = (signs[2] & ~sign[1]);" __PLAT_NLINE __PLAT_NLINE
        "endmodule");
  }
}

void cgraph_verilog_handshake(FILE *fp) {}

void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                         const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
    cgraph_file_fprintfln(fp,
                          "module fifo (" __PLAT_NLINE "  rstn," __PLAT_NLINE
                          "  clk," __PLAT_NLINE "  write," __PLAT_NLINE
                          "  read," __PLAT_NLINE "  big," __PLAT_NLINE
                          "  din," __PLAT_NLINE "  dout" __PLAT_NLINE ");");
    cgraph_file_fprintfln(fp, "input  rstn;" __PLAT_NLINE
                              "input  clki;" __PLAT_NLINE
                              "input  write;" __PLAT_NLINE
                              "input  read;" __PLAT_NLINE "input  big;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", vlen_1);
    cgraph_file_fprintfln(fp, "output [%ld:0] dout;" __PLAT_NLINE, vlen_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_fifo;" __PLAT_NLINE, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }
}

void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t i, len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp,
                          "module shift (" __PLAT_NLINE "  rstn," __PLAT_NLINE
                          "  clk," __PLAT_NLINE "  write," __PLAT_NLINE
                          "  read," __PLAT_NLINE "  msb," __PLAT_NLINE
                          "  din," __PLAT_NLINE "  dout" __PLAT_NLINE ");");
    cgraph_file_fprintfln(fp, "input  rstn;" __PLAT_NLINE
                              "input  clki;" __PLAT_NLINE
                              "input  write;" __PLAT_NLINE
                              "input  read;" __PLAT_NLINE "input  msb;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "output dout;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_shift;", len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_cnt;" __PLAT_NLINE, len_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if(read)");
    cgraph_file_fprintfln(
        fp,
        "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, "
        "1'b1};",
        len_1, len_1, len_1);
    cgraph_file_fprintfln(fp,
                          "end" __PLAT_NLINE __PLAT_NLINE
                          "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                          "begin" __PLAT_NLINE "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if(write)" __PLAT_NLINE
                              "    begin" __PLAT_NLINE "        if(msb)");
    cgraph_file_fprintfln(fp, "            reg_shift[%ld:0] <= din[%ld:0];",
                          len_1, len_1);
    cgraph_file_fprintfln(fp, "        else");
    cgraph_file_fprintf(fp, "            reg_shift[%ld:0] <= {din[0]", len_1);
    for (i = 1; i < len; i++) {
      cgraph_file_fprintf(fp, ", din[%ld]", i);
    }
    cgraph_file_fprintfln(fp, "};" __PLAT_NLINE "    end" __PLAT_NLINE
                              "    else if(read)");
    cgraph_file_fprintfln(fp,
                          "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
                          "1'b0};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "assign dout = reg_shift[%ld];" __PLAT_NLINE,
                          len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }
}

void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2, i;
    cgraph_file_fprintfln(fp, "module crc (" __PLAT_NLINE "  rstn," __PLAT_NLINE
                              "  clk," __PLAT_NLINE "  write," __PLAT_NLINE
                              "  read," __PLAT_NLINE "  msb," __PLAT_NLINE
                              "  din," __PLAT_NLINE "  poly" __PLAT_NLINE
                              "  dout" __PLAT_NLINE ");");
    cgraph_file_fprintfln(fp, "input  rstn;" __PLAT_NLINE
                              "input  clki;" __PLAT_NLINE
                              "input  write;" __PLAT_NLINE
                              "input  read;" __PLAT_NLINE "input  msb;");
    cgraph_file_fprintfln(fp, "input   [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "input   [%ld:0] poly;", len_1);
    cgraph_file_fprintfln(fp, "output  [%ld:0] dout;" __PLAT_NLINE, len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_crc;" __PLAT_NLINE, len_1);
    cgraph_file_fprintf(fp,
                        "always @(posedge clki or negedge rstn)" __PLAT_NLINE
                        "begin" __PLAT_NLINE "    if(!rstn)" __PLAT_NLINE
                        "        reg_crc[%ld:0] <= {%ld{1'b1}};" __PLAT_NLINE
                        "    else if(write)" __PLAT_NLINE
                        "    begin" __PLAT_NLINE "        if(msb)" __PLAT_NLINE
                        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
                        "din[%ld:0];" __PLAT_NLINE "        else" __PLAT_NLINE
                        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
                        "{din[0]",
                        len_1, len, len_1, len_1, len_1, len_1, len_1);
    for (i = 1; i < len; i++) {
      cgraph_file_fprintf(fp, ", din[%ld]", i);
    }
    cgraph_file_fprintfln(fp, "};" __PLAT_NLINE "    end");
    cgraph_file_fprintfln(fp,
                          "    else" __PLAT_NLINE
                          "        reg_crc[%ld:0] <= ({reg_crc[%ld:0], 1'b0} ^ "
                          "{%ld{reg_crc[%ld]}}) & poly[%ld:0];" __PLAT_NLINE
                          "end" __PLAT_NLINE,
                          len_1, len_2, len, len_1, len_1);
    cgraph_file_fprintfln(fp,
                          "assign dout[%ld:0] = (read ? reg_crc[%ld:0] : "
                          "{%ld{1'b0}});" __PLAT_NLINE __PLAT_NLINE "endmodule",
                          len_1, len_1, len);
  }
}

void cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time) {
  cgraph_file_fprintfln(fp, "`timescale 1ns/1ps" __PLAT_NLINE __PLAT_NLINE
                            "module tbench();" __PLAT_NLINE
                            "reg clk;" __PLAT_NLINE "reg rstn;");
  cgraph_file_fprintfln(
      fp, "always @(*)" __PLAT_NLINE "begin" __PLAT_NLINE
          "    if(!rstn)" __PLAT_NLINE "      clk = 1'b0;" __PLAT_NLINE
          "    else" __PLAT_NLINE "      #50 clk = ~clk;" __PLAT_NLINE
          "end" __PLAT_NLINE);
  cgraph_file_fprintfln(fp,
                        "initial" __PLAT_NLINE "begin" __PLAT_NLINE
                        "    rstn = 1'b0;" __PLAT_NLINE
                        "    #100 rstn = 1'b1;" __PLAT_NLINE
                        "    #%ld rstn = 1'b0;" __PLAT_NLINE
                        "    #100 $finish;" __PLAT_NLINE "end" __PLAT_NLINE,
                        delay_time);
  cgraph_file_fprintfln(fp, "endmodule");
}
