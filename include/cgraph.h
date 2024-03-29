/**
 * @mainpage cgraph
 *                                          _
 *                                         | |
 *                 ___ __ _ _ __ __ _ _ __ | |__
 *                / __/ _` | '__/ _` | '_ \| '_ \
 *               | (_| (_| | | | (_| | |_) | | | |
 *                \___\__, |_|  \__,_| .__/|_| |_|
 *                     __/ |         | |
 *                    |___/          |_|
 * <table>
 * <tr><th>Project <td> cgraph
 * <tr><th>Author  <td> Liu Runzhan
 * <tr><th>Version <td> 0.0.0
 * <tr><th>Github  <td> https://github.com/liurunzhan/cgraph
 * <tr><th>Email   <td> liurunzhan@sina.com
 * </table>
 * @section Overview
 * This library is used to solve the graph and mathematical problems.
 * @section Description
 *
 * @section Usage
 *
 * @section Declearation
 *
 */

#ifndef __CGRAPH_H__
#define __CGRAPH_H__

#ifdef __cplusplus
extern "C" {
#endif

/** used to clear common-defined macro variables, except included only */
#ifndef __CGRAPH_MACRO_CFLAG__
#define __CGRAPH_MACRO_CFLAG__
#endif

/** object types */
#include "cgraph_gobject.h"
#include "cgraph_hobject.h"
#include "cgraph_m3object.h"
#include "cgraph_mobject.h"
#include "cgraph_object.h"

/** data and structure types */
#include "cgraph_data.h"
#include "cgraph_struct.h"

#include "cgraph_error.h"
#include "cgraph_file.h"
#include "cgraph_game.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"
#include "cgraph_rand.h"
#include "cgraph_version.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_H__ */
