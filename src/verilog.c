#include "cgraph_math.h"
#include "cgraph_verilog.h"

void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len) {
  if ((NULL != fp) && (!ferror(fp))) {
    cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                     len_1 = len - 1;
    fprintf(fp, "module clkgen (" CGRAPH_PLAT_NLINE "   rstn," CGRAPH_PLAT_NLINE
                "   clki," CGRAPH_PLAT_NLINE "   cnten," CGRAPH_PLAT_NLINE
                "   clken," CGRAPH_PLAT_NLINE "   br," CGRAPH_PLAT_NLINE
                "   clko" CGRAPH_PLAT_NLINE ");" CGRAPH_PLAT_NLINE
                "input              rstn;" CGRAPH_PLAT_NLINE
                "input              clki;" CGRAPH_PLAT_NLINE
                "input              cnten;" CGRAPH_PLAT_NLINE
                "input              clken;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "input      [%ld:0] br;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "output reg         clko;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] clk_cnt;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            max_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "      clk_cnt <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE, max);
    fprintf(fp, "    else if(cnten)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "      clk_cnt <= (clk_cnt + %ld'b1);" CGRAPH_PLAT_NLINE, max);
    fprintf(fp,
            "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
            "always @(*)" CGRAPH_PLAT_NLINE "  begin" CGRAPH_PLAT_NLINE
            "    if(clken)" CGRAPH_PLAT_NLINE "      begin" CGRAPH_PLAT_NLINE
            "        case(dr)" CGRAPH_PLAT_NLINE);
    for (i = 0; i < max; i++) {
      fprintf(fp, "        %ld : clko = clk_cnt[%ld];" CGRAPH_PLAT_NLINE, i, i);
    }
    fprintf(fp,
            "        default : clko = 1'bx;" CGRAPH_PLAT_NLINE
            "        endcase" CGRAPH_PLAT_NLINE "      end" CGRAPH_PLAT_NLINE
            "    else" CGRAPH_PLAT_NLINE "      clko = 1'b0;" CGRAPH_PLAT_NLINE
            "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
            "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    fprintf(fp,
            "module sync (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
            "  clki," CGRAPH_PLAT_NLINE "  signi," CGRAPH_PLAT_NLINE
            "  signo" CGRAPH_PLAT_NLINE ");" CGRAPH_PLAT_NLINE
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  signi;" CGRAPH_PLAT_NLINE
            "output signo;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE, len_1,
            len);
    fprintf(fp, "    else" CGRAPH_PLAT_NLINE "      begin" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_NLINE,
            len_1, len_2);
    fprintf(fp, "      end" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "assign signo = signs[%ld];" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1, len_2 = len - 2;
    fprintf(fp,
            "module sync (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
            "  clki," CGRAPH_PLAT_NLINE "  signi," CGRAPH_PLAT_NLINE
            "  signo" CGRAPH_PLAT_NLINE ");" CGRAPH_PLAT_NLINE
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  signi;" CGRAPH_PLAT_NLINE
            "output signo;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
            "reg [1:0] sync;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "reg reg_signo;" CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE
                "        sync[1:0] <= {2{1'b0}};" CGRAPH_PLAT_NLINE
                "    else" CGRAPH_PLAT_NLINE
                "        sync[1:0] <= {sync[0], signi};" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "        signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE, len_1,
            len);
    fprintf(fp, "    else" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "        signs[%ld:0] <= {signs[%ld:0], "
            "sync[1]};" CGRAPH_PLAT_NLINE,
            len_1, len_2);
    fprintf(fp, "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE
                "        reg_signo <= 1'b0;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1, len);
    fprintf(fp, "        reg_signo <= 1'b0;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1, len);
    fprintf(fp, "        reg_signo <= 1'b1;" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "assign signo = reg_signo;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1;
    fprintf(fp,
            "module sync (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
            "  clki," CGRAPH_PLAT_NLINE "  signi," CGRAPH_PLAT_NLINE
            "  signo" CGRAPH_PLAT_NLINE ");" CGRAPH_PLAT_NLINE
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  signi;" CGRAPH_PLAT_NLINE
            "output signo;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "reg         sign_last;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE, len_1,
            len);
    fprintf(fp, "    else" CGRAPH_PLAT_NLINE "      begin" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_NLINE,
            len_1, len - 2);
    fprintf(fp, "      end" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE
                "       sign_last <= 1'b0;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})" CGRAPH_PLAT_NLINE,
            len_1, len);
    fprintf(fp, "       sign_last <= 1'b0;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})" CGRAPH_PLAT_NLINE,
            len_1, len);
    fprintf(fp, "       sign_last <= 1'b1;" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_edgedet(FILE *fp) {
  if (NULL != fp && !ferror(fp)) {
    fprintf(fp,
            "module edgedect (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
            "  clki," CGRAPH_PLAT_NLINE "  signi," CGRAPH_PLAT_NLINE
            "  signp," CGRAPH_PLAT_NLINE "  signn" CGRAPH_PLAT_NLINE
            ");" CGRAPH_PLAT_NLINE "input  rstn;" CGRAPH_PLAT_NLINE
            "input  clki;" CGRAPH_PLAT_NLINE "input  signi;" CGRAPH_PLAT_NLINE
            "output signp;" CGRAPH_PLAT_NLINE
            "output signn;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
            "reg [2:0] signs;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE
                "      signs[2:0] <= {3{1'b0}};" CGRAPH_PLAT_NLINE
                "    else" CGRAPH_PLAT_NLINE
                "      signs[2:0] <= {signs[1:0], signi};" CGRAPH_PLAT_NLINE
                "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "assign signp = (~signs[2] & sign[1]);" CGRAPH_PLAT_NLINE
                "assign signn = (signs[2] & ~sign[1]);" CGRAPH_PLAT_NLINE
                    CGRAPH_PLAT_NLINE "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_handshake(FILE *fp) {}

void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                         const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
    fprintf(fp, "module fifo (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
                "  clk," CGRAPH_PLAT_NLINE "  write," CGRAPH_PLAT_NLINE
                "  read," CGRAPH_PLAT_NLINE "  big," CGRAPH_PLAT_NLINE
                "  din," CGRAPH_PLAT_NLINE "  dout" CGRAPH_PLAT_NLINE
                ");" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  write;" CGRAPH_PLAT_NLINE "input  read;" CGRAPH_PLAT_NLINE
            "input  big;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_NLINE, vlen_1);
    fprintf(fp, "output [%ld:0] dout;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            vlen_1);
    fprintf(fp, "reg [%ld:0] reg_fifo;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t i, len_1 = len - 1, len_2 = len - 2;
    fprintf(fp, "module shift (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
                "  clk," CGRAPH_PLAT_NLINE "  write," CGRAPH_PLAT_NLINE
                "  read," CGRAPH_PLAT_NLINE "  msb," CGRAPH_PLAT_NLINE
                "  din," CGRAPH_PLAT_NLINE "  dout" CGRAPH_PLAT_NLINE
                ");" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  write;" CGRAPH_PLAT_NLINE "input  read;" CGRAPH_PLAT_NLINE
            "input  msb;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "output dout;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] reg_shift;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "reg [%ld:0] reg_cnt;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE,
            len_1, len);
    fprintf(fp, "    else if(read)" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, "
            "1'b1};" CGRAPH_PLAT_NLINE,
            len_1, len_1, len_1);
    fprintf(fp, "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_NLINE,
            len_1, len);
    fprintf(fp, "    else if(write)" CGRAPH_PLAT_NLINE
                "      begin" CGRAPH_PLAT_NLINE
                "        if(msb)" CGRAPH_PLAT_NLINE);
    fprintf(fp, "            reg_shift[%ld:0] <= din[%ld:0];" CGRAPH_PLAT_NLINE,
            len_1, len_1);
    fprintf(fp, "        else" CGRAPH_PLAT_NLINE);
    fprintf(fp, "            reg_shift[%ld:0] <= {reg_shift[0]", len_1);
    for (i = 1; i < len; i++) {
      fprintf(fp, ", reg_shift[%ld]", i);
    }
    fprintf(fp, "};" CGRAPH_PLAT_NLINE "      end" CGRAPH_PLAT_NLINE
                "    else if(read)" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
            "1'b0};" CGRAPH_PLAT_NLINE,
            len_1, len_2);
    fprintf(fp, "  end" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "assign dout = reg_shift[%ld];" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len) {
  if (NULL != fp && !ferror(fp)) {
    cgraph_size_t len_1 = len - 1;
    fprintf(fp, "module crc (" CGRAPH_PLAT_NLINE "  rstn," CGRAPH_PLAT_NLINE
                "  clk," CGRAPH_PLAT_NLINE "  write," CGRAPH_PLAT_NLINE
                "  read," CGRAPH_PLAT_NLINE "  msb," CGRAPH_PLAT_NLINE
                "  din," CGRAPH_PLAT_NLINE "  dout" CGRAPH_PLAT_NLINE
                ");" CGRAPH_PLAT_NLINE);
    fprintf(fp,
            "input  rstn;" CGRAPH_PLAT_NLINE "input  clki;" CGRAPH_PLAT_NLINE
            "input  write;" CGRAPH_PLAT_NLINE "input  read;" CGRAPH_PLAT_NLINE
            "input  msb;" CGRAPH_PLAT_NLINE);
    fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_NLINE, len_1);
    fprintf(fp, "output dout;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE);
    fprintf(fp, "reg [%ld:0] reg_crc;" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE,
            len_1);
    fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_NLINE
                "  begin" CGRAPH_PLAT_NLINE "    if(!rstn)" CGRAPH_PLAT_NLINE
                "    else" CGRAPH_PLAT_NLINE "  end" CGRAPH_PLAT_NLINE
                "endmodule" CGRAPH_PLAT_NLINE);
  }
}

void cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time) {
  fprintf(fp, "`timescale 1ns/1ps" CGRAPH_PLAT_NLINE CGRAPH_PLAT_NLINE
              "module tbench();" CGRAPH_PLAT_NLINE "reg clk;" CGRAPH_PLAT_NLINE
              "reg rstn;" CGRAPH_PLAT_NLINE);
  fprintf(fp,
          "always @(*)" CGRAPH_PLAT_NLINE "  begin" CGRAPH_PLAT_NLINE
          "    if(!rstn)" CGRAPH_PLAT_NLINE
          "      clk = 1'b0;" CGRAPH_PLAT_NLINE "    else" CGRAPH_PLAT_NLINE
          "      #50 clk = ~clk;" CGRAPH_PLAT_NLINE "  end" CGRAPH_PLAT_NLINE);
  fprintf(fp,
          "initial" CGRAPH_PLAT_NLINE "  begin" CGRAPH_PLAT_NLINE
          "    rstn = 1'b0;" CGRAPH_PLAT_NLINE
          "    #100 rstn = 1'b1;" CGRAPH_PLAT_NLINE
          "    #%ld $finish;" CGRAPH_PLAT_NLINE "  end" CGRAPH_PLAT_NLINE,
          delay_time);
  fprintf(fp, "endmodule" CGRAPH_PLAT_NLINE);
}
