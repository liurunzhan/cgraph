#include "cgraph_file.h"
#include "cgraph_float128.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

#ifdef CGRAPH_WITH_FLOAT128

#define TYPE_FLOAT128
#include "template.h"

/**/
#include "float_base.ct"

#include "template_off.h"

#endif
