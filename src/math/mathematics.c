#include "mathematics.h"

// (n + 1)^2 = n^2 + (n + n) + 1;
// n^2 = ((n - 1) + 1)^2
// = (n - 1)^2 + 2(n -1) + 1
// = (n - 1)^2 + 2n - 1
int64_t square(int64_t n) {
    int64_t n_minus1_square = 0;
    int64_t n_square = 0;

    if (n == 0) {
        goto EXIT;
    }

    // ex: -n -> n = (-n - (-2n))
    // ex: -3 -> 3 = (-3) - (-3) - (-3)
    n = (n >= 0) ? (n) : ((n) - (n) - (n));

    for (int64_t index = 0; index < (n - 1); index++) {
        n_minus1_square += (n - 1);
    }
    n_square = (n_minus1_square + (n + n) - 1);

EXIT:
    return n_square;
}