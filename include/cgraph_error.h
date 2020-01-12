#ifndef _CGRAPH_ERROR_H_
#define _CGRAPH_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define cgraph_error_print(reason) \
  cgraph_error((reason), (__LINE__), (__FILE__))

void cgraph_error(cgraph_char_t *reason, const cgraph_size_t line, cgraph_char_t *file);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_ERROR_H_ */