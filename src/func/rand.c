#include "cgraph_error.h"
#include "cgraph_math.h"
#include "cgraph_rand.h"

/** 32-bit integer random functions  */
#define CGRAPH_RAND32_DEFAULT cgraph_rand32_miller
static cgraph_uint32_t (*cgraph_rand32_intgen)(void) = CGRAPH_RAND32_DEFAULT;

void cgraph_rand32_init(cgraph_uint32_t (*func)(void)) {
  if (NULL == func) {
    goto CERROR;
  }
  cgraph_rand32_intgen = func;

CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_WARN,
                        "rand32 init handle is empty, use previous as default");
#endif
  cgraph_rand32_intgen = (NULL == cgraph_rand32_intgen) ? CGRAPH_RAND32_DEFAULT
                                                        : cgraph_rand32_intgen;
}

static volatile cgraph_uint32_t rand32_seed = UINT32_C(1);

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
 * m = 2147483647 (CGRAPH_UINT32_MAX = 2^31 - 1 or 2 << 31 - 1)
 * returning a 32-bit integer [1, 2147483647]
 */
cgraph_uint32_t cgraph_rand32_miller(void) {
#define MILLER_A UINT32_C(48271)
#define MILLER_B (0)
#define MILLER_M CGRAPH_UINT32_MAX
  cgraph_int32_t hi = rand32_seed / (MILLER_M / MILLER_A),
                 lo = rand32_seed % (MILLER_M % MILLER_A);

  rand32_seed = (MILLER_A * lo - (MILLER_M % MILLER_A) * hi);

  return rand32_seed;
#undef MILLER_A
#undef MILLER_B
#undef MILLER_M
}

/**
 * @brief xorshift-32
 * Author    : Marsaglia
 * Method    : Xorshift Algorithm
 * Arguments :
 */
cgraph_uint32_t cgraph_rand32_xorshift(void) {
#define XORSHIFT_A (13)
#define XORSHIFT_B (17)
#define XORSHIFT_C (5)
  cgraph_uint32_t v = rand32_seed;
  v ^= (v << XORSHIFT_A);
  v ^= (v >> XORSHIFT_B);
  v ^= (v << XORSHIFT_C);

  return (rand32_seed = v);
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C
}

/**
 * @brief 32-bit xoshiro-128 algorithm
 * Refered from https://prng.di.unimi.it
 */
#define XOSHIRO xoshiro128_32
#define XOSHIRO_BITS (32)
#define XOSHIRO_ROTL(x, bits) CGRAPH_ROTL(x, XOSHIRO_BITS, bits)

static cgraph_uint32_t XOSHIRO[4] = {UINT32_C(0), UINT32_C(0), UINT32_C(0),
                                     UINT32_C(0)};

void cgraph_rand32_xoshiro128_jump(cgraph_uint32_t (*xoshiro128)(void)) {
  static const cgraph_uint32_t jump[4] = {
      UINT32_C(0x8764000b), UINT32_C(0xf542d2d3), UINT32_C(0x6fa035c3),
      UINT32_C(0x77f2db5b)};
  cgraph_uint32_t states[4] = {UINT32_C(0), UINT32_C(0), UINT32_C(0),
                               UINT32_C(0)};
  CGRAPH_LOOP(i, 0, 4)
  CGRAPH_LOOP(j, 0, XOSHIRO_BITS)
  if (jump[i] & (UINT32_C(1) << j)) {
    states[0] ^= XOSHIRO[0];
    states[1] ^= XOSHIRO[1];
    states[2] ^= XOSHIRO[2];
    states[3] ^= XOSHIRO[3];
  }
  xoshiro128();
  CGRAPH_LOOP_END
  CGRAPH_LOOP_END

  XOSHIRO[0] = states[0];
  XOSHIRO[1] = states[1];
  XOSHIRO[2] = states[2];
  XOSHIRO[3] = states[3];
}

