#include "cgraph_base.h"
#include "cgraph_verilog.h"

#ifndef LEND
#define LEND __PLAT_LEND
#endif

cgraph_size_t
cgraph_verilog_handshake_sampletime_min(const cgraph_size_t clk0_period,
                                        const cgraph_size_t clk1_period,
                                        const cgraph_size_t sync_cycle) {
  cgraph_size_t res = 0;
  if ((0 < clk0_period) && (0 < clk1_period) && (0 < sync_cycle)) {
    res = sync_cycle * clk0_period;
  }

  return res;
}

cgraph_size_t
cgraph_verilog_handshake_sampletime_max(const cgraph_size_t clk0_period,
                                        const cgraph_size_t clk1_period,
                                        const cgraph_size_t sync_cycle) {
  cgraph_size_t res = 0;
  if ((0 < clk0_period) && (0 < clk1_period) && (0 < sync_cycle)) {
    res = sync_cycle * (clk0_period + clk1_period);
  }

  return res;
}

cgraph_size_t
cgraph_verilog_handshake_samplecycle_min(const cgraph_float64_t clk0_freq,
                                         const cgraph_float64_t clk1_freq,
                                         const cgraph_size_t sync_cycle) {
  cgraph_size_t res = 0;
  if ((0.0 < clk0_freq) && (0.0 < clk1_freq) && (0 < sync_cycle)) {
    res = sync_cycle;
  }

  return res;
}

cgraph_size_t
cgraph_verilog_handshake_samplecycle_max(const cgraph_float64_t clk0_freq,
                                         const cgraph_float64_t clk1_freq,
                                         const cgraph_size_t sync_cycle) {
  cgraph_size_t res = 0;
  if ((0.0 < clk0_freq) && (0.0 < clk1_freq) && (0 < sync_cycle)) {
    res = sync_cycle *
          (1 + (cgraph_size_t)cgraph_math_ceil(clk0_freq / clk1_freq));
  }

  return res;
}

