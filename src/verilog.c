#include "cgraph_math.h"
#include "cgraph_verilog.h"

void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len)
{
    if ((NULL != fp) && (!ferror(fp))) {
        cgraph_size_t i, max = cgraph_math_pow2(len), max_1 = max - 1,
                         len_1 = len - 1;
        fprintf(fp,
                "module clkgen (" CGRAPH_PLAT_FEND "   rstn," CGRAPH_PLAT_FEND
                "   clki," CGRAPH_PLAT_FEND "   cnten," CGRAPH_PLAT_FEND
                "   clken," CGRAPH_PLAT_FEND "   br," CGRAPH_PLAT_FEND
                "   clko" CGRAPH_PLAT_FEND ");" CGRAPH_PLAT_FEND
                "input              rstn;" CGRAPH_PLAT_FEND
                "input              clki;" CGRAPH_PLAT_FEND
                "input              cnten;" CGRAPH_PLAT_FEND
                "input              clken;" CGRAPH_PLAT_FEND);
        fprintf(fp, "input      [%ld:0] br;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp,
                "output reg         clko;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] clk_cnt;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                max_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "      clk_cnt <= {%ld{1'b0}};" CGRAPH_PLAT_FEND, max);
        fprintf(fp, "    else if(cnten)" CGRAPH_PLAT_FEND);
        fprintf(fp, "      clk_cnt <= (clk_cnt + %ld'b1);" CGRAPH_PLAT_FEND,
                max);
        fprintf(fp,
                "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "always @(*)" CGRAPH_PLAT_FEND "  begin" CGRAPH_PLAT_FEND
                "    if(clken)" CGRAPH_PLAT_FEND "      begin" CGRAPH_PLAT_FEND
                "        case(dr)" CGRAPH_PLAT_FEND);
        for (i = 0; i < max; i++) {
            fprintf(fp, "        %ld : clko = clk_cnt[%ld];" CGRAPH_PLAT_FEND,
                    i, i);
        }
        fprintf(fp, "        default : clko = 1'bx;" CGRAPH_PLAT_FEND
                    "        endcase" CGRAPH_PLAT_FEND
                    "      end" CGRAPH_PLAT_FEND "    else" CGRAPH_PLAT_FEND
                    "      clko = 1'b0;" CGRAPH_PLAT_FEND
                    "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                    "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1, len_2 = len - 2;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                "  clki," CGRAPH_PLAT_FEND "  signi," CGRAPH_PLAT_FEND
                "  signo" CGRAPH_PLAT_FEND ");" CGRAPH_PLAT_FEND
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  signi;" CGRAPH_PLAT_FEND
                "output signo;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                len_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_FEND "      begin" CGRAPH_PLAT_FEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_FEND,
            len_1, len_2);
        fprintf(fp, "      end" CGRAPH_PLAT_FEND
                    "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp,
                "assign signo = signs[%ld];" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1, len_2 = len - 2;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                "  clki," CGRAPH_PLAT_FEND "  signi," CGRAPH_PLAT_FEND
                "  signo" CGRAPH_PLAT_FEND ");" CGRAPH_PLAT_FEND
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  signi;" CGRAPH_PLAT_FEND
                "output signo;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "reg [1:0] sync;" CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp,
                "reg reg_signo;" CGRAPH_PLAT_FEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND
                "        sync[1:0] <= {2{1'b0}};" CGRAPH_PLAT_FEND
                "    else" CGRAPH_PLAT_FEND
                "        sync[1:0] <= {sync[0], signi};" CGRAPH_PLAT_FEND
                "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "        signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_FEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], sync[1]};" CGRAPH_PLAT_FEND,
            len_1, len_2);
        fprintf(fp, "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                    "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                    "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND
                    "        reg_signo <= 1'b0;" CGRAPH_PLAT_FEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})", len_1, len);
        fprintf(fp, "        reg_signo <= 1'b0;" CGRAPH_PLAT_FEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})", len_1, len);
        fprintf(fp,
                "        reg_signo <= 1'b1;" CGRAPH_PLAT_FEND
                "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "assign signo = reg_signo;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1;
        fprintf(fp,
                "module sync (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                "  clki," CGRAPH_PLAT_FEND "  signi," CGRAPH_PLAT_FEND
                "  signo" CGRAPH_PLAT_FEND ");" CGRAPH_PLAT_FEND
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  signi;" CGRAPH_PLAT_FEND
                "output signo;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] signs;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp,
                "reg         sign_last;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "       signs[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "    else" CGRAPH_PLAT_FEND "      begin" CGRAPH_PLAT_FEND);
        fprintf(
            fp,
            "        signs[%ld:0] <= {signs[%ld:0], signi};" CGRAPH_PLAT_FEND,
            len_1, len - 2);
        fprintf(fp, "      end" CGRAPH_PLAT_FEND
                    "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                    "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                    "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND
                    "       sign_last <= 1'b0;" CGRAPH_PLAT_FEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b0}})" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "       sign_last <= 1'b0;" CGRAPH_PLAT_FEND);
        fprintf(fp, "    else if(signs[%ld:0] == {%ld{1'b1}})" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "       sign_last <= 1'b1;" CGRAPH_PLAT_FEND
                    "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                    "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_edgedet(FILE *fp)
{
    if (NULL != fp && !ferror(fp)) {
        fprintf(fp,
                "module edgedect (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                "  clki," CGRAPH_PLAT_FEND "  signi," CGRAPH_PLAT_FEND
                "  signp," CGRAPH_PLAT_FEND "  signn" CGRAPH_PLAT_FEND
                ");" CGRAPH_PLAT_FEND "input  rstn;" CGRAPH_PLAT_FEND
                "input  clki;" CGRAPH_PLAT_FEND "input  signi;" CGRAPH_PLAT_FEND
                "output signp;" CGRAPH_PLAT_FEND
                "output signn;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "reg [2:0] signs;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                    "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND
                    "      signs[2:0] <= {3{1'b0}};" CGRAPH_PLAT_FEND
                    "    else" CGRAPH_PLAT_FEND
                    "      signs[2:0] <= {signs[1:0], signi};" CGRAPH_PLAT_FEND
                    "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                    "assign signp = (~signs[2] & sign[1]);" CGRAPH_PLAT_FEND
                    "assign signn = (signs[2] & ~sign[1]);" CGRAPH_PLAT_FEND
                        CGRAPH_PLAT_FEND "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_handshake(FILE *fp) {}

void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                         const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t vlen_1 = vlen - 1, len_1 = len - 1;
        fprintf(fp, "module fifo (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                    "  clk," CGRAPH_PLAT_FEND "  write," CGRAPH_PLAT_FEND
                    "  read," CGRAPH_PLAT_FEND "  big," CGRAPH_PLAT_FEND
                    "  din," CGRAPH_PLAT_FEND "  dout" CGRAPH_PLAT_FEND
                    ");" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  write;" CGRAPH_PLAT_FEND "input  read;" CGRAPH_PLAT_FEND
                "input  big;" CGRAPH_PLAT_FEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_FEND, vlen_1);
        fprintf(fp, "output [%ld:0] dout;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                vlen_1);
        fprintf(fp, "reg [%ld:0] reg_fifo;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t i, len_1 = len - 1, len_2 = len - 2;
        fprintf(fp, "module shift (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                    "  clk," CGRAPH_PLAT_FEND "  write," CGRAPH_PLAT_FEND
                    "  read," CGRAPH_PLAT_FEND "  msb," CGRAPH_PLAT_FEND
                    "  din," CGRAPH_PLAT_FEND "  dout" CGRAPH_PLAT_FEND
                    ");" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  write;" CGRAPH_PLAT_FEND "input  read;" CGRAPH_PLAT_FEND
                "input  msb;" CGRAPH_PLAT_FEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp, "output dout;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] reg_shift;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp, "reg [%ld:0] reg_cnt;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                len_1);
        fprintf(fp,
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "        reg_cnt[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "    else if(read)" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "        reg_cnt[%ld:0] <= reg_cnt[%ld:0] + {{%ld{1'b0}}, "
                "1'b1};" CGRAPH_PLAT_FEND,
                len_1, len_1, len_1);
        fprintf(fp,
                "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND);
        fprintf(fp, "        reg_shift[%ld:0] <= {%ld{1'b0}};" CGRAPH_PLAT_FEND,
                len_1, len);
        fprintf(fp, "    else if(write)" CGRAPH_PLAT_FEND
                    "      begin" CGRAPH_PLAT_FEND
                    "        if(msb)" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "            reg_shift[%ld:0] <= din[%ld:0];" CGRAPH_PLAT_FEND,
                len_1, len_1);
        fprintf(fp, "        else" CGRAPH_PLAT_FEND);
        fprintf(fp, "            reg_shift[%ld:0] <= {reg_shift[0]", len_1);
        for (i = 1; i < len; i++) {
            fprintf(fp, ", reg_shift[%ld]", i);
        }
        fprintf(fp, "};" CGRAPH_PLAT_FEND "      end" CGRAPH_PLAT_FEND
                    "    else if(read)" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "        reg_shift[%ld:0] <= {reg_shift[%ld:0], "
                "1'b0};" CGRAPH_PLAT_FEND,
                len_1, len_2);
        fprintf(fp, "  end" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(
            fp,
            "assign dout = reg_shift[%ld];" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
            len_1);
        fprintf(fp, "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len)
{
    if (NULL != fp && !ferror(fp)) {
        cgraph_size_t len_1 = len - 1;
        fprintf(fp, "module crc (" CGRAPH_PLAT_FEND "  rstn," CGRAPH_PLAT_FEND
                    "  clk," CGRAPH_PLAT_FEND "  write," CGRAPH_PLAT_FEND
                    "  read," CGRAPH_PLAT_FEND "  msb," CGRAPH_PLAT_FEND
                    "  din," CGRAPH_PLAT_FEND "  dout" CGRAPH_PLAT_FEND
                    ");" CGRAPH_PLAT_FEND);
        fprintf(fp,
                "input  rstn;" CGRAPH_PLAT_FEND "input  clki;" CGRAPH_PLAT_FEND
                "input  write;" CGRAPH_PLAT_FEND "input  read;" CGRAPH_PLAT_FEND
                "input  msb;" CGRAPH_PLAT_FEND);
        fprintf(fp, "input  [%ld:0] din;" CGRAPH_PLAT_FEND, len_1);
        fprintf(fp, "output dout;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND);
        fprintf(fp, "reg [%ld:0] reg_crc;" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND,
                len_1);
        fprintf(fp, "always @(posedge clki or negedge rstn)" CGRAPH_PLAT_FEND
                    "  begin" CGRAPH_PLAT_FEND "    if(!rstn)" CGRAPH_PLAT_FEND
                    "    else" CGRAPH_PLAT_FEND "  end" CGRAPH_PLAT_FEND
                    "endmodule" CGRAPH_PLAT_FEND);
    }
}

void cgraph_verilog_tbench(FILE *fp, const cgraph_size_t delay_time)
{
    fprintf(fp, "`timescale 1ns/1ps" CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND
                "module tbench();" CGRAPH_PLAT_FEND "reg clk;" CGRAPH_PLAT_FEND
                "reg rstn;" CGRAPH_PLAT_FEND);
    fprintf(fp,
            "always @(*)" CGRAPH_PLAT_FEND "  begin" CGRAPH_PLAT_FEND
            "    if(!rstn)" CGRAPH_PLAT_FEND
            "      clk = 1'b0;" CGRAPH_PLAT_FEND "    else" CGRAPH_PLAT_FEND
            "      #50 clk = ~clk;" CGRAPH_PLAT_FEND "  end" CGRAPH_PLAT_FEND);
    fprintf(fp,
            "initial" CGRAPH_PLAT_FEND "  begin" CGRAPH_PLAT_FEND
            "    rstn = 1'b0;" CGRAPH_PLAT_FEND
            "    #100 rstn = 1'b1;" CGRAPH_PLAT_FEND
            "    #%ld $finish;" CGRAPH_PLAT_FEND "  end" CGRAPH_PLAT_FEND,
            delay_time);
    fprintf(fp, "endmodule" CGRAPH_PLAT_FEND);
}
