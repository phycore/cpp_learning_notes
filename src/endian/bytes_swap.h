#ifndef _BYTES_SWAP_H
#define _BYTES_SWAP_H

// TODO: https://en.cppreference.com/w/cpp/numeric/byteswap

/*
16 bit
(byte[1]|byte[0])
byte[0] -> byte[1]: << 8
byte[1] -> byte[0]: >> 8

32 bit
(byte[3]|byte[2]|byte[1]|byte[0])
byte[0] -> byte[3]: << 24
byte[1] -> byte[2]: << 8
byte[2] -> byte[1]: >> 8
byte[3] -> byte[0]: >> 24

64 bit
(byte[7]|byte[6]|byte[5]|byte[4]|byte[3]|byte[2]|byte[1]|byte[0])
byte[0] -> byte[7]: << 56
byte[1] -> byte[6]: << 40
byte[2] -> byte[5]: << 24
byte[3] -> byte[4]: << 8
byte[4] -> byte[3]: >> 8
byte[5] -> byte[2]: >> 24
byte[6] -> byte[1]: >> 40
byte[7] -> byte[0]: >> 56
*/

// clang-format off
#define ENDIAN_SWAP16(x)     \
    ((((x) & 0x00FF) << 8) | \
     (((x) & 0xFF00) >> 8))

#define ENDIAN_SWAP32(x)           \
    ((((x) & 0x000000FF) << 24) |  \
     (((x) & 0x0000FF00) << 8)  |  \
     (((x) & 0x00FF0000) >> 8)  |  \
     (((x) & 0xFF000000) >> 24))

#define ENDIAN_SWAP64(x)                  \
    ((((x) & 0x00000000000000FF) << 56) | \
     (((x) & 0x000000000000FF00) << 40) | \
     (((x) & 0x0000000000FF0000) << 24) | \
     (((x) & 0x00000000FF000000) << 8)  | \
     (((x) & 0x000000FF00000000) >> 8)  | \
     (((x) & 0x0000FF0000000000) >> 24) | \
     (((x) & 0x00FF000000000000) >> 40) | \
     (((x) & 0xFF00000000000000) >> 56))

// clang-format on

#endif