void cgraph_rand32_xoshiro128_longjmp(cgraph_uint32_t (*xoshiro128)(void)) {
  static const cgraph_uint32_t jump[4] = {
      UINT32_C(0xb523952e), UINT32_C(0xb523952e), UINT32_C(0xb523952e),
      UINT32_C(0x1c580662)};
  cgraph_uint32_t states[4] = {UINT32_C(0), UINT32_C(0), UINT32_C(0),
                               UINT32_C(0)};
  CGRAPH_LOOP(i, 0, 4)
  CGRAPH_LOOP(j, 0, XOSHIRO_BITS)
  if (jump[i] & (UINT32_C(1) << j)) {
    states[0] ^= XOSHIRO[0];
    states[1] ^= XOSHIRO[1];
    states[2] ^= XOSHIRO[2];
    states[3] ^= XOSHIRO[3];
  }
  xoshiro128();
  CGRAPH_LOOP_END
  CGRAPH_LOOP_END

  XOSHIRO[0] = states[0];
  XOSHIRO[1] = states[1];
  XOSHIRO[2] = states[2];
  XOSHIRO[3] = states[3];
}

cgraph_uint32_t cgraph_rand32_xoshiro128pp(void) {
  cgraph_uint32_t res = XOSHIRO_ROTL(XOSHIRO[0] + XOSHIRO[3], 7) + XOSHIRO[0];
  const uint64_t t = XOSHIRO[1] << 9;

  XOSHIRO[2] ^= XOSHIRO[0];
  XOSHIRO[3] ^= XOSHIRO[1];
  XOSHIRO[1] ^= XOSHIRO[2];
  XOSHIRO[0] ^= XOSHIRO[3];
  XOSHIRO[2] ^= t;
  XOSHIRO[3] = XOSHIRO_ROTL(XOSHIRO[3], 11);

  return res;
}

cgraph_uint32_t cgraph_rand32_xoshiro128ss(void) {
  cgraph_uint32_t res = XOSHIRO_ROTL(XOSHIRO[1] * 5, 7) * 9;
  const uint64_t t = XOSHIRO[1] << 9;

  XOSHIRO[2] ^= XOSHIRO[0];
  XOSHIRO[3] ^= XOSHIRO[1];
  XOSHIRO[1] ^= XOSHIRO[2];
  XOSHIRO[0] ^= XOSHIRO[3];
  XOSHIRO[2] ^= t;
  XOSHIRO[3] = XOSHIRO_ROTL(XOSHIRO[3], 11);

  return res;
}
#undef XOSHIRO
#undef XOSHIRO_BITS
#undef XOSHIRO_ROTL

/**
 * @brief mt19937-32
 * Authors   : Makoto Matsumoto and Takuji Nishimura
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

/**
 * @brief PCG XSH-RR
 */
cgraph_uint32_t cgraph_rand32_pcg(void) {
#define PCG_BITS (32)
#define PCG_ROTR(x, k) (((x) >> (k)) | ((x) << (PCG_BITS - (k))))
#define PCG_MUL UINT64_C(6364136223846793005)
#define PCG_INC UINT64_C(1442695040888963407)
  const cgraph_uint64_t seed = cgraph_rand64_seed();
  const cgraph_uint32_t data = (seed ^ (seed >> 18)) >> 27, bits = seed >> 59;
  cgraph_rand64_srand(seed * PCG_MUL + PCG_INC);

  return PCG_ROTR(data, bits);
#undef PCG_BITS
#undef PCG_ROTR
#undef PCG_MUL
#undef PCG_INC
}

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
#define CGRAPH_RAND64_DEFAULT cgraph_rand64_mmix
static cgraph_uint64_t (*cgraph_rand64_intgen)(void) = CGRAPH_RAND64_DEFAULT;

void cgraph_rand64_init(cgraph_uint64_t (*func)(void)) {
  if (NULL == func) {
    goto CERROR;
  }
  cgraph_rand64_intgen = func;

CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_WARN,
                        "rand64 init handle is empty, use previous as default");
#endif
  cgraph_rand64_intgen = (NULL == cgraph_rand64_intgen) ? CGRAPH_RAND64_DEFAULT
                                                        : cgraph_rand64_intgen;
}

