extern CGVTable STRUCT(NAME);

extern cgraph_type_t FUNCTION(NAME, type)(void);
extern cgraph_size_t FUNCTION(NAME, size)(void);
extern cgraph_size_t FUNCTION(NAME, msize)(void);
extern cgraph_size_t FUNCTION(NAME, dsize)(void);
extern cgraph_char_t *FUNCTION(NAME, name)(void);

extern void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size);
extern void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error);
extern void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size);
extern void FUNCTION(NAME, free)(void *cthis);

extern cgraph_size_t FUNCTION(NAME, hash)(const void *cthis);

extern void FUNCTION(NAME, ascsort)(void *cthis, const cgraph_size_t start, const cgraph_size_t end);
extern void FUNCTION(NAME, descsort)(void *cthis, const cgraph_size_t start, const cgraph_size_t end);

extern void *FUNCTION(NAME, add)(const void *x, const void *y);
extern void *FUNCTION(NAME, sub)(const void *x, const void *y);
extern void *FUNCTION(NAME, mul)(const void *x, const void *y);
extern void *FUNCTION(NAME, div)(const void *x, const void *y);