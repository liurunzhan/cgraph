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

#ifndef __CGRAPH_SNODE_H__
#define __CGRAPH_SNODE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct cgraph_snode1_t {
  struct cgraph_snode1_t *p1;
  void *data;
} cgraph_snode1_t;

extern cgraph_snode1_t *cgraph_snode1_calloc(void);
extern cgraph_snode1_t *cgraph_snode1_init(cgraph_snode1_t *cthis,
                                           cgraph_snode1_t *p1, void *data);
extern void cgraph_snode1_free(cgraph_snode1_t *cthis);
extern void *cgraph_snode1_data(const cgraph_snode1_t *cthis);
extern cgraph_snode1_t *cgraph_snode1_p1(const cgraph_snode1_t *cthis);

typedef struct cgraph_snode2_t {
  struct cgraph_snode2_t *p1, *p2;
  void *data;
} cgraph_snode2_t;

extern cgraph_snode2_t *cgraph_snode2_calloc(void);
extern cgraph_snode2_t *cgraph_snode2_init(cgraph_snode2_t *cthis,
                                           cgraph_snode2_t *p1,
                                           cgraph_snode2_t *p2, void *data);
extern void cgraph_snode2_free(cgraph_snode2_t *cthis);
extern void *cgraph_snode2_data(const cgraph_snode2_t *cthis);
extern cgraph_snode2_t *cgraph_snode2_p1(const cgraph_snode2_t *cthis);
extern cgraph_snode2_t *cgraph_snode2_p2(const cgraph_snode2_t *cthis);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_SNODE_H__ */
