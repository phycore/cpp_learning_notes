#include <catch2/catch_all.hpp>
#include <cstdint>

extern "C" {
#include "bytes_swap.h"
}

TEST_CASE("check endian by pointer.", "[endian check]") {
    uint16_t a = 0x1234;

    uint8_t* p_a = (uint8_t*)&a;
    CAPTURE(*(p_a + 0), *(p_a + 1));
    if (IS_BIG_ENDIAN) {
        REQUIRE(*(p_a + 0) == 0x12);
        REQUIRE(*(p_a + 1) == 0x34);
    } else {
        REQUIRE(*(p_a + 0) == 0x34);
        REQUIRE(*(p_a + 1) == 0x12);
    }
}

TEST_CASE("check endian by union", "[endian check]") {
    typedef union byte_order {
        uint16_t value;
        uint8_t order[2];
    } byte_order_t;

    byte_order_t a = {.value = 0x1234};
    CAPTURE(a.order[0], a.order[1]);
    if (IS_BIG_ENDIAN) {
        REQUIRE(a.order[0] == 0x12);
        REQUIRE(a.order[1] == 0x34);
    } else {
        REQUIRE(a.order[0] == 0x34);
        REQUIRE(a.order[1] == 0x12);
    }
}

TEST_CASE("endian swap 16 bit", "[endian swap]") {
    uint16_t a = 0x1234;
    uint16_t swap_a = ENDIAN_SWAP16(a);

    uint8_t* p_swap_a = (uint8_t*)&swap_a;
    CAPTURE(*(p_swap_a + 0), *(p_swap_a + 1));

    bool is_big_to_little = (IS_BIG_ENDIAN) ? (1) : (0);
    if (is_big_to_little) {
        REQUIRE(*(p_swap_a + 0) == 0x34);
        REQUIRE(*(p_swap_a + 1) == 0x12);
    } else {
        REQUIRE(*(p_swap_a + 0) == 0x12);
        REQUIRE(*(p_swap_a + 1) == 0x34);
    }
}

TEST_CASE("endian swap 32 bit", "[endian swap]") {
    uint32_t a = 0x12345678;
    uint32_t swap_a = ENDIAN_SWAP32(a);

    uint8_t* p_swap_a = (uint8_t*)&swap_a;
    CAPTURE(*(p_swap_a + 0), *(p_swap_a + 1));
    CAPTURE(*(p_swap_a + 2), *(p_swap_a + 3));

    bool is_big_to_little = (IS_BIG_ENDIAN) ? (1) : (0);
    if (is_big_to_little) {
        REQUIRE(*(p_swap_a + 0) == 0x78);
        REQUIRE(*(p_swap_a + 1) == 0x56);
        REQUIRE(*(p_swap_a + 2) == 0x34);
        REQUIRE(*(p_swap_a + 3) == 0x12);
    } else {
        REQUIRE(*(p_swap_a + 0) == 0x12);
        REQUIRE(*(p_swap_a + 1) == 0x34);
        REQUIRE(*(p_swap_a + 2) == 0x56);
        REQUIRE(*(p_swap_a + 3) == 0x78);
    }
}

TEST_CASE("endian swap 64 bit", "[endian swap]") {
    uint64_t a = 0x1234567812345678;
    uint64_t swap_a = ENDIAN_SWAP64(a);

    uint8_t* p_swap_a = (uint8_t*)&swap_a;
    CAPTURE(*(p_swap_a + 0), *(p_swap_a + 1));
    CAPTURE(*(p_swap_a + 2), *(p_swap_a + 3));
    CAPTURE(*(p_swap_a + 4), *(p_swap_a + 5));
    CAPTURE(*(p_swap_a + 6), *(p_swap_a + 7));

    bool is_big_to_little = (IS_BIG_ENDIAN) ? (1) : (0);
    if (is_big_to_little) {
        REQUIRE(*(p_swap_a + 0) == 0x78);
        REQUIRE(*(p_swap_a + 1) == 0x56);
        REQUIRE(*(p_swap_a + 2) == 0x34);
        REQUIRE(*(p_swap_a + 3) == 0x12);
        REQUIRE(*(p_swap_a + 4) == 0x78);
        REQUIRE(*(p_swap_a + 5) == 0x56);
        REQUIRE(*(p_swap_a + 6) == 0x34);
        REQUIRE(*(p_swap_a + 7) == 0x12);
    } else {
        REQUIRE(*(p_swap_a + 0) == 0x12);
        REQUIRE(*(p_swap_a + 1) == 0x34);
        REQUIRE(*(p_swap_a + 2) == 0x56);
        REQUIRE(*(p_swap_a + 3) == 0x78);
        REQUIRE(*(p_swap_a + 4) == 0x12);
        REQUIRE(*(p_swap_a + 5) == 0x34);
        REQUIRE(*(p_swap_a + 6) == 0x56);
        REQUIRE(*(p_swap_a + 7) == 0x78);
    }
}