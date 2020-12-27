#ifndef _CGRAPH_VERILOG_H_
#define _CGRAPH_VERILOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * learn more knowledge about software and hardware
 * know more ways to solve different fields of problems
 * work harder to catch more opportunities
 */
#include "cgraph_config.h"

extern void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_filter(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_edgedet(FILE *fp);
extern void cgraph_verilog_fifo(FILE *fp, const cgraph_size_t vlen, const cgraph_size_t len);
extern void cgraph_verilog_shift(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_crc(FILE *fp, const cgraph_size_t len);

/**test function in DEBUG mode and do not use in RELEASE mode */
extern void cgraph_verilog_test(void);

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_VERILOG_H_ */
