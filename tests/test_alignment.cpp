#include <catch2/catch_all.hpp>
#include <cstdint>

extern "C" {
#include "plat_packed.h"
}

TEST_CASE("data_alignment_padding", "[alignment]") {
    typedef struct alignment {
        int8_t a;
        int16_t b;
        int32_t c;
        int64_t d;
    } alignment_t;

    typedef struct alignment_padding {
        int8_t a;        // 1 byte
        int8_t padding;  // 1 byte
        int16_t b;       // 2 byte
        int32_t c;       // 4 byte
        int64_t d;       // 8 byte, total = 16 byte
    } alignment_padding_t;

    size_t alig_size = sizeof(alignment_t);
    size_t alig_padding_size = sizeof(alignment_padding_t);

    INFO("size of alignment_t:" << alig_size);
    INFO("size of alignment_padding_t" << alig_padding_size);
    REQUIRE(alig_size == alig_padding_size);
}

TEST_CASE("data_alignment_packed", "[alignment]") {
    PACK(struct alignment {
        int8_t a;   // 1 byte
        int16_t b;  // 2 byte
        int32_t c;  // 4 byte
        int64_t d;  // 8 byte, total = 15 byte
    });
    typedef struct alignment alignment_t;

    alignment_t alig = {0};
    size_t compiler_data_size = sizeof(alignment_t);
    size_t viewed_data_size = (sizeof(alig.a) + sizeof(alig.b) + sizeof(alig.c) + sizeof(alig.d));

    INFO("packed size of aligment_t:" << compiler_data_size);
    REQUIRE(compiler_data_size == viewed_data_size);
}