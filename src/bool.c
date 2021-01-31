#include "cgraph_bool.h"
#include "cgraph_file.h"
#include "cgraph_memory.h"

#define TYPE_BOOL
#include "template.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

/*template module*/
#include "int_base.ct"

#include "template_off.h"
