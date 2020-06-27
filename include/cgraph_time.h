#ifndef _CGRAPH_TIME_H_
#define _CGRAPH_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_TIME
#include "templete.h"

/*
  data[0] : year
  data[1] : month
  data[2] : day
  data[3] : hour
  data[4] : minute
  data[5] : second
*/ 
typedef struct {
  DATA_TYPE data[6];
}cgraph_time_t;

#define CGRAPH_YEAR(x) ((x).data[0])
#define CGRAPH_MONTH(x) ((x).data[1])
#define CGRAPH_DAY(x) ((x).data[2])
#define CGRAPH_HOUR(x) ((x).data[3])
#define CGRAPH_MINUTE(x) ((x).data[4])
#define CGRAPH_SECOND(x) ((x).data[5])

#include "data_templete.h"

extern cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, le)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addt)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, subt)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mult)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, divt)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep);
extern TYPE FUNCTION(NAME, localtime)(void);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_TIME_H_ */
