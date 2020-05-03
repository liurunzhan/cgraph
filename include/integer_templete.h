extern TYPE FUNCTION(NAME, gcd)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, lcm)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, and)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, or)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, not)(const TYPE x);
extern TYPE FUNCTION(NAME, xor)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, xnor)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, iszero)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismin)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismax)(const TYPE x);
extern cgraph_size_t FUNCTION(NAME, ones)(const TYPE x);