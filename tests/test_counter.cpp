#include <catch2/catch_all.hpp>
#include <counter.hpp>

extern "C" {
#include "counter.h"
}

TEST_CASE("counter_reset", "[counter]") {
    counter* p_counter = new counter;
    p_counter->reset();

    CAPTURE(p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == 0);
    delete p_counter;
}

TEST_CASE("counter_increase", "[counter]") {
    counter* p_counter = new counter;
    p_counter->reset();

    const int64_t target_numbuer = 127;
    uint64_t running_counts = target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate();
    }

    INFO("Increase test counts: " << target_numbuer
                                  << " answer counts: " << p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == target_numbuer);

    p_counter->reset();
    CAPTURE(p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == 0);

    delete p_counter;
}

TEST_CASE("counter_decrease", "[counter]") {
    counter* p_counter = new counter;
    p_counter->reset();

    const int64_t target_numbuer = -128;
    uint64_t running_counts = (target_numbuer >= 0) ? (target_numbuer) : (-target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate();
    }

    INFO("Decrease test counts: " << target_numbuer
                                  << " answer counts: " << p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == target_numbuer);

    p_counter->reset();
    CAPTURE(p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == 0);

    delete p_counter;
}

TEST_CASE("counter_mixed_+-", "[counter]") {
    counter* p_counter = new counter;
    p_counter->reset();

    // Increase
    const int64_t increase_target_numbuer = 234;
    uint64_t running_counts = increase_target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate();
    }

    // Decrease
    const int64_t decrease_target_numbuer = -123;
    running_counts =
        (decrease_target_numbuer >= 0) ? (decrease_target_numbuer) : (-decrease_target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate();
    }

    INFO("Mixed test counts: " << (increase_target_numbuer + decrease_target_numbuer)
                               << " answer counts: " << p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == (increase_target_numbuer + decrease_target_numbuer));

    p_counter->reset();
    CAPTURE(p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == 0);

    delete p_counter;
}

TEST_CASE("counter_mixed_-+", "[counter]") {
    counter* p_counter = new counter;
    p_counter->reset();

    // Decrease
    const int64_t decrease_target_numbuer = -345;
    uint64_t running_counts =
        (decrease_target_numbuer >= 0) ? (decrease_target_numbuer) : (-decrease_target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate();
    }

    // Increase
    const int64_t increase_target_numbuer = 678;
    running_counts = increase_target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate();
    }

    INFO("Mixed test counts: " << (increase_target_numbuer + decrease_target_numbuer)
                               << " answer counts: " << p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == (increase_target_numbuer + decrease_target_numbuer));

    p_counter->reset();
    CAPTURE(p_counter->getCounts());
    REQUIRE(p_counter->getCounts() == 0);

    delete p_counter;
}

TEST_CASE("counter_reset_c", "[counter]") {
    struct counter_obj* p_counter = new_counter_obj();
    p_counter->reset(p_counter);

    CAPTURE(p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == 0);

    delete_counter_obj(p_counter);
}

TEST_CASE("counter_increase_c", "[counter]") {
    struct counter_obj* p_counter = new_counter_obj();
    p_counter->reset(p_counter);

    const int64_t target_numbuer = 127;
    uint64_t running_counts = target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate(p_counter);
    }

    INFO("Increase test counts: " << target_numbuer
                                  << " answer counts: " << p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == target_numbuer);

    p_counter->reset(p_counter);
    CAPTURE(p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == 0);

    delete_counter_obj(p_counter);
}

TEST_CASE("counter_decrease_c", "[counter]") {
    struct counter_obj* p_counter = new_counter_obj();
    p_counter->reset(p_counter);

    const int64_t target_numbuer = -128;
    uint64_t running_counts = (target_numbuer >= 0) ? (target_numbuer) : (-target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate(p_counter);
    }

    INFO("Decrease test counts: " << target_numbuer
                                  << " answer counts: " << p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == target_numbuer);

    p_counter->reset(p_counter);
    CAPTURE(p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == 0);

    delete_counter_obj(p_counter);
}

TEST_CASE("counter_mixed_+-_c", "[counter]") {
    struct counter_obj* p_counter = new_counter_obj();
    p_counter->reset(p_counter);

    // Increase
    const int64_t increase_target_numbuer = 234;
    uint64_t running_counts = increase_target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate(p_counter);
    }

    // Decrease
    const int64_t decrease_target_numbuer = -123;
    running_counts =
        (decrease_target_numbuer >= 0) ? (decrease_target_numbuer) : (-decrease_target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate(p_counter);
    }

    INFO("Mixed test counts: " << (increase_target_numbuer + decrease_target_numbuer)
                               << " answer counts: " << p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) ==
            (increase_target_numbuer + decrease_target_numbuer));

    p_counter->reset(p_counter);
    CAPTURE(p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == 0);

    delete_counter_obj(p_counter);
}

TEST_CASE("counter_mixed_-+_c", "[counter]") {
    struct counter_obj* p_counter = new_counter_obj();
    p_counter->reset(p_counter);

    // Decrease
    const int64_t decrease_target_numbuer = -345;
    uint64_t running_counts =
        (decrease_target_numbuer >= 0) ? (decrease_target_numbuer) : (-decrease_target_numbuer);
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->depreciate(p_counter);
    }

    // Increase
    const int64_t increase_target_numbuer = 678;
    running_counts = increase_target_numbuer;
    for (uint64_t index = 0; index < running_counts; index++) {
        p_counter->accumulate(p_counter);
    }

    INFO("Mixed test counts: " << (increase_target_numbuer + decrease_target_numbuer)
                               << " answer counts: " << p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) ==
            (increase_target_numbuer + decrease_target_numbuer));

    p_counter->reset(p_counter);
    CAPTURE(p_counter->get_counts(p_counter));
    REQUIRE(p_counter->get_counts(p_counter) == 0);

    delete_counter_obj(p_counter);
}