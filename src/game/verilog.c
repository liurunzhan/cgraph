#include "cgraph_file.h"
#include "cgraph_math.h"
#include "cgraph_verilog.h"

cgraph_bool_t cgraph_verilog_clkgen_even(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2(len), max_1 = max - 1, len_1 = len - 1;
    flag = CGRAPH_TRUE;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_LEND "   rstn," __PLAT_LEND
        "   clki," __PLAT_LEND "   cnten," __PLAT_LEND "   clken," __PLAT_LEND
        "   br," __PLAT_LEND "   clko" __PLAT_LEND ");" __PLAT_LEND
        "input              rstn;" __PLAT_LEND
        "input              clki;" __PLAT_LEND
        "input              cnten;" __PLAT_LEND "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" __PLAT_LEND, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "always @(*)" __PLAT_LEND "begin" __PLAT_LEND
                              "    if(clken)" __PLAT_LEND
                              "    begin" __PLAT_LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko = clk_cnt[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" __PLAT_LEND
                              "        endcase" __PLAT_LEND
                              "    end" __PLAT_LEND "    else" __PLAT_LEND
                              "      clko = 1'b0;" __PLAT_LEND
                              "end" __PLAT_LEND __PLAT_LEND "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_clkgen_odd(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2(len), max_1 = max - 1, len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_LEND "   rstn," __PLAT_LEND
        "   clki," __PLAT_LEND "   cnten," __PLAT_LEND "   clken," __PLAT_LEND
        "   br," __PLAT_LEND "   clko" __PLAT_LEND ");" __PLAT_LEND
        "input          rstn;" __PLAT_LEND "input          clki;" __PLAT_LEND
        "input          cnten;" __PLAT_LEND "input          clken;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_p;" __PLAT_LEND, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= (clk_cnt_p + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "reg clko_p;" __PLAT_LEND __PLAT_LEND
                              "always @(*)" __PLAT_LEND "begin" __PLAT_LEND
                              "    if(clken)" __PLAT_LEND
                              "    begin" __PLAT_LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko_p = clk_cnt_p[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : clko_p = 1'bx;" __PLAT_LEND
                              "        endcase" __PLAT_LEND
                              "    end" __PLAT_LEND "    else" __PLAT_LEND
                              "      clko_p = 1'b0;" __PLAT_LEND "end");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_n;" __PLAT_LEND, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(negedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= (clk_cnt_n + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "reg clko_n;" __PLAT_LEND __PLAT_LEND
                              "always @(*)" __PLAT_LEND "begin" __PLAT_LEND
                              "    if(clken)" __PLAT_LEND
                              "    begin" __PLAT_LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko_n = clk_cnt_n[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(
        fp,
        "        default : clko_n = 1'bx;" __PLAT_LEND
        "        endcase" __PLAT_LEND "    end" __PLAT_LEND
        "    else" __PLAT_LEND "      clko_n = 1'b0;" __PLAT_LEND
        "end" __PLAT_LEND __PLAT_LEND
        "assign clko = clko_p | clk_n;" __PLAT_LEND __PLAT_LEND "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2(len), max_1 = max - 1, len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" __PLAT_LEND "   rstn," __PLAT_LEND
        "   clki," __PLAT_LEND "   cnten," __PLAT_LEND "   clken," __PLAT_LEND
        "   br," __PLAT_LEND "   clko" __PLAT_LEND ");" __PLAT_LEND
        "input              rstn;" __PLAT_LEND
        "input              clki;" __PLAT_LEND
        "input              cnten;" __PLAT_LEND "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" __PLAT_LEND, max_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if(cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "always @(*)" __PLAT_LEND "begin" __PLAT_LEND
                              "    if(clken)" __PLAT_LEND
                              "    begin" __PLAT_LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko = clk_cnt[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" __PLAT_LEND
                              "        endcase" __PLAT_LEND
                              "    end" __PLAT_LEND "    else" __PLAT_LEND
                              "      clko = 1'b0;" __PLAT_LEND
                              "end" __PLAT_LEND __PLAT_LEND "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_sync(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp,
                          "module sync (" __PLAT_LEND "  rstn," __PLAT_LEND
                          "  clki," __PLAT_LEND "  signi," __PLAT_LEND
                          "  signo" __PLAT_LEND ");" __PLAT_LEND
                          "input  rstn;" __PLAT_LEND "input  clki;" __PLAT_LEND
                          "input  signi;" __PLAT_LEND "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;" __PLAT_LEND, len_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" __PLAT_LEND "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "    end" __PLAT_LEND "end");
    cgraph_file_fprintfln(fp, "assign signo = signs[%ld];" __PLAT_LEND, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_filter(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(
        fp, "module sync (" __PLAT_LEND "  rstn," __PLAT_LEND
            "  clki," __PLAT_LEND "  signi," __PLAT_LEND "  signo" __PLAT_LEND
            ");" __PLAT_LEND "input  rstn;" __PLAT_LEND
            "input  clki;" __PLAT_LEND "input  signi;" __PLAT_LEND
            "output signo;" __PLAT_LEND __PLAT_LEND "reg [1:0] sync;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(
        fp, "reg reg_signo;" __PLAT_LEND
            "always @(posedge clki or negedge rstn)" __PLAT_LEND
            "begin" __PLAT_LEND "    if(!rstn)" __PLAT_LEND
            "        sync[1:0] <= {2{1'b0}};" __PLAT_LEND "    else" __PLAT_LEND
            "        sync[1:0] <= {sync[0], signi};" __PLAT_LEND
            "end" __PLAT_LEND __PLAT_LEND
            "always @(posedge clki or negedge rstn)" __PLAT_LEND
            "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else");
    cgraph_file_fprintfln(fp,
                          "        signs[%ld:0] <= {signs[%ld:0], "
                          "sync[1]};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp,
                          "end" __PLAT_LEND __PLAT_LEND
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)" __PLAT_LEND
                          "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1,
                          len);
    cgraph_file_fprintfln(
        fp,
        "        reg_signo <= 1'b1;" __PLAT_LEND "end" __PLAT_LEND __PLAT_LEND
        "assign signo = reg_signo;" __PLAT_LEND __PLAT_LEND "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_simple(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1;
    cgraph_file_fprintfln(fp,
                          "module sync (" __PLAT_LEND "  rstn," __PLAT_LEND
                          "  clki," __PLAT_LEND "  signi," __PLAT_LEND
                          "  signo" __PLAT_LEND ");" __PLAT_LEND
                          "input  rstn;" __PLAT_LEND "input  clki;" __PLAT_LEND
                          "input  signi;" __PLAT_LEND "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(fp,
                          "reg         sign_last;" __PLAT_LEND __PLAT_LEND
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" __PLAT_LEND "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len - 2);
    cgraph_file_fprintfln(fp,
                          "    end" __PLAT_LEND "end" __PLAT_LEND __PLAT_LEND
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)" __PLAT_LEND
                          "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1,
                          len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b1;" __PLAT_LEND
                              "end" __PLAT_LEND __PLAT_LEND "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_edgedet(FILE *fp) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_file_fprintfln(
        fp, "module edgedect (" __PLAT_LEND "  rstn," __PLAT_LEND
            "  clki," __PLAT_LEND "  signi," __PLAT_LEND "  signp," __PLAT_LEND
            "  signn" __PLAT_LEND ");" __PLAT_LEND "input  rstn;" __PLAT_LEND
            "input  clki;" __PLAT_LEND "input  signi;" __PLAT_LEND
            "output signp;" __PLAT_LEND "output signn;" __PLAT_LEND __PLAT_LEND
            "reg [2:0] signs;");
    cgraph_file_fprintfln(
        fp, "always @(posedge clki or negedge rstn)" __PLAT_LEND
            "begin" __PLAT_LEND "    if(!rstn)" __PLAT_LEND
            "      signs[2:0] <= {3{1'b0}};" __PLAT_LEND "    else" __PLAT_LEND
            "      signs[2:0] <= {signs[1:0], signi};" __PLAT_LEND
            "end" __PLAT_LEND __PLAT_LEND
            "assign signp = (~signs[2] & sign[1]);" __PLAT_LEND
            "assign signn = (signs[2] & ~sign[1]);" __PLAT_LEND __PLAT_LEND
            "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_handshake(FILE *fp) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                                  const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
    cgraph_file_fprintfln(fp, "module fifo (" __PLAT_LEND "  rstn," __PLAT_LEND
                              "  clk," __PLAT_LEND "  write," __PLAT_LEND
                              "  read," __PLAT_LEND "  big," __PLAT_LEND
                              "  din," __PLAT_LEND "  dout" __PLAT_LEND ");");
    cgraph_file_fprintfln(fp,
                          "input  rstn;" __PLAT_LEND "input  clki;" __PLAT_LEND
                          "input  write;" __PLAT_LEND "input  read;" __PLAT_LEND
                          "input  big;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", vlen_1);
    cgraph_file_fprintfln(fp, "output [%ld:0] dout;" __PLAT_LEND, vlen_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_fifo;" __PLAT_LEND, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_shift(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module shift (" __PLAT_LEND "  rstn," __PLAT_LEND
                              "  clk," __PLAT_LEND "  write," __PLAT_LEND
                              "  read," __PLAT_LEND "  msb," __PLAT_LEND
                              "  din," __PLAT_LEND "  dout" __PLAT_LEND ");");
    cgraph_file_fprintfln(fp,
                          "input  rstn;" __PLAT_LEND "input  clki;" __PLAT_LEND
                          "input  write;" __PLAT_LEND "input  read;" __PLAT_LEND
                          "input  msb;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "output dout;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_shift;", len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_cnt;" __PLAT_LEND, len_1);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if(read)");
    cgraph_file_fprintfln(
        fp,
        "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, "
        "1'b1};",
        len_1, len_1, len_1);
    cgraph_file_fprintfln(fp,
                          "end" __PLAT_LEND __PLAT_LEND
                          "always @(posedge clki or negedge rstn)" __PLAT_LEND
                          "begin" __PLAT_LEND "    if(!rstn)");
    cgraph_file_fprintfln(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if(write)" __PLAT_LEND
                              "    begin" __PLAT_LEND "        if(msb)");
    cgraph_file_fprintfln(fp, "            reg_shift[%ld:0] <= din[%ld:0];",
                          len_1, len_1);
    cgraph_file_fprintfln(fp, "        else");
    cgraph_file_fprintf(fp, "            reg_shift[%ld:0] <= {din[0]", len_1);
    CGRAPH_LOOP(i, 1, len)
    cgraph_file_fprintf(fp, ", din[%ld]", i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "};" __PLAT_LEND "    end" __PLAT_LEND
                              "    else if(read)");
    cgraph_file_fprintfln(fp,
                          "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
                          "1'b0};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "end");
    cgraph_file_fprintfln(fp, "assign dout = reg_shift[%ld];" __PLAT_LEND,
                          len_1);
    cgraph_file_fprintfln(fp, "endmodule");
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_crc(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module crc (" __PLAT_LEND "  rstn," __PLAT_LEND
                              "  clk," __PLAT_LEND "  write," __PLAT_LEND
                              "  read," __PLAT_LEND "  msb," __PLAT_LEND
                              "  din," __PLAT_LEND "  poly" __PLAT_LEND
                              "  dout" __PLAT_LEND ");");
    cgraph_file_fprintfln(fp,
                          "input  rstn;" __PLAT_LEND "input  clki;" __PLAT_LEND
                          "input  write;" __PLAT_LEND "input  read;" __PLAT_LEND
                          "input  msb;");
    cgraph_file_fprintfln(fp, "input   [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "input   [%ld:0] poly;", len_1);
    cgraph_file_fprintfln(fp, "output  [%ld:0] dout;" __PLAT_LEND, len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_crc;" __PLAT_LEND, len_1);
    cgraph_file_fprintf(fp,
                        "always @(posedge clki or negedge rstn)" __PLAT_LEND
                        "begin" __PLAT_LEND "    if(!rstn)" __PLAT_LEND
                        "        reg_crc[%ld:0] <= {%ld{1'b1}};" __PLAT_LEND
                        "    else if(write)" __PLAT_LEND "    begin" __PLAT_LEND
                        "        if(msb)" __PLAT_LEND
                        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
                        "din[%ld:0];" __PLAT_LEND "        else" __PLAT_LEND
                        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
                        "{din[0]",
                        len_1, len, len_1, len_1, len_1, len_1, len_1);
    CGRAPH_LOOP(i, 1, len)
    cgraph_file_fprintf(fp, ", din[%ld]", i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "};" __PLAT_LEND "    end");
    cgraph_file_fprintfln(fp,
                          "    else" __PLAT_LEND
                          "        reg_crc[%ld:0] <= ({reg_crc[%ld:0], 1'b0} ^ "
                          "{%ld{reg_crc[%ld]}}) & poly[%ld:0];" __PLAT_LEND
                          "end" __PLAT_LEND,
                          len_1, len_2, len, len_1, len_1);
    cgraph_file_fprintfln(fp,
                          "assign dout[%ld:0] = (read ? reg_crc[%ld:0] : "
                          "{%ld{1'b0}});" __PLAT_LEND __PLAT_LEND "endmodule",
                          len_1, len_1, len);
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_file_fprintfln(fp, "`timescale 1ns/1ps" __PLAT_LEND __PLAT_LEND
                              "module tbench();" __PLAT_LEND
                              "reg clk;" __PLAT_LEND "reg rstn;");
    cgraph_file_fprintfln(
        fp, "always @(*)" __PLAT_LEND "begin" __PLAT_LEND
            "    if(!rstn)" __PLAT_LEND "      clk = 1'b0;" __PLAT_LEND
            "    else" __PLAT_LEND "      #50 clk = ~clk;" __PLAT_LEND
            "end" __PLAT_LEND);
    cgraph_file_fprintfln(
        fp,
        "initial" __PLAT_LEND "begin" __PLAT_LEND "    rstn = 1'b0;" __PLAT_LEND
        "    #100 rstn = 1'b1;" __PLAT_LEND "    #%ld rstn = 1'b0;" __PLAT_LEND
        "    #100 $finish;" __PLAT_LEND "end" __PLAT_LEND,
        delay_time);
    cgraph_file_fprintfln(fp, "endmodule");
  }

  return flag;
}
