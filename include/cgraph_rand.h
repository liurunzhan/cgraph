/**
 * @file cgraph_rand.h
 * @brief the 32-bit and 64-bit random number generator functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_RAND_H__
#define __CGRAPH_RAND_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/** 32-bit random number */
#ifndef RAND32_MAX
#define RAND32_MAX CGRAPH_UINT32_MAX
#endif

/** 32-bit random integer generator */
extern void cgraph_rand32_init(cgraph_uint32_t (*func)(void));
extern void cgraph_rand32_srand(const cgraph_uint32_t seed);
extern cgraph_uint32_t cgraph_rand32_seed(void);
extern cgraph_uint32_t cgraph_rand32_rand(void);

extern cgraph_uint32_t cgraph_rand32_miller(void);

extern cgraph_uint32_t cgraph_rand32_xorshift(void);
extern void cgraph_rand32_xoshiro128_jump(cgraph_uint32_t (*xoshiro128)(void));
extern void
    cgraph_rand32_xoshiro128_longjmp(cgraph_uint32_t (*xoshiro128)(void));
extern cgraph_uint32_t cgraph_rand32_xoshiro128pp(void);
extern cgraph_uint32_t cgraph_rand32_xoshiro128ss(void);

extern void cgraph_rand32_mt19937_init(void);
extern cgraph_uint32_t cgraph_rand32_mt19937(void);

extern cgraph_uint32_t cgraph_rand32_pcg(void);

extern cgraph_uint32_t cgraph_rand32_uniform(const cgraph_uint32_t min,
                                             const cgraph_uint32_t max);
extern cgraph_float32_t cgraph_rand32_normal(const cgraph_float32_t mu,
                                             const cgraph_float32_t sigma);

/** 64-bit random number */
#ifndef RAND64_MAX
#define RAND64_MAX CGRAPH_UINT64_MAX
#endif

/** 64-bit random integer generator */
extern void cgraph_rand64_init(cgraph_uint64_t (*func)(void));
extern void cgraph_rand64_srand(const cgraph_uint64_t seed);
extern cgraph_uint64_t cgraph_rand64_seed(void);
extern cgraph_uint64_t cgraph_rand64_rand(void);

extern cgraph_uint64_t cgraph_rand64_mmix(void);

extern cgraph_uint64_t cgraph_rand64_xorshift(void);
extern cgraph_uint64_t cgraph_rand64_xorshift64s(void);
extern cgraph_uint64_t cgraph_rand64_xorshift128p(void);
extern void cgraph_rand64_xoshiro256_jump(cgraph_uint64_t (*xoshiro256)(void));
extern void
    cgraph_rand64_xoshiro256_longjmp(cgraph_uint64_t (*xoshiro256)(void));
extern cgraph_uint64_t cgraph_rand64_xoshiro256pp(void);
extern cgraph_uint64_t cgraph_rand64_xoshiro256ss(void);

extern void cgraph_rand64_mt19937_init(void);
extern cgraph_uint64_t cgraph_rand64_mt19937(void);

extern cgraph_uint64_t cgraph_rand64_pcg(void);

extern cgraph_uint64_t cgraph_rand64_uniform(const cgraph_uint64_t min,
                                             const cgraph_uint64_t max);
extern cgraph_float64_t cgraph_rand64_normal(const cgraph_float64_t mu,
                                             const cgraph_float64_t sigma);

extern cgraph_bool_t cgraph_rand_bool(void);
extern cgraph_logic_t cgraph_rand_logic(void);
extern cgraph_size_t cgraph_rand_size(const cgraph_size_t size);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_RAND_H__ */
