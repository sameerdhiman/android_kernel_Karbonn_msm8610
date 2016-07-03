/* Test vectors : FIPS Known answer tests for QCEDEV .
 *
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __CRYPTO_MSM_QCEDEV_FIPS_H
#define __CRYPTO_MSM_QCEDEV_FIPS_H

#include "qce.h"

static uint8_t  _std_init_vector_sha1_uint8[] =   {
	0x67, 0x45, 0x23, 0x01, 0xEF, 0xCD, 0xAB, 0x89,
	0x98, 0xBA, 0xDC, 0xFE, 0x10, 0x32, 0x54, 0x76,
	0xC3, 0xD2, 0xE1, 0xF0
};

/* standard initialization vector for SHA-256, source: FIPS 180-2 */
static uint8_t _std_init_vector_sha256_uint8[] = {
	0x6A, 0x09, 0xE6, 0x67, 0xBB, 0x67, 0xAE, 0x85,
	0x3C, 0x6E, 0xF3, 0x72, 0xA5, 0x4F, 0xF5, 0x3A,
	0x51, 0x0E, 0x52, 0x7F, 0x9B, 0x05, 0x68, 0x8C,
	0x1F, 0x83, 0xD9, 0xAB, 0x5B, 0xE0, 0xCD, 0x19
};

/*
 * For Hashing / HMAC algorithms
 */
struct _fips_test_vector_sha_hmac {
	char *key;
	unsigned char klen;
	char *input;
	unsigned char ilen;
	char *digest;
	unsigned char diglen;
	enum qcedev_sha_alg_enum hash_alg;
};

/*
 * For cipher algorithms
 */
struct _fips_test_vector_cipher {
	char *key;
	unsigned char klen;
	char *iv;
	unsigned char ivlen;
	char *pln_txt;
	unsigned int pln_txt_len;
	char *enc_txt;
	unsigned int enc_txt_len;
	enum qcedev_cipher_alg_enum enc_alg;
	enum qcedev_cipher_mode_enum mode;
};


/*
 * Test vectors sha and hmac algorothms
 */
static struct _fips_test_vector_sha_hmac fips_test_vector_sha_hmac[] = {
/* http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/SHA1.pdf */
	{/* SHA1 */
		.hash_alg	=	QCEDEV_ALG_SHA1,
		.input		=	"abc",
		.ilen		=	3,
		.digest	=	"\xa9\x99\x3e\x36\x47\x06\x81\x6a"
					"\xba\x3e\x25\x71\x78\x50\xc2\x6c"
					"\x9c\xd0\xd8\x9d",
		.diglen	=	SHA1_DIGEST_SIZE,
	},
/* http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/SHA256.pdf */
	{/* SHA256 */
		.hash_alg	=	QCEDEV_ALG_SHA256,
		.input		=	"abc",
		.ilen		=	3,
		.digest	=	"\xba\x78\x16\xbf\x8f\x01\xcf\xea"
					"\x41\x41\x40\xde\x5d\xae\x22\x23"
					"\xb0\x03\x61\xa3\x96\x17\x7a\x9c"
					"\xb4\x10\xff\x61\xf2\x00\x15\xad",
		.diglen	=	SHA256_DIGEST_SIZE,
	},
/* http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/HMAC_SHA1.pdf */
	{/* HMAC-SHA1 */
		.hash_alg	=	QCEDEV_ALG_SHA1_HMAC,
		.key		=	"\x00\x01\x02\x03\x04\x05\x06\x07"
					"\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
					"\x10\x11\x12\x13",
		.klen		=	20,
		.input		=	"Sample message for keylen<blocklen",
		.ilen		=	34,
		.digest	=	"\x4C\x99\xFF\x0C\xB1\xB3\x1B\xD3"
					"\x3F\x84\x31\xDB\xAF\x4D\x17\xFC"
					"\xD3\x56\xA8\x07",
		.diglen	=	SHA1_DIGEST_SIZE,
	},
/* http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/HMAC_SHA256.pdf */
	{/* HMAC-SHA256 */
		.hash_alg	=	QCEDEV_ALG_SHA256_HMAC,
		.key		=	"\x00\x01\x02\x03\x04\x05\x06\x07"
					"\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
					"\x10\x11\x12\x13\x14\x15\x16\x17"
					"\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F"
					"\x20\x21\x22\x23\x24\x25\x26\x27"
					"\x28\x29\x2A\x2B\x2C\x2D\x2E\x2F"
					"\x30\x31\x32\x33\x34\x35\x36\x37"
					"\x38\x39\x3A\x3B\x3C\x3D\x3E\x3F",
		.klen		=	64,
		.input		=	"Sample message for keylen=blocklen",
		.ilen		=	34,
		.digest	=	"\x8B\xB9\xA1\xDB\x98\x06\xF2\x0D"
					"\xF7\xF7\x7B\x82\x13\x8C\x79\x14"
					"\xD1\x74\xD5\x9E\x13\xDC\x4D\x01"
					"\x69\xC9\x05\x7B\x13\x3E\x1D\x62",
		.diglen	=	SHA256_DIGEST_SIZE,
	},
/* From NIST Special Publication 800-38B Appendix D.1 */
	{/* AES 128-CMAC */
		.hash_alg	=	QCEDEV_ALG_AES_CMAC,
		.key		=	"\x2b\x7e\x15\x16\x28\xae\xd2\xa6"
					"\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
		.klen		=	16,
		.input		=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a",
		.ilen		=	16,
		.digest	=	"\x07\x0a\x16\xb4\x6b\x4d\x41\x44"
					"\xf7\x9b\xdd\x9d\xd0\x4a\x28\x7c",
		.diglen	=	16,
	},
	/* From NIST Special Publication 800-38B Appendix D.1 */
	{/* AES 256-CMAC */
		.hash_alg	=	QCEDEV_ALG_AES_CMAC,
		.key		=	"\x60\x3d\xeb\x10\x15\xca\x71\xbe"
					"\x2b\x73\xae\xf0\x85\x7d\x77\x81"
					"\x1f\x35\x2c\x07\x3b\x61\x08\xd7"
					"\x2d\x98\x10\xa3\x09\x14\xdf\xf4",
		.klen		=	32,
		.input		=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a",
		.ilen		=	16,
		.digest	=	"\x28\xa7\x02\x3f\x45\x2e\x8f\x82"
						"\xbd\x4b\xf2\x8d\x8c\x37\xc3\x5c",
		.diglen	=	16,
	},
};

 /*
 *Test vectors for cipher algorithms
 */
