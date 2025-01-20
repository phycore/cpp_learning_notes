#include <catch2/catch_all.hpp>
extern "C" {
#include "mathematics.h"
}

TEST_CASE("square", "[math]") {
    for (int64_t n = -100; n <= 100; n++) {
        REQUIRE(square(n) == ((n) * (n)));
    }
}