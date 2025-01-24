#include <catch2/catch_all.hpp>
#include <cstdint>

typedef struct white {
    uint16_t width;
    uint16_t height;
    uint16_t bad_pixels;
    uint16_t white_pixels;
    uint8_t xxx_score;
    uint8_t yyy_score;
} white_t;

typedef struct dark {
    uint16_t width;
    uint16_t height;
    uint16_t bad_pixels;
    uint16_t dark_pixels;
    uint8_t iii_score;
    uint8_t jjj_score;
} dark_t;

typedef union sensor_quality {
    white_t white;
    dark_t dark;
} sensor_quality_t;

TEST_CASE("union_structure_shared_memory", "[union]") {
    sensor_quality_t sensor_test = {0};
    sensor_test.white.width = 52;
    sensor_test.white.height = 48;
    sensor_test.white.bad_pixels = 2;
    sensor_test.white.white_pixels = 1;
    sensor_test.white.xxx_score = 20;
    sensor_test.white.yyy_score = 30;

    /*sensor_test.white and sensor_test.dark share the same memory.*/
    size_t size_of_white = sizeof(sensor_test.white);
    size_t size_of_dark = sizeof(sensor_test.dark);
    CAPTURE(&(sensor_test.white.width), &(sensor_test.dark.width));
    CAPTURE(size_of_white, size_of_dark);
    REQUIRE(&(sensor_test.white.width) == &(sensor_test.dark.width));
    REQUIRE(size_of_white == size_of_dark);

    /*check memory they are the same memory address.*/
    REQUIRE(&(sensor_test.white.white_pixels) == &(sensor_test.dark.dark_pixels));
    REQUIRE(&(sensor_test.white.xxx_score) == &(sensor_test.dark.iii_score));
    REQUIRE(&(sensor_test.white.yyy_score) == &(sensor_test.dark.jjj_score));

    /*check store value in the same memory address.*/
    REQUIRE(sensor_test.white.white_pixels == sensor_test.dark.dark_pixels);
    REQUIRE(sensor_test.white.xxx_score == sensor_test.dark.iii_score);
    REQUIRE(sensor_test.white.yyy_score == sensor_test.dark.jjj_score);

    /*write dark value and check again.*/
    sensor_test.dark.dark_pixels = 3;
    sensor_test.dark.iii_score = 15;
    sensor_test.dark.jjj_score = 26;
    REQUIRE(sensor_test.white.white_pixels == 3);
    REQUIRE(sensor_test.white.xxx_score == 15);
    REQUIRE(sensor_test.white.yyy_score == 26);
}