#include "cgraph_fraction.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

#define TYPE_FRACTION
#include "template.h"

/**/
#include "data_base.ct"

/**                               public apis                                 */
/*
  fnv-1a hash function (Fowler-Noll-Vo hash function, proposed by Glenn
  Fowler，Landon Curt Noll and Phong Vo in 1991): begin_of_algorithm hash =
  offset_basis for byte_of_data in data begin hash = hash ^ byte_of_data hash =
  hash * fnv_prime end return hash end_of_algorithm 32-bit offset_basis :
  2166136261 32-bit fnv_prime : 16777619 = 2^24 + 2^8 + 0x93 64-bit offset_basis
  : 14695981039346656037 64-bit fnv_prime : 1099511628211 = 2^40 + 2^8 + 0xb3
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis)
{
    cgraph_size_t hash = 2166136261UL;
    hash = (hash ^ FRACTION_NUM(cthis)) * 16777619UL;
    hash = ((hash >> 8) ^ FRACTION_DEN(cthis)) * 16777619UL;

    return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis)
{
    return CGRAPH_TEST(0 != FRACTION_DEN(cthis));
}

/**                              private apis                                 */
TYPE FUNCTION(NAME, initwnd)(const DATA_TYPE num, const DATA_TYPE den)
{
    TYPE res;
    FRACTION_NUM(res) = num;
    FRACTION_DEN(res) = den;

    return res;
}

TYPE FUNCTION(NAME, initwn)(const DATA_TYPE num)
{
    TYPE res;
    FRACTION_NUM(res) = num;
    FRACTION_DEN(res) = 1;

    return res;
}

TYPE FUNCTION(NAME, initwd)(const DATA_TYPE den)
{
    TYPE res;
    FRACTION_NUM(res) = 1;
    FRACTION_DEN(res) = den;

    return res;
}

cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE x)
{
    return CGRAPH_TEST((!FRACTION_NUM(x)) && (!FRACTION_DEN(x)));
}

cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE x)
{
    return CGRAPH_TEST(FRACTION_NUM(x) && (!FRACTION_DEN(x)));
}

cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE x)
{
    return CGRAPH_TEST((0 < FRACTION_NUM(x)) && (!FRACTION_DEN(x)));
}

cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE x)
{
    return CGRAPH_TEST((0 > FRACTION_NUM(x)) && (!FRACTION_DEN(x)));
}

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x)
{
    return CGRAPH_TEST((!FRACTION_NUM(x)) && FRACTION_DEN(x));
}

cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE x)
{
    return CGRAPH_TEST(FRACTION_NUM(x) * FRACTION_DEN(x) > 0);
}

cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE x)
{
    return CGRAPH_TEST(FRACTION_NUM(x) * FRACTION_DEN(x) < 0);
}

static const TYPE cgraph_fraction_min = MIN;

cgraph_bool_t FUNCTION(NAME, ismin)(const TYPE x)
{
    return CGRAPH_TEST(EQ(x, cgraph_fraction_min));
}

static const TYPE cgraph_fraction_max = MAX;

cgraph_bool_t FUNCTION(NAME, ismax)(const TYPE x)
{
    return CGRAPH_TEST(EQ(x, cgraph_fraction_max));
}

TYPE FUNCTION(NAME, addn)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) + FRACTION_DEN(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);

    return res;
}

TYPE FUNCTION(NAME, subn)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) - FRACTION_DEN(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);

    return res;
}

TYPE FUNCTION(NAME, muln)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);

    return res;
}

TYPE FUNCTION(NAME, divn)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;

    return res;
}

TYPE FUNCTION(NAME, pown)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                            ? FRACTION_NUM(x)
                            : (DATA_TYPE)pow(FRACTION_DEN(x), y);
    FRACTION_DEN(res) = FRACTION_DEN(x) == 1 ? FRACTION_DEN(x)
                                             : (DATA_TYPE)pow(FRACTION_DEN(x), y);

    return res;
}

TYPE FUNCTION(NAME, addd)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * y + FRACTION_DEN(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;

    return res;
}

TYPE FUNCTION(NAME, subd)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * y - FRACTION_DEN(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;

    return res;
}

TYPE FUNCTION(NAME, muld)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;

    return res;
}

TYPE FUNCTION(NAME, divd)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);

    return res;
}

TYPE FUNCTION(NAME, powd)(const TYPE x, const DATA_TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                            ? FRACTION_NUM(x)
                            : (DATA_TYPE)pow(FRACTION_DEN(x), 1.0 / y);
    FRACTION_DEN(res) = FRACTION_DEN(x) == 1
                            ? FRACTION_DEN(x)
                            : (DATA_TYPE)pow(FRACTION_DEN(x), 1.0 / y);

    return res;
}

TYPE FUNCTION(NAME, addf)(const TYPE x, const TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) =
        FRACTION_NUM(x) * FRACTION_DEN(y) + FRACTION_DEN(x) * FRACTION_NUM(y);
    FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

    return res;
}

TYPE FUNCTION(NAME, subf)(const TYPE x, const TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) =
        FRACTION_NUM(x) * FRACTION_DEN(y) - FRACTION_DEN(x) * FRACTION_NUM(y);
    FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

    return res;
}

TYPE FUNCTION(NAME, mulf)(const TYPE x, const TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
    FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

    return res;
}

TYPE FUNCTION(NAME, divf)(const TYPE x, const TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y);
    FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_NUM(y);

    return res;
}

TYPE FUNCTION(NAME, powf)(const TYPE x, const TYPE y)
{
    TYPE res;
    FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                            ? FRACTION_NUM(x)
                            : (DATA_TYPE)pow(FRACTION_DEN(x), FRACTION_VALUE(y));
    FRACTION_DEN(res) = FRACTION_DEN(x) == 1
                            ? FRACTION_DEN(x)
                            : (DATA_TYPE)pow(FRACTION_DEN(x), FRACTION_VALUE(y));

    return res;
}

TYPE FUNCTION(NAME, abs)(const TYPE x)
{
    TYPE res;
    FRACTION_NUM(res) = CGRAPH_ABS(FRACTION_NUM(x));
    FRACTION_DEN(res) = CGRAPH_ABS(FRACTION_DEN(x));

    return res;
}

#include "template_off.h"
