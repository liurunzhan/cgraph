#include "cgraph_error.h"
#include "cgraph_math.h"
#include "cgraph_rand.h"

/** 32-bit integer random functions  */
static cgraph_uint32_t (*cgraph_rand32_intgen)(void) = cgraph_rand32_miller;

void cgraph_rand32_init(cgraph_uint32_t (*func)(void)) {
  if (NULL != func) {
    cgraph_rand32_intgen = func;
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_WARN,
                        "rand32 init handle is empty, use previous as default");
  }
#endif
}

static cgraph_uint32_t rand32_seed = UINT32_C(1);

void cgraph_rand32_srand(const cgraph_uint32_t seed) { rand32_seed = seed; }

cgraph_uint32_t cgraph_rand32_seed(void) { return rand32_seed; }

cgraph_uint32_t cgraph_rand32_rand(void) { return cgraph_rand32_intgen(); }

/**
 * @brief
 * Authors   : Park,  Miller
 * Method    : X(n+1) <- (a * X(n) + b) % m, where X(0) = 1
 * Arguments :
 * a = 16807 or 48271
 * b = 0
 * m = 2147483647 (RAND32_MAX = 2^31 - 1 or 2 << 31 - 1)
 * returning a 32-bit integer [1, 2147483647]
 */
#define MILLER_A UINT32_C(48271)
#define MILLER_B (0)
#define MILLER_M RAND32_MAX
cgraph_uint32_t cgraph_rand32_miller(void) {
  cgraph_int32_t hi = rand32_seed / (MILLER_M / MILLER_A),
                 lo = rand32_seed % (MILLER_M % MILLER_A);

  rand32_seed = (MILLER_A * lo - (MILLER_M % MILLER_A) * hi);

  return rand32_seed;
}
#undef MILLER_A
#undef MILLER_B
#undef MILLER_M

/**
 * @brief xorshift-32
 * Author    : Marsaglia
 * Method    : Xorshift Algorithm
 * Arguments :
 */
#define XORSHIFT_A (13)
#define XORSHIFT_B (17)
#define XORSHIFT_C (5)
cgraph_uint32_t cgraph_rand32_xorshift(void) {
  cgraph_uint32_t v = rand32_seed;
  v ^= (v << XORSHIFT_A);
  v ^= (v >> XORSHIFT_B);
  v ^= (v << XORSHIFT_C);

  return rand32_seed = v;
}
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C

/**
 * @brief mt19937-32
 * Authors   :
 * Method    : 32-bit Mersenne Twister Algorithm
 * Arguments :
 * (w, n, m, r) = (32, 624, 397, 31)
 * a = 0x9908B0DFU
 * f = 1812433253
 * (u, d) = (11, 0xFFFFFFFFU)
 * (s, b) = ( 7, 0x9D2C5680U)
 * (t, c) = (15, 0xEFC60000U)
 * l = 18
 */
#define MT19937 mt19937_32
#define MT19937_DSEED UINT32_C(997)
#define MT19937_SEED ((rand32_seed ? rand32_seed : MT19937_DSEED) & UINT32_MASK)
#define MT19937_TWIST(i, j)                                                    \
  ((MT19937[(i)] & UINT32_MSB) | (MT19937[(j)] & (~UINT32_MSB)))
#define MT19937_W (32)
#define MT19937_N (624)
#define MT19937_M (397)
#define MT19937_R (31)
#define MT19937_A UINT32_C(0x9908B0DF)
#define MT19937_F UINT32_C(1812433253)
#define MT19937_U (11)
#define MT19937_D UINT32_C(0xFFFFFFFF)
#define MT19937_S (7)
#define MT19937_B UINT32_C(0x9D2C5680)
#define MT19937_T (15)
#define MT19937_C UINT32_C(0xEFC60000)
#define MT19937_L (18)
#define MT19937_A_OR(y) ((UINT32_C(0x01) & (y)) ? MT19937_A : UINT32_C(0x00))

#if MT19937_M >= MT19937_N
#error MT19937 does not support that M is greater than or equal to N
#endif

static cgraph_uint32_t MT19937[MT19937_N];

