#include <catch2/catch_all.hpp>
extern "C" {
#include "mathematics.h"
#include "plat_memory.h"
}

TEST_CASE("square", "[math]") {
    for (int64_t n = -100; n <= 100; n++) {
        REQUIRE(square(n) == ((n) * (n)));
    }
}

TEST_CASE("square_sequence", "[math]") {
    // 0^2 sequence
    size_t zero_square[] = {0};
    size_t* zero_square_sequence = square_sequence(0);
    REQUIRE(std::memcmp(zero_square_sequence, zero_square, (sizeof(size_t) * (0 + 1))) == 0);
    PLAT_FREE(zero_square_sequence);

    // 1^2 sequence
    size_t one_square[] = {0, 1};
    size_t* one_square_sequence = square_sequence(1);
    REQUIRE(std::memcmp(one_square_sequence, one_square, (sizeof(size_t) * (1 + 1))) == 0);
    PLAT_FREE(one_square_sequence);

    // 4^2 sequence
    size_t four_square[] = {0, 1, 4, 9, 16};
    size_t* four_square_sequence = square_sequence(4);
    REQUIRE(std::memcmp(four_square_sequence, four_square, (sizeof(size_t) * (4 + 1))) == 0);
    PLAT_FREE(four_square_sequence);

    // 5^2 sequence
    size_t five_square[] = {0, 1, 4, 9, 16, 25};
    size_t* five_square_sequence = square_sequence(5);
    REQUIRE(std::memcmp(five_square_sequence, five_square, (sizeof(size_t) * (5 + 1))) == 0);
    PLAT_FREE(five_square_sequence);

    // 10^2 sequence
    size_t ten_square[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    size_t* ten_square_sequence = square_sequence(10);
    REQUIRE(std::memcmp(ten_square_sequence, ten_square, (sizeof(size_t) * (10 + 1))) == 0);
    PLAT_FREE(ten_square_sequence);
}