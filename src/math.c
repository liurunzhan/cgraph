#include <ctype.h>

#include "cgraph_math.h"
#include "cgraph_memory.h"

cgraph_uint_t cgraph_math_crc(const cgraph_uint_t predata,
                              const cgraph_uint_t data,
                              const cgraph_uint_t poly)
{
    cgraph_uint_t res = predata, temp = (data & res), ones = 0xFFFFFFFF,
                  msb = 0;
    cgraph_size_t i = 0, bits = 32;
    for (i = 0; i < bits; i++) {
        msb = ((res ^ temp) >> (bits - 1) & 0x01);
        if (msb == 0x01) {
            res = (((res << 1) ^ ones) & poly);
        } else {
            res = (res << 1);
        }
        temp = (temp << 1);
    }

    return res;
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data)
{
    return CGRAPH_TEST(isprint(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data)
{
    return CGRAPH_TEST(isalnum(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data)
{
    return CGRAPH_TEST(isalpha(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data)
{
    return CGRAPH_TEST(isupper(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_islower(const cgraph_char_t data)
{
    return CGRAPH_TEST(islower(data));
}

CGRAPH_INLINE cgraph_char_t cgraph_math_toupper(const cgraph_char_t data)
{
    return isupper(data) ? toupper(data) : MATH_ERROR;
}

CGRAPH_INLINE cgraph_char_t cgraph_math_tolower(const cgraph_char_t data)
{
    return islower(data) ? tolower(data) : MATH_ERROR;
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data)
{
    return CGRAPH_TEST(isspace(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data)
{
    return CGRAPH_TEST(CGRAPH_PLAT_PSPLIT_C == data);
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isnline(const cgraph_char_t data)
{
    return CGRAPH_TEST(CGRAPH_PLAT_NLINE_C == data);
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data)
{
    return CGRAPH_TEST(isdigit(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data)
{
    return CGRAPH_TEST(isxdigit(data));
}

cgraph_int_t cgraph_math_hex2dec(cgraph_char_t data, cgraph_bool_t *error)
{
    cgraph_int_t res = 0;
    if (NULL != error) {
        *error = CGRAPH_FALSE;
        switch (data) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            res = data - '0';
            break;
        }
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F': {
            res = data - 'A' + 10;
            break;
        }
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f': {
            res = data - 'a' + 10;
            break;
        }
        default: {
            *error = CGRAPH_TRUE;
            break;
        }
        }
    }

    return res;
}

static const cgraph_char_t __cgraph_math_dec2hex_upper__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data,
                                   cgraph_bool_t *error)
{
    cgraph_char_t ch = 0;
    if (NULL != error) {
        *error = CGRAPH_TRUE;
        if (data >= 0 && data < 16) {
            ch = __cgraph_math_dec2hex_upper__[data];
            *error = CGRAPH_FALSE;
        }
    }

    return ch;
}

static const cgraph_char_t __cgraph_math_dec2hex_lower__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data,
                                   cgraph_bool_t *error)
{
    cgraph_char_t ch = 0;
    if (NULL != error) {
        *error = CGRAPH_TRUE;
        if (data >= 0 && data < 16) {
            ch = __cgraph_math_dec2hex_lower__[data];
            *error = CGRAPH_FALSE;
        }
    }

    return ch;
}

cgraph_size_t cgraph_math_baseoflen(const cgraph_int_t data,
                                    const cgraph_int_t base)
{
    cgraph_size_t len = 0;
    cgraph_int_t new_data = data;
    while (0 != new_data) {
        new_data = new_data / base;
        len += 1;
    }

    return len;
}

cgraph_bool_t cgraph_math_prime(const cgraph_int_t data)
{
    cgraph_bool_t flag = CGRAPH_TRUE;
    cgraph_int_t tmp;
    if (2 > data) {
        flag = CGRAPH_FALSE;
    } else if ((2 == data) || (3 == data)) {
        flag = CGRAPH_TRUE;
    } else if ((1 != (tmp = (data % 6))) && (5 != tmp)) {
        flag = CGRAPH_FALSE;
    } else {
        cgraph_int_t root = sqrt(data), i;
        for (i = 5; i <= root; i += 6) {
            if ((0 == (data % i)) || (0 == (data % (i + 2)))) {
                flag = CGRAPH_FALSE;
                break;
            }
        }
    }

    return flag;
}

cgraph_size_t cgraph_math_primes(cgraph_int_t *primes, cgraph_int_t *isprime,
                                 const cgraph_int_t data)
{
    cgraph_size_t counter = 0;
    if ((NULL != primes) && (NULL != isprime) && (data > 1)) {
        cgraph_size_t i, j;
        for (i = 0; i < data; i++) {
            primes[i] = 0;
            isprime[i] = CGRAPH_TRUE;
        }
        for (i = 2; i < data; i++) {
            if (isprime[i] == CGRAPH_TRUE) {
                primes[counter++] = i;
            }
            for (j = 0; j < counter && i * primes[j] < data; j++) {
                isprime[i * primes[j]] = CGRAPH_FALSE;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }

    return counter;
}

static cgraph_int_t __cgraph_math_seed = 0;

void cgraph_random_seed(cgraph_int_t seed) { __cgraph_math_seed = seed; }

/**
        Author  : Park,  Miller
        Methode : X(n+1) <- (a * X(n) + b) % m
        a = 16807 or 48271
        m = 2147483647 (CGRAPH_RANDOM_MAX, 2^31 - 1 or 2 << 31 - 1)
        b = 0
        returning a 32bit integer [1, 2147483647]
        X(0) = 1
*/
cgraph_int_t cgraph_random(void)
{
    const cgraph_int_t a = 48271, m = CGRAPH_RANDOM_MAX;
    const cgraph_int_t m_div_a = m / a, m_mod_a = m % a;
    cgraph_int_t hi = __cgraph_math_seed / m_div_a,
                 lo = __cgraph_math_seed % m_div_a;
    __cgraph_math_seed = (a * lo - m_mod_a * hi);

    return __cgraph_math_seed;
}

cgraph_int_t cgraph_random_uniform(const cgraph_int_t min,
                                   const cgraph_int_t max)
{
    return cgraph_random() % (max - min) + min;
}

/*
        Authors : Box and Muller
        mu      : the average value of the normal distribution
        sigma   : the variance of the normal distribution
*/
cgraph_float64_t cgraph_random_normal(const cgraph_float64_t mu,
                                      const cgraph_float64_t sigma)
{
    static cgraph_float64_t U, V, Z;
    static cgraph_bool_t phase = CGRAPH_FALSE;
    if (!phase) {
        U = (1.0 * cgraph_random() + 1.0) / (CGRAPH_RANDOM_MAX + 2.0);
        V = 1.0 * cgraph_random() / (CGRAPH_RANDOM_MAX + 1.0);
        Z = sqrt(-2.0 * log(U)) * sin(2.0 * MATH_CONST_PI * V);
    } else {
        Z = sqrt(-2.0 * log(U)) * cos(2.0 * MATH_CONST_PI * V);
    }
    phase = CGRAPH_TRUE - phase;

    return Z * sigma + mu;
}

cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                  const cgraph_float64_t x)
{
    return log(x) / log(n);
}

CGRAPH_INLINE cgraph_int_t cgraph_math_pow2(const cgraph_int_t n)
{
    return (1 << n);
}

cgraph_int_t cgraph_math_log2(const cgraph_int_t x)
{
    cgraph_int_t res = 0, num = x;
    while (num > 1) {
        num = num >> 1;
        res++;
    }

    return res;
}

CGRAPH_INLINE cgraph_int_t cgraph_math_mod2(const cgraph_int_t x)
{
    return (x & 0x01);
}

CGRAPH_INLINE cgraph_int_t cgraph_math_bin2gray(const cgraph_int_t data)
{
    return (data ^ (data >> 1));
}

CGRAPH_INLINE cgraph_int_t cgraph_math_gray2bin(const cgraph_int_t data)
{
    return (data ^ (data << 1));
}

cgraph_int_t cgraph_math_pow(const cgraph_int_t x, const cgraph_int_t n)
{
    cgraph_int_t res = 1, _x = x, _n = n;
    while (_n != 0) {
        if (1 == (_n & 0x01)) {
            res *= _x;
        }
        _n = _n >> 1;
        _x *= _x;
    }

    return res;
}

cgraph_int_t cgraph_math_pow_mod(const cgraph_int_t x, const cgraph_int_t n,
                                 const cgraph_int_t mod)
{
    cgraph_int_t res = 1, _x = x, _n = n;
    while (_n != 0) {
        if (1 == (_n & 0x01)) {
            res = (res * _x) % mod;
        }
        _n = _n >> 1;
        _x = (_x * _x) % mod;
    }

    return res % mod;
}

cgraph_int_t cgraph_math_mul(const cgraph_int_t x, const cgraph_int_t y)
{
    cgraph_int_t res = 0, _x = x, _y = y;
    while (_y != 0) {
        if ((_y & 0x01) == 1) {
            res += _x;
        }
        _x = _x << 1;
        _y = _y >> 1;
    }

    return res;
}

cgraph_int_t cgraph_math_mul_mod(const cgraph_int_t x, const cgraph_int_t y,
                                 const cgraph_int_t mod)
{
    cgraph_int_t res = 0, _x = x, _y = y;
    while (_y != 0) {
        if ((_y & 0x01) == 1) {
            res = (res + _x) % mod;
        }
        _x = (_x << 1) % mod;
        _y = _y >> 1;
    }

    return res % mod;
}
