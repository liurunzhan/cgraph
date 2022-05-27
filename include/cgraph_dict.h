/**
 * @file cgraph_dict.h
 * @brief the apis of STRUCTURE TYPE cgraph_dict_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_DICT_H__
#define __CGRAPH_DICT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_snode.h"

#include "cgraph_template_off.h"
#define TYPE_DICT
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define NAME dict
#define TYPE TYPE_T(NAME)
#define ID ID_T(DICT)
#define ZERO NULL

/**
 * @struct cgraph_dict_t
 * @brief the object of dictory
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_PTR2
  CGRAPH_STRUCTURE_ROOT
} cgraph_dict_t;

/** template module */
#include "cgraph_template_struct.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_DICT_H__ */
