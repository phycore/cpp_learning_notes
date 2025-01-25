#ifndef _BITWISE_H
#define _BITWISE_H

#include <stdint.h>

#define SET_BIT16(x, bit) (x |= ((uint16_t)bit))

#define CLEAR_BIT16(x, bit) (x &= ~((uint16_t)bit))

#define TOGGLE_BIT16(x, bit) (x ^= ((uint16_t)bit))

#define CHECK_BIT16(x, bit) ((x & ((uint16_t)bit)) & ((uint16_t)bit))

#endif