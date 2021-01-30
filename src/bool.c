#include "cgraph_bool.h"
#include "cgraph_file.h"
#include "cgraph_memory.h"

#define TYPE_BOOL
#include "template.h"

/*template module*/
#include "int_base.ct"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

cgraph_int_t FUNCTION(NAME, printf)(const TYPE x)
{
    return fprintf(stdout, "%s",
                   (CGRAPH_FALSE == x) ? __cgraph_false__ : __cgraph_true__);
}

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE x)
{
    return fprintf(fp, "%s",
                   (CGRAPH_FALSE == x) ? __cgraph_false__ : __cgraph_true__);
}

cgraph_int_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                      const cgraph_size_t size, const TYPE x)
{
    return cgraph_file_snprintf(buffer, size, "%s",
                                (CGRAPH_FALSE == x) ? __cgraph_false__
                                                    : __cgraph_true__);
}

#include "template_off.h"
