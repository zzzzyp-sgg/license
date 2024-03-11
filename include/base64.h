/// @details  this file contains the base64 encoding and decoding functions
/// @author   zyp
/// @date     2024-03-11

#ifndef BASE64_H
#define BASE64_H

#define BASE64_ENCODE_OUT_SIZE(s) ((unsigned int)((((s) + 2) / 3) * 4 + 1))
#define BASE64_DECODE_OUT_SIZE(s) ((unsigned int)(((s) / 4) * 3))

unsigned int base64_encode(const unsigned char* in, unsigned int inlen, char* out);
unsigned int base64_decode(const char* in, unsigned int inlen, unsigned char* out);

#endif