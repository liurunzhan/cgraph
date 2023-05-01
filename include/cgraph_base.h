/**
 * @file cgraph_base.h
 * @brief the basic data type apis
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_BASE_H__
#define __CGRAPH_BASE_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __CGRAPH_H__
#error cannot be both included with <cgraph.h>, because all files have been included in both files
#endif

#include "cgraph_error.h"
#include "cgraph_file.h"
#include "cgraph_hash.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"
#include "cgraph_rand.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BASE_H__ */
