#ifndef _CGRAPH_VERILOG_H_
#define _CGRAPH_VERILOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* To commemorate my two years to work in Integrated Circuit. */

#include "cgraph_config.h"

extern void cgraph_verilog_clkgen(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_sync(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_simple(FILE *fp, const cgraph_size_t len);
extern void cgraph_verilog_edgedet(FILE *fp);

/* test function in DEBUG mode and do not use in RELEASE mode */
extern void cgraph_verilog_test(void);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_VERILOG_H_ */