void cgraph_rand32_mt19937_init(void) {
  MT19937[0] = MT19937_SEED;
  CGRAPH_LOOP(i, 1, MT19937_N)
  MT19937[i] =
      MT19937_F * ((MT19937[i - 1] ^ (MT19937[i - 1] >> (MT19937_W - 2))) +
                   (cgraph_uint32_t)i);
  CGRAPH_LOOP_END
}

cgraph_uint32_t cgraph_rand32_mt19937(void) {
  static cgraph_size_t index = MT19937_N;
  cgraph_uint32_t seed;
  if (MT19937_N <= index) {
    cgraph_uint32_t y;
    cgraph_size_t i;
    for (i = 0; i < (MT19937_N - MT19937_M); i++) {
      y = MT19937_TWIST(i, i + 1);
      MT19937[i] = MT19937[i + MT19937_M] ^ (y >> 1) ^ MT19937_A_OR(y);
    }
    for (; i < (MT19937_N - 1); i++) {
      y = MT19937_TWIST(i, i + 1);
      MT19937[i] =
          MT19937[i + MT19937_M - MT19937_N] ^ (y >> 1) ^ MT19937_A_OR(y);
    }
    y = MT19937_TWIST(i, 0);
    MT19937[i] = MT19937[MT19937_M - 1] ^ (y >> 1) ^ MT19937_A_OR(y);
    index = 0;
  }
  seed = MT19937[index];
  seed ^= (seed >> MT19937_U) & MT19937_D;
  seed ^= (seed << MT19937_S) & MT19937_B;
  seed ^= (seed << MT19937_T) & MT19937_C;
  seed ^= (seed >> MT19937_L);
  index++;

  return seed;
}
#undef MT19937
#undef MT19937_DSEED
#undef MT19937_SEED
#undef MT19937_TWIST
#undef MT19937_W
#undef MT19937_N
#undef MT19937_M
#undef MT19937_R
#undef MT19937_A
#undef MT19937_F
#undef MT19937_U
#undef MT19937_D
#undef MT19937_S
#undef MT19937_B
#undef MT19937_T
#undef MT19937_C
#undef MT19937_L
#undef MT19937_A_OR

cgraph_uint32_t cgraph_rand32_uniform(const cgraph_uint32_t min,
                                      const cgraph_uint32_t max) {
  return cgraph_rand32_intgen() % (max - min) + min;
}

/**
 * @brief
 * Authors   : Box and Muller
 * Method    : 32-bit Box-Muller Algorithm
 * Arguments :
 * mu        : the average value of the normal distribution
 * sigma     : the variance of the normal distribution
 */
cgraph_float32_t cgraph_rand32_normal(const cgraph_float32_t mu,
                                      const cgraph_float32_t sigma) {
  static volatile cgraph_float32_t U, V, Z;
  static volatile cgraph_bool_t phase = CGRAPH_FALSE;
  if (CGRAPH_FALSE == phase) {
    U = 1.0 * (cgraph_rand32_intgen() + 1) / (1.0 * RAND32_MAX + 2.0);
    V = 1.0 * cgraph_rand32_intgen() / (1.0 * RAND32_MAX + 1.0);
    Z = sqrt(-2.0 * log(U)) * sin(2.0 * M_PI * V);
  } else {
    Z = sqrt(-2.0 * log(U)) * cos(2.0 * M_PI * V);
  }
  phase = CGRAPH_TRUE - phase;

  return Z * sigma + mu;
}

/** 64-bit integer random functions  */
static cgraph_uint64_t (*cgraph_rand64_intgen)(void) = cgraph_rand64_mmix;

void cgraph_rand64_init(cgraph_uint64_t (*func)(void)) {
  if (NULL != func) {
    cgraph_rand64_intgen = func;
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_WARN,
                        "rand64 init handle is empty, use previous as default");
  }
#endif
}

static cgraph_uint64_t rand64_seed = UINT64_C(1);

void cgraph_rand64_srand(const cgraph_uint64_t seed) { rand64_seed = seed; }

cgraph_uint64_t cgraph_rand64_seed(void) { return rand64_seed; }

cgraph_uint64_t cgraph_rand64_rand(void) { return cgraph_rand64_intgen(); }

