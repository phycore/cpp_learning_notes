#include <catch2/catch_all.hpp>

extern "C" {
#include "bits.h"
#include "bitwise.h"
}

TEST_CASE("set bit", "[bitwise]") {
    uint16_t a = ((0b00000000U << 8) | 0b11000011U);
    SET_BIT16(a, BIT03);

    REQUIRE(a == ((0b00000000U << 8) | 0b11001011U));
}

TEST_CASE("clear bit", "[bitwise]") {
    uint16_t a = ((0xFFU << 8) | 0xFFU);
    CLEAR_BIT16(a, BIT15);

    REQUIRE(a == ((0b01111111U << 8) | 0b11111111U));
}

TEST_CASE("toggle bit", "[bitwise]") {
    uint16_t a = ((0b01010101U << 8) | 0b01010101U);
    // 1 ^ 0 = 1
    TOGGLE_BIT16(a, BIT08);
    REQUIRE(a == ((0b01010100U << 8) | 0b01010101U));
    // 1 ^ 1 = 0
    TOGGLE_BIT16(a, BIT08);
    REQUIRE(a == ((0b01010101U << 8) | 0b01010101U));
}

TEST_CASE("check bit", "[bitwise]") {
    uint16_t a = ((0x80U << 8) | 0x1234U);
    // After check BIT15, a will be BIT15.
    REQUIRE(CHECK_BIT16(a, BIT15) == BIT15);
    // After check BIT14, a will be 0.
    REQUIRE(CHECK_BIT16(a, BIT14) == 0);
}