cgraph_bool_t cgraph_verilog_fsm_gray(FILE *fp, const cgraph_char_t *prefix,
                                      const cgraph_int_t states) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_char_t *state_prefix = "FSM_STATE";
    cgraph_int_t states_width = cgraph_math_abitlen(states);
    if (CGRAPH_ISSTR(prefix)) {
      state_prefix = (cgraph_char_t *)prefix;
    }
    CGRAPH_LOOP(i, 0, states)
    cgraph_file_fprintfln(fp, "localparam %s%d = %d'h%x;", state_prefix, i,
                          states_width, cgraph_math_bin2gray(i));
    CGRAPH_LOOP_END
    cgraph_file_fprintln(fp);
    cgraph_file_fprintfln(fp, "reg [%d:0] %s_curr_state;", states_width,
                          state_prefix);
    cgraph_file_fprintfln(fp, "reg [%d:0] %s_nxt_state;" LEND, states_width,
                          state_prefix);
    cgraph_file_fprintfln(
        fp, "always @(*)" LEND "begin" LEND "    case(%s_nxt_state)",
        state_prefix, state_prefix);
    CGRAPH_LOOP(i, 0, states)
    cgraph_file_fprintfln(fp, "        %s%d : begin  end", state_prefix, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : begin %s_nxt_state = %s0; end",
                          state_prefix, state_prefix);
    cgraph_file_fprintfln(fp, "    endcase" LEND "end" LEND);
    cgraph_file_fprintfln(fp,
                          "always @(posedge clk) begin" LEND
                          "    %s_curr_state <= %s_nxt_state;" LEND "end" LEND,
                          state_prefix, state_prefix);
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_clkgen_even(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2i(len), max_1 = max - 1,
                  len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen_even (" LEND "   rstn," LEND "   clki," LEND
        "   cnten," LEND "   clken," LEND "   br," LEND "   clko" LEND ");" LEND
        "input              rstn;" LEND "input              clki;" LEND
        "input              cnten;" LEND "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" LEND, max_1);
    cgraph_file_fprintfln(fp, "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if (cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end" LEND);
    cgraph_file_fprintfln(fp,
                          "always @(*)" LEND "begin" LEND "    if (clken)" LEND
                          "    begin" LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko = clk_cnt[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" LEND
                              "        endcase" LEND "    end" LEND
                              "    else" LEND "      clko = 1'b0;" LEND
                              "end" LEND LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_clkgen_odd(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2i(len), max_1 = max - 1,
                  len_1 = len - 1;
    cgraph_file_fprintfln(
        fp, "module clkgen_odd (" LEND "   rstn," LEND "   clki," LEND
            "   cnten," LEND "   clken," LEND "   br," LEND "   clko" LEND
            ");" LEND "input          rstn;" LEND "input          clki;" LEND
            "input          cnten;" LEND "input          clken;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_p;" LEND, max_1);
    cgraph_file_fprintfln(fp, "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if (cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_p <= (clk_cnt_p + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end" LEND);
    cgraph_file_fprintfln(fp, "reg clko_p;" LEND LEND "always @(*)" LEND
                              "begin" LEND "    if (clken)" LEND
                              "    begin" LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko_p = clk_cnt_p[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp,
                          "        default : clko_p = 1'bx;" LEND
                          "        endcase" LEND "    end" LEND "    else" LEND
                          "      clko_p = 1'b0;" LEND "end" LEND);
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt_n;" LEND, max_1);
    cgraph_file_fprintfln(fp, "always @(negedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if (cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt_n <= (clk_cnt_n + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end" LEND);
    cgraph_file_fprintfln(fp, "reg clko_n;" LEND LEND "always @(*)" LEND
                              "begin" LEND "    if (clken)" LEND
                              "    begin" LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        0x%lx : clko_n = clk_cnt_n[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(
        fp,
        "        default : clko_n = 1'bx;" LEND "        endcase" LEND
        "    end" LEND "    else" LEND "      clko_n = 1'b0;" LEND
        "end" LEND LEND "assign clko = clko_p | clk_n;" LEND LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t max = cgraph_math_pow2i(len), max_1 = max - 1,
                  len_1 = len - 1;
    cgraph_file_fprintfln(
        fp,
        "module clkgen (" LEND "   rstn," LEND "   clki," LEND "   cnten," LEND
        "   clken," LEND "   br," LEND "   clko" LEND ");" LEND
        "input              rstn;" LEND "input              clki;" LEND
        "input              cnten;" LEND "input              clken;");
    cgraph_file_fprintfln(fp, "input      [%ld:0] br;", len_1);
    cgraph_file_fprintfln(fp, "output reg         clko;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] clk_cnt;" LEND, max_1);
    cgraph_file_fprintfln(fp, "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= {%ld{1'b0}};", max);
    cgraph_file_fprintfln(fp, "    else if (cnten)");
    cgraph_file_fprintfln(fp, "      clk_cnt <= (clk_cnt + %ld'b1);", max);
    cgraph_file_fprintfln(fp, "end" LEND);
    cgraph_file_fprintfln(fp,
                          "always @(*)" LEND "begin" LEND "    if (clken)" LEND
                          "    begin" LEND "        case(dr)");
    CGRAPH_LOOP(i, 0, max)
    cgraph_file_fprintfln(fp, "        'h%lx : clko = clk_cnt[%ld];", i, i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "        default : clko = 1'bx;" LEND
                              "        endcase" LEND "    end" LEND
                              "    else" LEND "      clko = 1'b0;" LEND
                              "end" LEND LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_sync(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module sync (" LEND "  rstn," LEND "  clki," LEND
                              "  signi," LEND "  signo" LEND ");" LEND
                              "input  rstn;" LEND "input  clki;" LEND
                              "input  signi;" LEND "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;" LEND, len_1);
    cgraph_file_fprintfln(fp, "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" LEND "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "    end" LEND "end");
    cgraph_file_fprintfln(fp, "assign signo = signs[%ld];" LEND, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_filter(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(
        fp, "module filter (" LEND "  rstn," LEND "  clki," LEND "  signi," LEND
            "  signo" LEND ");" LEND "input  rstn;" LEND "input  clki;" LEND
            "input  signi;" LEND "output signo;" LEND LEND "reg [1:0] sync;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(
        fp, "reg reg_signo;" LEND "always @(posedge clki or negedge rstn)" LEND
            "begin" LEND "    if (!rstn)" LEND
            "        sync[1:0] <= {2{1'b0}};" LEND "    else" LEND
            "        sync[1:0] <= {sync[0], signi};" LEND "end" LEND LEND
            "always @(posedge clki or negedge rstn)" LEND "begin" LEND
            "    if (!rstn)");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else");
    cgraph_file_fprintfln(fp,
                          "        signs[%ld:0] <= {signs[%ld:0], "
                          "sync[1]};",
                          len_1, len_2);
    cgraph_file_fprintfln(
        fp, "end" LEND LEND "always @(posedge clki or negedge rstn)" LEND
            "begin" LEND "    if (!rstn)" LEND "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if (signs[%ld:0] == {%ld{1'b0}})",
                          len_1, len);
    cgraph_file_fprintfln(fp, "        reg_signo <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if (signs[%ld:0] == {%ld{1'b1}})",
                          len_1, len);
    cgraph_file_fprintfln(fp,
                          "        reg_signo <= 1'b1;" LEND "end" LEND LEND
                          "assign signo = reg_signo;" LEND LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_simple(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1;
    cgraph_file_fprintfln(fp, "module simple (" LEND "  rstn," LEND
                              "  clki," LEND "  signi," LEND "  signo" LEND
                              ");" LEND "input  rstn;" LEND "input  clki;" LEND
                              "input  signi;" LEND "output signo;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] signs;", len_1);
    cgraph_file_fprintfln(fp, "reg         sign_last;" LEND LEND
                              "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "       signs[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else" LEND "    begin");
    cgraph_file_fprintfln(fp, "        signs[%ld:0] <= {signs[%ld:0], signi};",
                          len_1, len - 2);
    cgraph_file_fprintfln(fp, "    end" LEND "end" LEND LEND
                              "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)" LEND
                              "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if (signs[%ld:0] == {%ld{1'b0}})",
                          len_1, len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b0;");
    cgraph_file_fprintfln(fp, "    else if (signs[%ld:0] == {%ld{1'b1}})",
                          len_1, len);
    cgraph_file_fprintfln(fp, "       sign_last <= 1'b1;" LEND "end" LEND LEND
                              "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_edgedect(FILE *fp) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_file_fprintfln(
        fp, "module edgedect (" LEND "  rstn," LEND "  clki," LEND
            "  signi," LEND "  signp," LEND "  signn" LEND ");" LEND
            "input  rstn;" LEND "input  clki;" LEND "input  signi;" LEND
            "output signp;" LEND "output signn;" LEND LEND "reg [2:0] signs;");
    cgraph_file_fprintfln(
        fp, "always @(posedge clki or negedge rstn)" LEND "begin" LEND
            "    if (!rstn)" LEND "      signs[2:0] <= {3{1'b0}};" LEND
            "    else" LEND "      signs[2:0] <= {signs[1:0], signi};" LEND
            "end" LEND LEND "assign signp = (~signs[2] & sign[1]);" LEND
            "assign signn = (signs[2] & ~sign[1]);" LEND LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_handshake(FILE *fp) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_file_fprintfln(fp, "module handshake (");
    cgraph_file_fprintfln(fp, "  rstn1," LEND "  clk1," LEND "  sign1" LEND
                              "  rstn2," LEND "  clk2," LEND "  sign2" LEND);
    cgraph_file_fprintfln(fp, ");");
    cgraph_file_fprintfln(fp, "  input rsnt1;" LEND "  input clk1;" LEND LEND
                              "input sign1;" LEND "  input rstn2;" LEND
                              "  input clk2;" LEND "input sign1;" LEND LEND);
    cgraph_file_fprintfln(fp, "always @(posedge clk1 negedge rstn1)" LEND
                              "  begin" LEND "    if (!rstn1)" LEND
                              "    else" LEND "  end");
    cgraph_file_fprintfln(fp, "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                                  const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
    cgraph_file_fprintfln(fp, "module fifo (" LEND "  rstn," LEND "  clk," LEND
                              "  write," LEND "  read," LEND "  big," LEND
                              "  din," LEND "  dout" LEND ");");
    cgraph_file_fprintfln(fp, "input  rstn;" LEND "input  clki;" LEND
                              "input  write;" LEND "input  read;" LEND
                              "input  big;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", vlen_1);
    cgraph_file_fprintfln(fp, "output [%ld:0] dout;" LEND, vlen_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_fifo;" LEND, len_1);
    cgraph_file_fprintfln(fp, "always @(posedge clk negedge rstn)" LEND
                              "  begin" LEND "    if (!rstb)" LEND
                              "    else" LEND "  end");
    cgraph_file_fprintfln(fp, LEND "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_shift(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module shift (" LEND "  rstn," LEND "  clk," LEND
                              "  write," LEND "  read," LEND "  msb," LEND
                              "  din," LEND "  dout" LEND ");");
    cgraph_file_fprintfln(fp, "input  rstn;" LEND "input  clki;" LEND
                              "input  write;" LEND "input  read;" LEND
                              "input  msb;");
    cgraph_file_fprintfln(fp, "input  [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "output dout;");
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_shift;", len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_cnt;" LEND, len_1);
    cgraph_file_fprintfln(fp, "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if (read)");
    cgraph_file_fprintfln(
        fp,
        "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {%ld{1'b0}, "
        "1'b1};",
        len_1, len_1, len_1);
    cgraph_file_fprintfln(fp, "end" LEND LEND
                              "always @(posedge clki or negedge rstn)" LEND
                              "begin" LEND "    if (!rstn)");
    cgraph_file_fprintfln(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};", len_1,
                          len);
    cgraph_file_fprintfln(fp, "    else if (write)" LEND "    begin" LEND
                              "        if (msb)");
    cgraph_file_fprintfln(fp, "            reg_shift[%ld:0] <= din[%ld:0];",
                          len_1, len_1);
    cgraph_file_fprintfln(fp, "        else");
    cgraph_file_fprintf(fp, "            reg_shift[%ld:0] <= {din[0]", len_1);
    CGRAPH_LOOP(i, 1, len)
    cgraph_file_fprintf(fp, ", din[%ld]", i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "};" LEND "    end" LEND "    else if (read)");
    cgraph_file_fprintfln(fp,
                          "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
                          "1'b0};",
                          len_1, len_2);
    cgraph_file_fprintfln(fp, "end" LEND);
    cgraph_file_fprintfln(fp, "assign dout = reg_shift[%ld];" LEND, len_1);
    cgraph_file_fprintfln(fp, "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_crc(FILE *fp, const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    cgraph_file_fprintfln(fp, "module crc (" LEND "  rstn," LEND "  clk," LEND
                              "  write," LEND "  read," LEND "  msb," LEND
                              "  din," LEND "  poly" LEND "  dout" LEND ");");
    cgraph_file_fprintfln(fp, "input  rstn;" LEND "input  clki;" LEND
                              "input  write;" LEND "input  read;" LEND
                              "input  msb;");
    cgraph_file_fprintfln(fp, "input   [%ld:0] din;", len_1);
    cgraph_file_fprintfln(fp, "input   [%ld:0] poly;", len_1);
    cgraph_file_fprintfln(fp, "output  [%ld:0] dout;" LEND, len_1);
    cgraph_file_fprintfln(fp, "reg [%ld:0] reg_crc;" LEND, len_1);
    cgraph_file_fprintf(
        fp,
        "always @(posedge clki or negedge rstn)" LEND "begin" LEND
        "    if (!rstn)" LEND "        reg_crc[%ld:0] <= {%ld{1'b1}};" LEND
        "    else if (write)" LEND "    begin" LEND "        if (msb)" LEND
        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
        "din[%ld:0];" LEND "        else" LEND
        "            reg_crc[%ld:0] <= reg_crc[%ld:0] ^ "
        "{din[0]",
        len_1, len, len_1, len_1, len_1, len_1, len_1);
    CGRAPH_LOOP(i, 1, len)
    cgraph_file_fprintf(fp, ", din[%ld]", i);
    CGRAPH_LOOP_END
    cgraph_file_fprintfln(fp, "};" LEND "    end");
    cgraph_file_fprintfln(fp,
                          "    else" LEND
                          "        reg_crc[%ld:0] <= ({reg_crc[%ld:0], 1'b0} ^ "
                          "{%ld{reg_crc[%ld]}}) & poly[%ld:0];" LEND "end" LEND,
                          len_1, len_2, len, len_1, len_1);
    cgraph_file_fprintfln(fp,
                          "assign dout[%ld:0] = (read ? reg_crc[%ld:0] : "
                          "{%ld{1'b0}});" LEND LEND "endmodule",
                          len_1, len_1, len);
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_file_fprintfln(fp,
                          "`timescale 1ns/1ps" LEND LEND "module tbench();" LEND
                          "reg clk;" LEND "reg rstn;");
    cgraph_file_fprintfln(fp,
                          "always @(*)" LEND "begin" LEND "    if (!rstn)" LEND
                          "      clk = 1'b0;" LEND "    else" LEND
                          "      #50 clk = ~clk;" LEND "end" LEND);
    cgraph_file_fprintfln(fp,
                          "initial" LEND "begin" LEND "    rstn = 1'b0;" LEND
                          "    #100 rstn = 1'b1;" LEND
                          "    #%ld rstn = 1'b0;" LEND "    #100 $finish;" LEND
                          "end" LEND,
                          delay_time);
    cgraph_file_fprintfln(fp, "endmodule");
    flag = CGRAPH_TRUE;
  }

  return flag;
}

#ifdef LEND
#undef LEND
#endif
