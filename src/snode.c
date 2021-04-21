#include "cgraph_memory.h"
#include "cgraph_snode.h"

cgraph_snode1_t *cgraph_snode1_calloc(void) {
  return cgraph_calloc(sizeof(cgraph_snode1_t));
}

void cgraph_snode1_free(cgraph_snode1_t *cthis) {
  if (NULL != cthis) {
    cgraph_free(cthis);
  }
}

cgraph_snode2_t *cgraph_snode2_calloc(void) {
  return cgraph_calloc(sizeof(cgraph_snode2_t));
}

void cgraph_snode2_free(cgraph_snode2_t *cthis) {
  if (NULL != cthis) {
    cgraph_free(cthis);
  }
}