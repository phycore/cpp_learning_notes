#include <catch2/catch_all.hpp>
extern "C" {
#include "structure.h"
}

#define PI 3.14159

TEST_CASE("struct_initialize", "[struct]") {
    any_structure_t any_1 = {0};
    any_structure_t any_2 = {.a = 0, .b = {'\0'}, .c = 0.0f};

    CAPTURE(any_1.a, any_1.b, any_1.c);
    CAPTURE(any_2.a, any_2.b, any_2.c);
    REQUIRE(std::memcmp(&any_1, &any_2, sizeof(any_structure_t)) == 0);

    any_structure_t any_3;
    std::memset(&any_3, 0, sizeof(any_structure_t));
    CAPTURE(any_1.a, any_1.b, any_1.c);
    CAPTURE(any_3.a, any_3.b, any_3.c);
    REQUIRE(std::memcmp(&any_1, &any_3, sizeof(any_structure_t)) == 0);
}

TEST_CASE("struct_assigned", "[struct]") {
    any_structure_t any_1 = {.a = 32, .b = {"I love baseball!\0"}, .c = PI};
    any_structure_t any_2 = any_1;

    CAPTURE(any_1.a, any_1.b, any_1.c);
    CAPTURE(any_2.a, any_2.b, any_2.c);
    REQUIRE(std::memcmp(&any_1, &any_2, sizeof(any_structure_t)) == 0);
}

TEST_CASE("struct_dereference_pointer_assigned", "[struct]") {
    any_structure_t any_1 = {.a = 32, .b = {"I love baseball!\0"}, .c = PI};
    any_structure_t any_2;
    *(&any_2) = *(&any_1);

    CAPTURE(any_1.a, any_1.b, any_1.c);
    CAPTURE(any_2.a, any_2.b, any_2.c);
    REQUIRE(std::memcmp(&any_1, &any_2, sizeof(any_structure_t)) == 0);
}

TEST_CASE("char_array_initillize", "[string]") {
    char a[PATH_LEN] = {0};
    char b[PATH_LEN] = {'\0'};

    CAPTURE(a, b);
    REQUIRE(std::memcmp(&a, &b, sizeof(char) * PATH_LEN) == 0);

    char c[PATH_LEN];
    std::memset(c, 0, sizeof(char) * PATH_LEN);

    CAPTURE(a, c);
    REQUIRE(std::memcmp(&a, &c, sizeof(char) * PATH_LEN) == 0);
}

TEST_CASE("char_array_set", "[string]") {
    char a[PATH_LEN] = {"I like baseball!\0"};
    char b[PATH_LEN] = "I like baseball!";

    CAPTURE(a, b);
    REQUIRE(std::memcmp(a, b, sizeof(char) * PATH_LEN) == 0);

    // clang-format off
    char c[PATH_LEN] = {'I', ' ',
                        'l', 'i', 'k', 'e', ' ',
                        'b', 'a', 's', 'e', 'b', 'a', 'l', 'l', '!', '\0'};
    // clang-format on
    CAPTURE(a, c);
    REQUIRE(std::memcmp(a, c, sizeof(char) * PATH_LEN) == 0);

    char d[PATH_LEN] = {"I like baseball!"};

    CAPTURE(a, d);
    REQUIRE(std::memcmp(a, d, sizeof(char) * PATH_LEN) == 0);
}