/**
 * @brief MMIX
 * Authors   : Donald Knuth
 * Method    : X(n+1) <- (a * X(n) + b) % m, where X(0) = 1
 * Arguments :
 * a = 6364136223846793005ULL
 * b = 1442695040888963407ULL
 * m = 18446744073709551615ULL
 * returning a 64-bit integer [1, 18446744073709551615ULL]
 */
#define MMIX_A UINT64_C(6364136223846793005)
#define MMIX_B UINT64_C(1442695040888963407)
#define MMIX_M UINT64_C(18446744073709551615)
cgraph_uint64_t cgraph_rand64_mmix(void) {
  rand64_seed = ((((MMIX_A % MMIX_M) * (rand64_seed % MMIX_M)) % MMIX_M +
                  (MMIX_B % MMIX_M)) %
                 MMIX_M);

  return rand64_seed;
}
#undef MMIX_A
#undef MMIX_B
#undef MMIX_M

/**
 * @brief xorshift-64
 */
#define XORSHIFT_A (13)
#define XORSHIFT_B (7)
#define XORSHIFT_C (17)
cgraph_uint64_t cgraph_rand64_xorshift(void) {
  cgraph_uint64_t v = rand64_seed;
  v ^= (v << XORSHIFT_A);
  v ^= (v >> XORSHIFT_B);
  v ^= (v << XORSHIFT_C);

  return rand64_seed = v;
}
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C

/**  */
#define XORSHIFT_A (12)
#define XORSHIFT_B (25)
#define XORSHIFT_C (27)
cgraph_uint64_t cgraph_rand64_xorshift64s(void) {
  cgraph_uint64_t x = rand64_seed;
  x ^= x >> XORSHIFT_A;
  x ^= x << XORSHIFT_B;
  x ^= x >> XORSHIFT_C;
  rand64_seed = x;
  return x * UINT64_C(0x2545F4914F6CDD1D);
}
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C

/**  */
#define XORSHIFT_A (23)
#define XORSHIFT_B (17)
#define XORSHIFT_C (26)

static cgraph_uint64_t xorshift_a = 0;
static cgraph_uint64_t xorshift_b = 0;

cgraph_uint64_t cgraph_rand64_xorshift128p(void) {
  cgraph_uint64_t t = xorshift_a;
  const cgraph_uint64_t s = xorshift_b;
  xorshift_a = s;
  t ^= t << XORSHIFT_A;
  t ^= t >> XORSHIFT_B;
  t ^= s ^ (s >> XORSHIFT_C);
  xorshift_b = t;
  return t + s;
}
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C

/**
 * @brief mt19937-64
 * Authers   :
 * Method    : 64-bit Mersenne Twister Algorithm
 * Arguments :
 * (w, n, m, r) = (64, 312, 156, 31)
 * a = 0xB5026F5AA96619E9ULL
 * f = 6364136223846793005ULL
 * (u, d) = (29, 0x5555555555555555ULL)
 * (s, b) = (17, 0x71D67FFFEDA60000ULL)
 * (t, c) = (37, 0xFFF7EEE000000000ULL)
 * l = 43
 */
#define MT19937 mt19937_64
#define MT19937_DSEED UINT64_C(99991)
#define MT19937_SEED ((rand64_seed ? rand64_seed : MT19937_DSEED) & UINT64_MASK)
#define MT19937_TWIST(i, j)                                                    \
  ((MT19937[(i)] & UINT64_MSB) | (MT19937[(j)] & (~UINT64_MSB)))
#define MT19937_W (64)
#define MT19937_N (312)
#define MT19937_M (156)
#define MT19937_R (31)
#define MT19937_A UINT64_C(0xB5026F5AA96619E9)
#define MT19937_F UINT64_C(6364136223846793005)
#define MT19937_U (29)
#define MT19937_D UINT64_C(0x5555555555555555)
#define MT19937_S (17)
#define MT19937_B UINT64_C(0x71D67FFFEDA60000)
#define MT19937_T (37)
#define MT19937_C UINT64_C(0xFFF7EEE000000000)
#define MT19937_L (43)
#define MT19937_A_OR(y) ((UINT64_C(0x01) & (y)) ? MT19937_A : UINT64_C(0x00))

