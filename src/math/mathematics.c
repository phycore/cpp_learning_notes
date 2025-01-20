#include "mathematics.h"

#include "plat_memory.h"

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

// (n + 1)^2 = n^2 + 2n + 1
// ex: 49^2 = ((48) + 1)^2 = 48^2 + 2*(48) + 1
size_t* square_sequence(size_t n) {
    size_t sequence_size = (sizeof(size_t) * (n + 1));
    size_t* p_sequence = (size_t*)plat_allocate(sequence_size);
    if (NULL == p_sequence) {
        goto EXIT;
    }

    p_sequence[0] = 0;  // 0^2 = 0;
    for (size_t num = 1; num <= n; num++) {
        size_t pre_num = (num - 1);
        p_sequence[num] = p_sequence[pre_num] + (pre_num + pre_num) + 1;
        // p_sequence[4] = p_sequence[3] + (3 + 3) + 1
        // 4^2 = 3^2 + 2 * 3 + 1
    }

EXIT:
    return p_sequence;
}