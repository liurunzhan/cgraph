/**
 * @file cgraph_hash.h
 * @brief commonly-used hash functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_HASH_H__
#define __CGRAPH_HASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/** hash algorithms */
extern cgraph_size_t cgraph_hash_js(const cgraph_uint8_t *data,
                                    const cgraph_size_t len);
extern cgraph_size_t cgraph_hash_sdbm(const cgraph_uint8_t *data,
                                      const cgraph_size_t len);
extern cgraph_size_t cgraph_hash_rs(const cgraph_uint8_t *data,
                                    const cgraph_size_t len);
extern cgraph_size_t cgraph_hash_elf(const cgraph_uint8_t *data,
                                     const cgraph_size_t len);
extern cgraph_size_t cgraph_hash_bkdr(const cgraph_uint8_t *data,
                                      const cgraph_size_t len);

/** encryption algorithms */

typedef enum {
  CGRAPH_ENCMODE_ECB = 0, /** Electronic CodeBook mode */
  CGRAPH_ENCMODE_CBC = 1, /** Cipher Block Chaining mode */
  CGRAPH_ENCMODE_CFB = 2, /** Cipher FeedBack mode */
  CGRAPH_ENCMODE_OFB = 3, /** Output-FeedBack mode */
  CGRAPH_ENCMODE_CTR = 4  /** CounTeR mode */
} cgraph_encmode_t;

/* define commonly-used data length */
#pragma pack(1)
typedef struct {
  cgraph_uint8_t data[7];
} cgraph_hash56_t;

typedef struct {
  cgraph_uint16_t data[7];
} cgraph_hash112_t;

typedef struct {
  cgraph_uint32_t data[4];
} cgraph_hash128_t;

typedef struct {
  cgraph_uint32_t data[5];
} cgraph_hash160_t;
#pragma pack()

extern cgraph_hash128_t cgraph_encrypt_aes(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);
extern cgraph_hash128_t cgraph_decrypt_aes(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);

extern cgraph_hash128_t cgraph_encrypt_des(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);
extern cgraph_hash128_t cgraph_decrypt_des(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);

extern cgraph_hash128_t cgraph_encrypt_md5(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);
extern cgraph_hash128_t cgraph_decrypt_md5(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);

extern cgraph_hash128_t cgraph_encrypt_sm2(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);
extern cgraph_hash128_t cgraph_decrypt_sm2(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);

extern cgraph_hash128_t cgraph_encrypt_sm4(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);
extern cgraph_hash128_t cgraph_decrypt_sm4(const cgraph_uint8_t *data,
                                           const cgraph_size_t len);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_HASH_H__ */