#if MT19937_M >= MT19937_N
#error MT19937 does not support that M is greater than or equal to N
#endif

static cgraph_uint64_t MT19937[MT19937_N];

void cgraph_rand64_mt19937_init(void) {
  MT19937[0] = MT19937_SEED;
  CGRAPH_LOOP(i, 1, MT19937_N)
  MT19937[i] =
      MT19937_F * ((MT19937[i - 1] ^ (MT19937[i - 1] >> (MT19937_W - 2))) +
                   (cgraph_uint64_t)i);
  CGRAPH_LOOP_END
}

cgraph_uint64_t cgraph_rand64_mt19937(void) {
  static cgraph_size_t index = MT19937_N;
  cgraph_uint64_t seed;
  if (MT19937_N <= index) {
    cgraph_uint64_t y;
    cgraph_size_t i;
    for (i = 0; i < (MT19937_N - MT19937_M); i++) {
      y = MT19937_TWIST(i, i + 1);
      MT19937[i] = MT19937[i + MT19937_M] ^ (y >> 1) ^ MT19937_A_OR(y);
    }
    for (; i < (MT19937_N - 1); i++) {
      y = MT19937_TWIST(i, i + 1);
      MT19937[i] =
          MT19937[i + MT19937_M - MT19937_N] ^ (y >> 1) ^ MT19937_A_OR(y);
    }
    y = MT19937_TWIST(i, 0);
    MT19937[i] = MT19937[MT19937_M - 1] ^ (y >> 1) ^ MT19937_A_OR(y);
    index = 0;
  }
  seed = MT19937[index];
  seed ^= (seed >> MT19937_U) & MT19937_D;
  seed ^= (seed << MT19937_S) & MT19937_B;
  seed ^= (seed << MT19937_T) & MT19937_C;
  seed ^= (seed >> MT19937_L);
  index++;

  return seed;
}
#undef MT19937
#undef MT19937_DSEED
#undef MT19937_SEED
#undef MT19937_TWIST
#undef MT19937_W
#undef MT19937_N
#undef MT19937_M
#undef MT19937_R
#undef MT19937_A
#undef MT19937_F
#undef MT19937_U
#undef MT19937_D
#undef MT19937_S
#undef MT19937_B
#undef MT19937_T
#undef MT19937_C
#undef MT19937_L
#undef MT19937_A_OR

cgraph_uint64_t cgraph_rand64_uniform(const cgraph_uint64_t min,
                                      const cgraph_uint64_t max) {
  return cgraph_rand64_intgen() % (max - min) + min;
}

/**
 * @brief
 * Authors : Box and Muller
 * Method  : 64-bit Box-Muller Algorithm
 * mu      : the average value of the normal distribution
 * sigma   : the variance of the normal distribution
 */
cgraph_float64_t cgraph_rand64_normal(const cgraph_float64_t mu,
                                      const cgraph_float64_t sigma) {
  static volatile cgraph_float64_t U, V, Z;
  static volatile cgraph_bool_t phase = CGRAPH_FALSE;
  if (CGRAPH_FALSE == phase) {
    U = 1.0 * (cgraph_rand64_intgen() + 1) / (1.0 * RAND64_MAX + 2.0);
    V = 1.0 * cgraph_rand64_intgen() / (1.0 * RAND64_MAX + 1.0);
    Z = sqrt(-2.0 * log(U)) * sin(2.0 * M_PI * V);
  } else {
    Z = sqrt(-2.0 * log(U)) * cos(2.0 * M_PI * V);
  }
  phase = CGRAPH_TRUE - phase;

  return Z * sigma + mu;
}

cgraph_bool_t cgraph_rand_bool(void) {
  return cgraph_rand32_intgen() & CGRAPH_BOOL_MASK;
}

cgraph_logic_t cgraph_rand_logic(void) {
  return cgraph_rand32_intgen() & CGRAPH_LOGIC_MASK;
}

/** random size */
cgraph_size_t cgraph_rand_size(const cgraph_size_t size) {
#if __WORDSIZE == 64
  return cgraph_rand64_intgen() % size;
#else
  return cgraph_rand32_intgen() % size;
#endif
}