static volatile cgraph_uint64_t rand64_seed = UINT64_C(1);

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
cgraph_uint64_t cgraph_rand64_mmix(void) {
#define MMIX_A UINT64_C(6364136223846793005)
#define MMIX_B UINT64_C(1442695040888963407)
#define MMIX_M UINT64_C(18446744073709551615)
  rand64_seed = ((((MMIX_A % MMIX_M) * (rand64_seed % MMIX_M)) % MMIX_M +
                  (MMIX_B % MMIX_M)) %
                 MMIX_M);

  return rand64_seed;
#undef MMIX_A
#undef MMIX_B
#undef MMIX_M
}

/**
 * @brief xorshift-64
 */
cgraph_uint64_t cgraph_rand64_xorshift(void) {
#define XORSHIFT_A (13)
#define XORSHIFT_B (7)
#define XORSHIFT_C (17)
  cgraph_uint64_t v = rand64_seed;
  v ^= (v << XORSHIFT_A);
  v ^= (v >> XORSHIFT_B);
  v ^= (v << XORSHIFT_C);

  return (rand64_seed = v);
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C
}

/**  */
cgraph_uint64_t cgraph_rand64_xorshift64s(void) {
#define XORSHIFT_A (12)
#define XORSHIFT_B (25)
#define XORSHIFT_C (27)
  cgraph_uint64_t v = rand64_seed;
  v ^= v >> XORSHIFT_A;
  v ^= v << XORSHIFT_B;
  v ^= v >> XORSHIFT_C;

  return (rand64_seed = v) * UINT64_C(0x2545F4914F6CDD1D);
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C
}

/**  */
cgraph_uint64_t cgraph_rand64_xorshift128p(void) {
#define XORSHIFT_A (23)
#define XORSHIFT_B (17)
#define XORSHIFT_C (26)
  static cgraph_uint64_t rand64_seed2 = 0;
  cgraph_uint64_t t = rand64_seed;
  const cgraph_uint64_t s = rand64_seed2;
  rand64_seed = s;
  t ^= t << XORSHIFT_A;
  t ^= t >> XORSHIFT_B;
  t ^= s ^ (s >> XORSHIFT_C);

  return (rand64_seed2 = t) + s;
#undef XORSHIFT_A
#undef XORSHIFT_B
#undef XORSHIFT_C
}

/**
 * @brief 64-bit xoshiro-256 algorithm
 * Refered from https://prng.di.unimi.it
 */
#define XOSHIRO xoshiro256_64
#define XOSHIRO_BITS (64)
#define XOSHIRO_ROTL(x, bits) CGRAPH_ROTL(x, XOSHIRO_BITS, bits)
static uint32_t XOSHIRO[4] = {UINT64_C(0), UINT64_C(0), UINT64_C(0),
                              UINT64_C(0)};

void cgraph_rand64_xoshiro256_jump(cgraph_uint64_t (*xoshiro256)(void)) {
  static const cgraph_uint64_t jump[4] = {
      UINT64_C(0x180ec6d33cfd0aba), UINT64_C(0xd5a61266f0c9392c),
      UINT64_C(0xa9582618e03fc9aa), UINT64_C(0x39abdc4529b1661c)};
  cgraph_uint64_t states[4] = {UINT64_C(0), UINT64_C(0), UINT64_C(0),
                               UINT64_C(0)};
  CGRAPH_LOOP(i, 0, 4)
  CGRAPH_LOOP(j, 0, XOSHIRO_BITS)
  if (jump[i] & (UINT64_C(1) << j)) {
    states[0] ^= XOSHIRO[0];
    states[1] ^= XOSHIRO[1];
    states[2] ^= XOSHIRO[2];
    states[3] ^= XOSHIRO[3];
  }
  xoshiro256();
  CGRAPH_LOOP_END
  CGRAPH_LOOP_END

  XOSHIRO[0] = states[0];
  XOSHIRO[1] = states[1];
  XOSHIRO[2] = states[2];
  XOSHIRO[3] = states[3];
}

