#include <catch2/catch_all.hpp>

/*
Tips:
If const is on the * right, then it's a const pointer.
If const is on the * left, then it's a const integer.
*/

TEST_CASE("a pointer to a \"const integer\" formula 1", "[pointer]") {
    const int a = 2;
    int b = 3;

    const int* p_int = &a;
#if 0
    *p_int = 7;  // build fail!
#endif
    p_int = &b;  // fine!
    REQUIRE(p_int == &b);
    REQUIRE(*p_int == b);
}

TEST_CASE("a pointer to a \"const integer\" formula 2", "[pointer]") {
    const int a = 2;
    int b = 3;

    int const* p_int = &a;
#if 0
    *p_int = 7;  // build fail!
#endif
    p_int = &b;  // fine!
    REQUIRE(p_int == &b);
    REQUIRE(*p_int == b);
}

TEST_CASE("a \"const pointer\" to an integer", "[pointer]") {
    int a = 2;
    int b = 3;

    int* const p_int = &a;
#if 0
    p_int = &b;  // build fail!
#endif
    *p_int = b;  // fine!
    REQUIRE(p_int == &a);
    REQUIRE(*p_int == b);
}

TEST_CASE("a \"const pointer\" to a const integer", "[pointer]") {
    const int a = 2;
    int b = 3;

    const int* const p_int = &a;
#if 0
    p_int = &b;  // build fail!
    *pint = b;   // build fail!
#endif

    REQUIRE(p_int == &a);
    REQUIRE(*p_int == a);
}

TEST_CASE("a pointer to a \"const pointer\" to a \"const integer\"", "[pointer]") {
    const int a = 2;
    const int* const p_a = &a;

    // there are two *, it's a pointer to pointer.
    const int* const* pp_int = &p_a;
    REQUIRE(**pp_int == a);
    REQUIRE(*p_a == a);
    REQUIRE(*p_a == **pp_int);

    // pp_int could change store address.
    const int b = 3;
    const int* const p_b = &b;
    pp_int = &p_b;
    REQUIRE(**pp_int == b);
    REQUIRE(*p_b == b);
    REQUIRE(*p_b == **pp_int);
}