static struct _fips_test_vector_cipher fips_test_vector_cipher[] = {
	/* From NIST Special Publication 800-38A, Appendix F.1 */
	{/* AES-128 ECB */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_ECB,
		.key		=	"\x2b\x7e\x15\x16\x28\xae\xd2\xa6"
					"\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
		.klen		=	16,
		.ivlen		=	0,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\x3a\xd7\x7b\xb4\x0d\x7a\x36\x60"
					"\xa8\x9e\xca\xf3\x24\x66\xef\x97"
					"\xf5\xd3\xd5\x85\x03\xb9\x69\x9d"
					"\xe7\x85\x89\x5a\x96\xfd\xba\xaf"
					"\x43\xb1\xcd\x7f\x59\x8e\xce\x23"
					"\x88\x1b\x00\xe3\xed\x03\x06\x88"
					"\x7b\x0c\x78\x5e\x27\xe8\xad\x3f"
					"\x82\x23\x20\x71\x04\x72\x5d\xd4",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-38A, Appendix F.1 */
	{/* AES-256 ECB */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_ECB,
		.key		=	"\x60\x3d\xeb\x10\x15\xca\x71\xbe"
					"\x2b\x73\xae\xf0\x85\x7d\x77\x81"
					"\x1f\x35\x2c\x07\x3b\x61\x08\xd7"
					"\x2d\x98\x10\xa3\x09\x14\xdf\xf4",
		.klen		=	32,
		.ivlen		=	0,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\xf3\xee\xd1\xbd\xb5\xd2\xa0\x3c"
					"\x06\x4b\x5a\x7e\x3d\xb1\x81\xf8"
					"\x59\x1c\xcb\x10\xd4\x10\xed\x26"
					"\xdc\x5b\xa7\x4a\x31\x36\x28\x70"
					"\xb6\xed\x21\xb9\x9c\xa6\xf4\xf9"
					"\xf1\x53\xe7\xb1\xbe\xaf\xed\x1d"
					"\x23\x30\x4b\x7a\x39\xf9\xf3\xff"
					"\x06\x7d\x8d\x8f\x9e\x24\xec\xc7",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-38A, Appendix F.2 */
	{/* AES-128 CBC */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_CBC,
		.key		=	"\x2b\x7e\x15\x16\x28\xae\xd2\xa6"
					"\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
		.klen		=	16,
		.iv		=	"\x00\x01\x02\x03\x04\x05\x06\x07"
					"\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\x76\x49\xab\xac\x81\x19\xb2\x46"
					"\xce\xe9\x8e\x9b\x12\xe9\x19\x7d"
					"\x50\x86\xcb\x9b\x50\x72\x19\xee"
					"\x95\xdb\x11\x3a\x91\x76\x78\xb2"
					"\x73\xbe\xd6\xb8\xe3\xc1\x74\x3b"
					"\x71\x16\xe6\x9e\x22\x22\x95\x16"
					"\x3f\xf1\xca\xa1\x68\x1f\xac\x09"
					"\x12\x0e\xca\x30\x75\x86\xe1\xa7",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-38A, Appendix F.2 */
	{/* AES-256 CBC */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_CBC,
		.key		=	"\x60\x3d\xeb\x10\x15\xca\x71\xbe"
					"\x2b\x73\xae\xf0\x85\x7d\x77\x81"
					"\x1f\x35\x2c\x07\x3b\x61\x08\xd7"
					"\x2d\x98\x10\xa3\x09\x14\xdf\xf4",
		.klen		=	32,
		.iv		=	"\x00\x01\x02\x03\x04\x05\x06\x07"
					"\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\xf5\x8c\x4c\x04\xd6\xe5\xf1\xba"
					"\x77\x9e\xab\xfb\x5f\x7b\xfb\xd6"
					"\x9c\xfc\x4e\x96\x7e\xdb\x80\x8d"
					"\x67\x9f\x77\x7b\xc6\x70\x2c\x7d"
					"\x39\xf2\x33\x69\xa9\xd9\xba\xcf"
					"\xa5\x30\xe2\x63\x04\x23\x14\x61"
					"\xb2\xeb\x05\xe2\xc3\x9b\xe9\xfc"
					"\xda\x6c\x19\x07\x8c\x6a\x9d\x1b",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-38A, Appendix F.5 */
	{/* AES-128 CTR */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_CTR,
		.key		=	"\x2b\x7e\x15\x16\x28\xae\xd2\xa6"
					"\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
		.klen		=	16,
		.iv		=	"\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7"
					"\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\x87\x4d\x61\x91\xb6\x20\xe3\x26"
					"\x1b\xef\x68\x64\x99\x0d\xb6\xce"
					"\x98\x06\xf6\x6b\x79\x70\xfd\xff"
					"\x86\x17\x18\x7b\xb9\xff\xfd\xff"
					"\x5a\xe4\xdf\x3e\xdb\xd5\xd3\x5e"
					"\x5b\x4f\x09\x02\x0d\xb0\x3e\xab"
					"\x1e\x03\x1d\xda\x2f\xbe\x03\xd1"
					"\x79\x21\x70\xa0\xf3\x00\x9c\xee",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-38A, Appendix F.5 */
	{/* AES-256 CTR */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_CTR,
		.key		=	"\x60\x3d\xeb\x10\x15\xca\x71\xbe"
					"\x2b\x73\xae\xf0\x85\x7d\x77\x81"
					"\x1f\x35\x2c\x07\x3b\x61\x08\xd7"
					"\x2d\x98\x10\xa3\x09\x14\xdf\xf4",
		.klen		=	32,
		.iv		=	"\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7"
					"\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\x60\x1e\xc3\x13\x77\x57\x89\xa5"
					"\xb7\xa7\xf5\x04\xbb\xf3\xd2\x28"
					"\xf4\x43\xe3\xca\x4d\x62\xb5\x9a"
					"\xca\x84\xe9\x90\xca\xca\xf5\xc5"
					"\x2b\x09\x30\xda\xa2\x3d\xe9\x4c"
					"\xe8\x70\x17\xba\x2d\x84\x98\x8d"
					"\xdf\xc9\xc5\x8d\xb6\x7a\xad\xa6"
					"\x13\xc2\xdd\x08\x45\x79\x41\xa6",
		.enc_txt_len	=	64,
	},
	/* Derived From From NIST Special Publication 800-38A */
	{/* AES-128 XTS requires 2 keys and thus length of key is twice. */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_XTS,
		.key		=	"\x60\x3d\xeb\x10\x15\xca\x71\xbe"
					"\x2b\x73\xae\xf0\x85\x7d\x77\x81"
					"\x1f\x35\x2c\x07\x3b\x61\x08\xd7"
					"\x2d\x98\x10\xa3\x09\x14\xdf\xf4",
		.klen		=	32,
		.iv		=	"\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7"
					"\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\xba\x2a\x7d\x50\x7b\x60\x63\x3e"
					"\xf3\x1b\x06\x14\xb4\x45\xb5\xb5"
					"\x42\x0d\x12\x57\x28\x15\x2e\x5d"
					"\x5a\x54\xbe\x46\x5c\x9d\x1f\x2e"
					"\x18\x8e\x79\x07\xc7\xdf\xe7\xf8"
					"\x78\xa6\x53\x2a\x80\xb4\xd9\xce"
					"\x1d\xbe\x75\x7e\xb6\x11\xef\x1e"
					"\x51\x5d\xd6\x70\x03\x51\xcc\x94",
		.enc_txt_len	=	64,
	},
	/* Derived From From NIST Special Publication 800-38A */
	{/* AES-256 XTS requires 2 keys and thus length of key is twice */
		.enc_alg	=	QCEDEV_ALG_AES,
		.mode		=	QCEDEV_AES_MODE_XTS,
		.key		=	"\x3a\xd7\x7b\xb4\x0d\x7a\x36\x60"
					"\xa8\x9e\xca\xf3\x24\x66\xef\x97"
					"\xf5\xd3\xd5\x85\x03\xb9\x69\x9d"
					"\xe7\x85\x89\x5a\x96\xfd\xba\xaf"
					"\x43\xb1\xcd\x7f\x59\x8e\xce\x23"
					"\x88\x1b\x00\xe3\xed\x03\x06\x88"
					"\x7b\x0c\x78\x5e\x27\xe8\xad\x3f"
					"\x82\x23\x20\x71\x04\x72\x5d\xd4",
		.klen		=	64,
		.iv		=	"\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7"
					"\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff",
		.ivlen		=	16,
		.pln_txt	=	"\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
					"\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
					"\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
					"\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
					"\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
					"\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
					"\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
					"\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
		.pln_txt_len	=	64,
		.enc_txt	=	"\xd7\x2b\x90\x02\x6f\xf0\xd2\x39"
					"\x7b\x1a\x57\x92\xd0\x1e\xc1\xb6"
					"\x04\x8c\x08\x8e\xa4\x1f\xa0\x0f"
					"\x5e\xd8\xaf\xda\x6e\xd2\x4e\x5b"
					"\x23\xde\x09\xa4\x19\x79\xda\xd4"
					"\xe9\x4b\xbc\x05\x2e\xca\x20\x7d"
					"\xd5\x0f\x89\x88\xa3\xda\x46\x1f"
					"\x1e\xde\x53\x78\x90\xb2\x9a\x2c",
		.enc_txt_len	=	64,
	},
	/* From NIST Special Publication 800-67, Appendix B.1 */
	{/* 3DES ECB */
		.enc_alg	=	QCEDEV_ALG_3DES,
		.mode		=	QCEDEV_DES_MODE_ECB,
		.key		=	"\x01\x23\x45\x67\x89\xAB\xCD\xEF"
					"\x23\x45\x67\x89\xAB\xCD\xEF\x01"
					"\x45\x67\x89\xAB\xCD\xEF\x01\x23",
		.klen		=	24,
		.ivlen		=	0,
		.pln_txt	=	"\x54\x68\x65\x20\x71\x75\x66\x63"
					"\x6B\x20\x62\x72\x6F\x77\x6E\x20"
					"\x66\x6F\x78\x20\x6A\x75\x6D\x70",
		.pln_txt_len	=	24,
		.enc_txt	=	"\xA8\x26\xFD\x8C\xE5\x3B\x85\x5F"
					"\xCC\xE2\x1C\x81\x12\x25\x6F\xE6"
					"\x68\xD5\xC0\x5D\xD9\xB6\xB9\x00",
		.enc_txt_len	=	24,
	},
	/* Derived From From NIST Special Publication 800-38A  and 800-67 */
	{/* 3DES CBC */
		.enc_alg	=	QCEDEV_ALG_3DES,
		.mode		=	QCEDEV_DES_MODE_CBC,
		.key		=	"\x01\x23\x45\x67\x89\xAB\xCD\xEF"
					"\x23\x45\x67\x89\xAB\xCD\xEF\x01"
					"\x45\x67\x89\xAB\xCD\xEF\x01\x23",
		.klen		=	24,
		.iv		=	"\x00\x01\x02\x03\x04\x05\x06\x07",
		.ivlen		=	8,
		.pln_txt	=	"\x54\x68\x65\x20\x71\x75\x66\x63"
					"\x6B\x20\x62\x72\x6F\x77\x6E\x20"
					"\x66\x6F\x78\x20\x6A\x75\x6D\x70",
		.pln_txt_len	=	24,
		.enc_txt	=	"\xf3\x68\xd0\x6f\x3b\xbd\x61\x4e"
					"\x60\xf2\xd0\x24\x5c\xad\x3f\x81"
					"\x8d\x5c\x69\xf2\xcb\x3f\xd5\xc7",
		.enc_txt_len	=	24,
	},
};
#endif	/* __CRYPTO_MSM_QCEDEV_FIPS_H */

