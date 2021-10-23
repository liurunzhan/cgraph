/**
 * @file cgraph_verilog.h
 * @brief the verilog code generator
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_VERILOG_H__
#define __CGRAPH_VERILOG_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * learn more knowledge about software and hardware
 * know more ways to solve cross-field problems
 * work harder to catch more opportunities
 */
#include "cgraph_config.h"

extern cgraph_bool_t cgraph_verilog_clkgen_even(FILE *fp,
                                                const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_clkgen_odd(FILE *fp,
                                               const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_sync(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_filter(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_simple(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_edgedet(FILE *fp);
extern cgraph_bool_t cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen,
                                         const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_shift(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_crc(FILE *fp, const cgraph_size_t len);
extern cgraph_bool_t cgraph_verilog_tbench(FILE *fp,
                                           const cgraph_size_t delay_time);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_VERILOG_H__ */
