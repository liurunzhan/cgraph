/**
 * @file cgraph_snode.h
 * @brief the apis of snode in STRUCTURE TYPE
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_SNODE_H_
#define _CGRAPH_SNODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct {
  struct cgraph_snode1_t *p1;
  void *data;
} cgraph_snode1_t;

extern cgraph_snode1_t *cgraph_snode1_calloc(void);
extern void cgraph_snode1_free(cgraph_snode1_t *cthis);

typedef struct {
  struct cgraph_snode2_t *p1, *p2;
  void *data;
} cgraph_snode2_t;

extern cgraph_snode2_t *cgraph_snode2_calloc(void);
extern void cgraph_snode2_free(cgraph_snode2_t *cthis);

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_SNODE_H_ */