void cgraph_rand64_xoshiro256_longjmp(cgraph_uint64_t (*xoshiro256)(void)) {
  static const cgraph_uint64_t jump[4] = {
      UINT64_C(0x76e15d3efefdcbbf), UINT64_C(0xc5004e441c522fb3),
      UINT64_C(0x77710069854ee241), UINT64_C(0x39109bb02acbe635)};
  cgraph_uint64_t states[4] = {UINT64_C(0), UINT64_C(0), UINT64_C(0),
                               UINT64_C(0)};
  CGRAPH_LOOP(i, 0, 4)
  CGRAPH_LOOP(j, 0, XOSHIRO_BITS)
  if (jump[i] & (UINT64_C(1) << j)) {
    states[0] ^= XOSHIRO[0];
    states[1] ^= XOSHIRO[1];
    states[2] ^= XOSHIRO[2];
    states[3] ^= XOSHIRO[3];
  }
  xoshiro256();
  CGRAPH_LOOP_END
  CGRAPH_LOOP_END

  XOSHIRO[0] = states[0];
  XOSHIRO[1] = states[1];
  XOSHIRO[2] = states[2];
  XOSHIRO[3] = states[3];
}

cgraph_uint64_t cgraph_rand64_xoshiro256pp(void) {
  cgraph_uint64_t res = XOSHIRO_ROTL(XOSHIRO[0] + XOSHIRO[3], 23) + XOSHIRO[0];
  const uint64_t t = XOSHIRO[1] << 17;

  XOSHIRO[2] ^= XOSHIRO[0];
  XOSHIRO[3] ^= XOSHIRO[1];
  XOSHIRO[1] ^= XOSHIRO[2];
  XOSHIRO[0] ^= XOSHIRO[3];
  XOSHIRO[2] ^= t;
  XOSHIRO[3] = XOSHIRO_ROTL(XOSHIRO[3], 45);

  return res;
}

cgraph_uint64_t cgraph_rand64_xoshiro256ss(void) {
  cgraph_uint64_t res = XOSHIRO_ROTL(XOSHIRO[1] * 5, 7) * 9;
  const uint64_t t = XOSHIRO[1] << 17;

  XOSHIRO[2] ^= XOSHIRO[0];
  XOSHIRO[3] ^= XOSHIRO[1];
  XOSHIRO[1] ^= XOSHIRO[2];
  XOSHIRO[0] ^= XOSHIRO[3];
  XOSHIRO[2] ^= t;
  XOSHIRO[3] = XOSHIRO_ROTL(XOSHIRO[3], 45);

  return res;
}
#undef XOSHIRO
#undef XOSHIRO_BITS
#undef XOSHIRO_ROTL

/**
 * @brief mt19937-64
 * Authers   : Makoto Matsumoto and Takuji Nishimura
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

cgraph_uint64_t cgraph_rand64_pcg(void) {
#define PCG_BITS (64)
#define PCG_ROTR(x, k) (((x) >> (k)) | ((x) << (PCG_BITS - (k))))
#define PCG_MUL0 UINT64_C(2549297995355413924)
#define PCG_MUL1 UINT64_C(4865540595714422341)
#define PCG_INC0 UINT64_C(6364136223846793005)
#define PCG_INC1 UINT64_C(1442695040888963407)
  const cgraph_uint64_t seed = cgraph_rand64_seed();
  const cgraph_uint32_t data = (seed ^ (seed >> 18)) >> 27, bits = seed >> 59;
  cgraph_rand64_srand(seed * PCG_MUL0 + PCG_INC0);

  return PCG_ROTR(data, bits);
#undef PCG_BITS
#undef PCG_ROTR
#undef PCG_MUL0
#undef PCG_MUL1
#undef PCG_INC0
#undef PCG_INC1
}

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
#define cgraph_rand_intgen() cgraph_rand64_intgen()
#else
#define cgraph_rand_intgen() cgraph_rand32_intgen()
#endif
  return cgraph_rand_intgen() % size;
#undef cgraph_rand_intgen
}