#include "cgraph_memory.h"
#include "cgraph_snode.h"

cgraph_snode1_t *cgraph_snode1_calloc(void) {
  return cgraph_calloc(sizeof(cgraph_snode1_t));
}

cgraph_snode1_t *cgraph_snode1_init(cgraph_snode1_t *cthis, cgraph_snode1_t *p1,
                                    void *data) {
  if (NULL != cthis) {
    if (NULL != p1) {
      cthis->p1 = p1;
    }
    if (NULL != data) {
      cthis->data = data;
    }
  }

  return cthis;
}

void cgraph_snode1_free(cgraph_snode1_t *cthis) {
  if (NULL != cthis) {
    cgraph_free(cthis);
  }
}

__INLINE void *cgraph_snode1_data(const cgraph_snode1_t *cthis) {
  return NULL != cthis ? cthis->data : NULL;
}

__INLINE cgraph_snode1_t *cgraph_snode1_p1(const cgraph_snode1_t *cthis) {
  return NULL != cthis ? cthis->p1 : NULL;
}

cgraph_snode2_t *cgraph_snode2_calloc(void) {
  return cgraph_calloc(sizeof(cgraph_snode2_t));
}

cgraph_snode2_t *cgraph_snode2_init(cgraph_snode2_t *cthis, cgraph_snode2_t *p1,
                                    cgraph_snode2_t *p2, void *data) {
  if (NULL != cthis) {
    if (NULL != p1) {
      cthis->p1 = p1;
    }
    if (NULL != p2) {
      cthis->p2 = p2;
    }
    if (NULL != data) {
      cthis->data = data;
    }
  }

  return cthis;
}

void cgraph_snode2_free(cgraph_snode2_t *cthis) {
  if (NULL != cthis) {
    cgraph_free(cthis);
  }
}

__INLINE void *cgraph_snode2_data(const cgraph_snode2_t *cthis) {
  return NULL != cthis ? cthis->data : NULL;
}

__INLINE cgraph_snode2_t *cgraph_snode2_p1(const cgraph_snode2_t *cthis) {
  return NULL != cthis ? cthis->p1 : NULL;
}

__INLINE cgraph_snode2_t *cgraph_snode2_p2(const cgraph_snode2_t *cthis) {
  return NULL != cthis ? cthis->p2 : NULL;
}