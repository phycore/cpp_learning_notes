#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <stdint.h>

#include "plat_string.h"

typedef struct any_structure {
    int32_t a;
    char b[PATH_LEN];
    double c;
} any_structure_t;

#endif  // _STRUCTURE_H