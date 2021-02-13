#include "cgraph_math.h"
#include "cgraph_verilog.h"

void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len)
{
    if ((NULL != fp) && (!ferror(fp))) {
        cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                         len_1 = len - 1;
        fprintf(fp,
                "module clkgen (" CGRAPH_PLAT_LEND "   rstn," CGRAPH_PLAT_LEND
                "   clki," CGRAPH_PLAT_LEND "   cnten," CGRAPH_PLAT_LEND
                "   clken," CGRAPH_PLAT_LEND "   br," CGRAPH_PLAT_LEND
                "   clko" CGRAPH_PLAT_LEND ");" CGRAPH_PLAT_LEND
                "input              rstn;" CGRAPH_PLAT_LEND
                "input              clki;" CGRAPH_PLAT_LEND
                "input              cnten;" CGRAPH_PLAT_LEND
                "input              clken;" CGRAPH_PLAT_LEND);
        fprintf(fp, "input      [%ld:0] br;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp,
                "output reg         clko;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] clk_cnt;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                max_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "      clk_cnt <= {%ld{1'b0}};" CGRAPH_PLAT_LEND, max);
        fprintf(fp, "    else if(cnten)" CGRAPH_PLAT_LEND);
        fprintf(fp, "      clk_cnt <= (clk_cnt + %ld'b1);" CGRAPH_PLAT_LEND,
                max);
        fprintf(fp,
                "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "always @(*)" CGRAPH_PLAT_LEND "  begin" CGRAPH_PLAT_LEND
                "    if(clken)" CGRAPH_PLAT_LEND "      begin" CGRAPH_PLAT_LEND
                "        case(dr)" CGRAPH_PLAT_LEND);
        for (i = 0; i < max; i++) {
            fprintf(fp, "        %ld : clko = clk_cnt[%ld];" CGRAPH_PLAT_LEND,
                    i, i);
        }
        fprintf(fp, "        default : clko = 1'bx;" CGRAPH_PLAT_LEND
                    "        endcase" CGRAPH_PLAT_LEND
                    "      end" CGRAPH_PLAT_LEND "    else" CGRAPH_PLAT_LEND
                    "      clko = 1'b0;" CGRAPH_PLAT_LEND
                    "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                    "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1, len_2 = len - 2;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                "  clki," CGRAPH_PLAT_LEND "  signi," CGRAPH_PLAT_LEND
                "  signo" CGRAPH_PLAT_LEND ");" CGRAPH_PLAT_LEND
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  signi;" CGRAPH_PLAT_LEND
                "output signo;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                len_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_LEND "      begin" CGRAPH_PLAT_LEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_LEND,
            len_1, len_2);
        fprintf(fp, "      end" CGRAPH_PLAT_LEND
                    "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp,
                "assign signo = signs[%ld];" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1, len_2 = len - 2;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                "  clki," CGRAPH_PLAT_LEND "  signi," CGRAPH_PLAT_LEND
                "  signo" CGRAPH_PLAT_LEND ");" CGRAPH_PLAT_LEND
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  signi;" CGRAPH_PLAT_LEND
                "output signo;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "reg [1:0] sync;" CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp,
                "reg reg_signo;" CGRAPH_PLAT_LEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND
                "        sync[1:0] <= {2{1'b0}};" CGRAPH_PLAT_LEND
                "    else" CGRAPH_PLAT_LEND
                "        sync[1:0] <= {sync[0], signi};" CGRAPH_PLAT_LEND
                "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "        signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_LEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], sync[1]};" CGRAPH_PLAT_LEND,
            len_1, len_2);
        fprintf(fp, "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                    "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                    "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND
                    "        reg_signo <= 1'b0;" CGRAPH_PLAT_LEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1, len);
        fprintf(fp, "        reg_signo <= 1'b0;" CGRAPH_PLAT_LEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1, len);
        fprintf(fp,
                "        reg_signo <= 1'b1;" CGRAPH_PLAT_LEND
                "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "assign signo = reg_signo;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                "  clki," CGRAPH_PLAT_LEND "  signi," CGRAPH_PLAT_LEND
                "  signo" CGRAPH_PLAT_LEND ");" CGRAPH_PLAT_LEND
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  signi;" CGRAPH_PLAT_LEND
                "output signo;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp,
                "reg         sign_last;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_LEND "      begin" CGRAPH_PLAT_LEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_LEND,
            len_1, len - 2);
        fprintf(fp, "      end" CGRAPH_PLAT_LEND
                    "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                    "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                    "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND
                    "       sign_last <= 1'b0;" CGRAPH_PLAT_LEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "       sign_last <= 1'b0;" CGRAPH_PLAT_LEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "       sign_last <= 1'b1;" CGRAPH_PLAT_LEND
                    "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                    "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_edgedet(FILE *fp)
{
    if (NULL != fp && !ferror(fp)) {
        fprintf(fp,
                "module edgedect (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                "  clki," CGRAPH_PLAT_LEND "  signi," CGRAPH_PLAT_LEND
                "  signp," CGRAPH_PLAT_LEND "  signn" CGRAPH_PLAT_LEND
                ");" CGRAPH_PLAT_LEND "input  rstn;" CGRAPH_PLAT_LEND
                "input  clki;" CGRAPH_PLAT_LEND "input  signi;" CGRAPH_PLAT_LEND
                "output signp;" CGRAPH_PLAT_LEND
                "output signn;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "reg [2:0] signs;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                    "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND
                    "      signs[2:0] <= {3{1'b0}};" CGRAPH_PLAT_LEND
                    "    else" CGRAPH_PLAT_LEND
                    "      signs[2:0] <= {signs[1:0], signi};" CGRAPH_PLAT_LEND
                    "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                    "assign signp = (~signs[2] & sign[1]);" CGRAPH_PLAT_LEND
                    "assign signn = (signs[2] & ~sign[1]);" CGRAPH_PLAT_LEND
                        CGRAPH_PLAT_LEND "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_handshake(FILE *fp) {}

void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                         const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
        fprintf(fp, "module fifo (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                    "  clk," CGRAPH_PLAT_LEND "  write," CGRAPH_PLAT_LEND
                    "  read," CGRAPH_PLAT_LEND "  big," CGRAPH_PLAT_LEND
                    "  din," CGRAPH_PLAT_LEND "  dout" CGRAPH_PLAT_LEND
                    ");" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  write;" CGRAPH_PLAT_LEND "input  read;" CGRAPH_PLAT_LEND
                "input  big;" CGRAPH_PLAT_LEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_LEND, vlen_1);
        fprintf(fp, "output [%ld:0] dout;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                vlen_1);
        fprintf(fp, "reg [%ld:0] reg_fifo;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t i, len_1 = len - 1, len_2 = len - 2;
        fprintf(fp, "module shift (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                    "  clk," CGRAPH_PLAT_LEND "  write," CGRAPH_PLAT_LEND
                    "  read," CGRAPH_PLAT_LEND "  msb," CGRAPH_PLAT_LEND
                    "  din," CGRAPH_PLAT_LEND "  dout" CGRAPH_PLAT_LEND
                    ");" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  write;" CGRAPH_PLAT_LEND "input  read;" CGRAPH_PLAT_LEND
                "input  msb;" CGRAPH_PLAT_LEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp, "output dout;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] reg_shift;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp, "reg [%ld:0] reg_cnt;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                len_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "    else if(read)" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, "
                "1'b1};" CGRAPH_PLAT_LEND,
                len_1, len_1, len_1);
        fprintf(fp,
                "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND);
        fprintf(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_LEND,
                len_1, len);
        fprintf(fp, "    else if(write)" CGRAPH_PLAT_LEND
                    "      begin" CGRAPH_PLAT_LEND
                    "        if(msb)" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "            reg_shift[%ld:0] <= din[%ld:0];" CGRAPH_PLAT_LEND,
                len_1, len_1);
        fprintf(fp, "        else" CGRAPH_PLAT_LEND);
        fprintf(fp, "            reg_shift[%ld:0] <= {reg_shift[0]", len_1);
        for (i = 1; i < len; i++) {
            fprintf(fp, ", reg_shift[%ld]", i);
        }
        fprintf(fp, "};" CGRAPH_PLAT_LEND "      end" CGRAPH_PLAT_LEND
                    "    else if(read)" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
                "1'b0};" CGRAPH_PLAT_LEND,
                len_1, len_2);
        fprintf(fp, "  end" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(
            fp,
            "assign dout = reg_shift[%ld];" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
            len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1;
        fprintf(fp, "module crc (" CGRAPH_PLAT_LEND "  rstn," CGRAPH_PLAT_LEND
                    "  clk," CGRAPH_PLAT_LEND "  write," CGRAPH_PLAT_LEND
                    "  read," CGRAPH_PLAT_LEND "  msb," CGRAPH_PLAT_LEND
                    "  din," CGRAPH_PLAT_LEND "  dout" CGRAPH_PLAT_LEND
                    ");" CGRAPH_PLAT_LEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_LEND "input  clki;" CGRAPH_PLAT_LEND
                "input  write;" CGRAPH_PLAT_LEND "input  read;" CGRAPH_PLAT_LEND
                "input  msb;" CGRAPH_PLAT_LEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_LEND, len_1);
        fprintf(fp, "output dout;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND);
        fprintf(fp, "reg [%ld:0] reg_crc;" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND,
                len_1);
        fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_LEND
                    "  begin" CGRAPH_PLAT_LEND "    if(!rstn)" CGRAPH_PLAT_LEND
                    "    else" CGRAPH_PLAT_LEND "  end" CGRAPH_PLAT_LEND
                    "endmodule" CGRAPH_PLAT_LEND);
    }
}

void cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time)
{
    fprintf(fp, "`timescale 1ns/1ps" CGRAPH_PLAT_LEND CGRAPH_PLAT_LEND
                "module tbench();" CGRAPH_PLAT_LEND "reg clk;" CGRAPH_PLAT_LEND
                "reg rstn;" CGRAPH_PLAT_LEND);
    fprintf(fp,
            "always @(*)" CGRAPH_PLAT_LEND "  begin" CGRAPH_PLAT_LEND
            "    if(!rstn)" CGRAPH_PLAT_LEND
            "      clk = 1'b0;" CGRAPH_PLAT_LEND "    else" CGRAPH_PLAT_LEND
            "      #50 clk = ~clk;" CGRAPH_PLAT_LEND "  end" CGRAPH_PLAT_LEND);
    fprintf(fp,
            "initial" CGRAPH_PLAT_LEND "  begin" CGRAPH_PLAT_LEND
            "    rstn = 1'b0;" CGRAPH_PLAT_LEND
            "    #100 rstn = 1'b1;" CGRAPH_PLAT_LEND
            "    #%ld $finish;" CGRAPH_PLAT_LEND "  end" CGRAPH_PLAT_LEND,
            delay_time);
    fprintf(fp, "endmodule" CGRAPH_PLAT_LEND);
}
