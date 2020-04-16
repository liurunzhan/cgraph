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

// #include "data_templete.h"

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_TIME_H_ */