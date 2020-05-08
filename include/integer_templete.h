extern cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis);

extern TYPE FUNCTION(NAME, gcd)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, lcm)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, and)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, or)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, not)(const TYPE x);
extern TYPE FUNCTION(NAME, xor)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, xnor)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, bit)(const TYPE x, const cgraph_size_t position);
extern TYPE FUNCTION(NAME, set)(const TYPE x, const cgraph_size_t position);
extern TYPE FUNCTION(NAME, clr)(const TYPE x, const cgraph_size_t position);
extern TYPE FUNCTION(NAME, bits)(const TYPE x, const cgraph_size_t from, const cgraph_size_t to);
extern TYPE FUNCTION(NAME, sets)(const TYPE x, const cgraph_size_t from, const cgraph_size_t to);
extern TYPE FUNCTION(NAME, clrs)(const TYPE x, const cgraph_size_t from, const cgraph_size_t to);
extern cgraph_boolean_t FUNCTION(NAME, iszero)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismin)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismax)(const TYPE x);
extern cgraph_size_t FUNCTION(NAME, ones)(const TYPE x);

extern TYPE FUNCTION(NAME, lsfr)(const TYPE data, const TYPE polynomial);
extern TYPE FUNCTION(NAME, crc)(const TYPE data, const TYPE polynomial);