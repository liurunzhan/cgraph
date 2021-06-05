#include "cgraph_base.h"
#include "cgraph_float16.h"
#include "cgraph_int16.h"

#define TYPE_FLOAT16
#include "cgraph_template.h"

/** template module */
#include "template_float_soft.ct"

#include "cgraph_template_off.h"
