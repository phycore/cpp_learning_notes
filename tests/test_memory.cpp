#include <catch2/catch_all.hpp>
#include <cstdint>

extern "C" {
#include "plat_memory.h"
#include "plat_string.h"
}

#define ROWS (size_t)21
#define CLMS (size_t)108

TEST_CASE("array of pointers.", "[memory]") {
    char* books[] = {(char*)"Harry Potter and the Sorcerer\'s Stone",
                     (char*)"Harry Potter and the Chamber of Secrets",
                     (char*)"Harry Potter and the Prisoner of Azkaban",
                     (char*)"Harry Potter and the Goblet of Fire",
                     (char*)"Harry Potter and the Order of the Phoenix",
                     (char*)"Harry Potter and the Half-Blood Prince",
                     (char*)"Harry Potter and the Deathly Hallows"};

    size_t items_of_books = sizeof(books) / sizeof(books[0]);
    REQUIRE(items_of_books == 7);

    CAPTURE(books[2], *(books + 2));
    REQUIRE(strcmp(books[2], *(books + 2)) == 0);
    REQUIRE(strcmp(books[3], "Harry Potter and the Goblet of Fire") == 0);
}

TEST_CASE("1D memory allocation, dereference operation and free, pointer.", "[memory]") {
    /*memory allocate*/
    size_t alloc_size = ((size_t)PATH_LEN * sizeof(char));
    char* p_char = (char*)plat_allocate(alloc_size);
    REQUIRE(p_char != nullptr);

    /*memory free*/
    PLAT_FREE(p_char);
    REQUIRE(p_char == nullptr);
}

TEST_CASE("2D non-continue memory allocation, dereference operation and free, pointer to pointer",
          "[memory]") {
    /*memory allocate*/
    size_t row_size = (ROWS * sizeof(int32_t*));
    int32_t** matrix = (int32_t**)plat_allocate(row_size);
    REQUIRE(matrix != nullptr);

    size_t clm_size = (CLMS * sizeof(int32_t));
    for (size_t index = 0; index < ROWS; index++) {
        matrix[index] = (int32_t*)plat_allocate(clm_size);
        REQUIRE(matrix[index] != nullptr);
    }

    /*matrix operation*/
    for (size_t row_index = 0; row_index < ROWS; row_index++) {
        for (size_t clm_index = 0; clm_index < CLMS; clm_index++) {
            *(matrix[row_index] + clm_index) = (int32_t)(row_index * clm_index);
        }
    }
    REQUIRE(*(matrix[0] + 0) == 0);
    REQUIRE(*(*(matrix + 0) + 0) == 0);

    REQUIRE(*(matrix[1] + 1) == 1);
    REQUIRE(*(*(matrix + 1) + 1) == 1);

    REQUIRE(*(matrix[2] + 3) == 6);
    REQUIRE(*(*(matrix + 2) + 3) == 6);

    /*check memory not coninue*/
#if 0  // Be careful buffer overflow. So disable these REQUIRE statement.
    REQUIRE((matrix[1] + 0) != (*matrix + CLMS));
    REQUIRE((matrix[2] + 3) != (*matrix + (2*CLMS + 3)));
#endif

    /*memory free*/
    for (size_t index = 0; index < ROWS; index++) {
        PLAT_FREE(matrix[index]);
        REQUIRE(matrix[index] == nullptr);
    }
    PLAT_FREE(matrix);
    REQUIRE(matrix == nullptr);
}

TEST_CASE("2D continue memory allocation, dereference operation and free, pointer to pointer",
          "[memory]") {
    /*memory allocate*/
    size_t row_size = (ROWS * sizeof(int32_t*));
    int32_t** matrix = (int32_t**)plat_allocate(row_size);
    REQUIRE(matrix != nullptr);

    size_t clm_size = (CLMS * sizeof(int32_t));
    matrix[0] = (int32_t*)plat_allocate(ROWS * clm_size);
    for (size_t index = 0; index < ROWS; index++) {
        matrix[index] = matrix[0] + (index * CLMS);
        REQUIRE(matrix[index] != nullptr);
    }

    /*matrix operation*/
    for (size_t row_index = 0; row_index < ROWS; row_index++) {
        for (size_t clm_index = 0; clm_index < CLMS; clm_index++) {
            *(matrix[row_index] + clm_index) = (int32_t)(row_index * clm_index);
        }
    }
    REQUIRE(*(matrix[0] + 0) == 0);
    REQUIRE(*(*(matrix + 0) + 0) == 0);

    REQUIRE(*(matrix[1] + 1) == 1);
    REQUIRE(*(*(matrix + 1) + 1) == 1);

    REQUIRE(*(matrix[2] + 3) == 6);
    REQUIRE(*(*(matrix + 2) + 3) == 6);

    /*check memory continue*/
    REQUIRE((matrix[0] + 1) == (*matrix + 1));
    REQUIRE((matrix[1] + 0) == (*matrix + CLMS));
    REQUIRE((matrix[2] + 3) == (*matrix + (2 * CLMS + 3)));

    /*memory free*/
    PLAT_FREE(matrix[0]);
    REQUIRE(matrix[0] == nullptr);
    PLAT_FREE(matrix);
    REQUIRE(matrix == nullptr);
}

TEST_CASE(
    "2D continue memory allocation, dereference operation and free, a pointer to an array of "
    "integers",
    "[memory]") {
    /*memory allocate*/
    int32_t(*matrix)[CLMS] = {0}; /*matrix is a pointer to an array of integers.*/

    size_t alloc_size = ROWS * sizeof(*matrix);
    matrix = (int32_t(*)[CLMS])plat_allocate(alloc_size);
    REQUIRE(matrix != nullptr);

    /*matrix operaitons*/
    for (size_t row_index = 0; row_index < ROWS; row_index++) {
        for (size_t clm_index = 0; clm_index < CLMS; clm_index++) {
            matrix[row_index][clm_index] = (int32_t)(row_index * clm_index);
        }
    }
    REQUIRE(matrix[0][0] == 0);
    REQUIRE(matrix[1][1] == 1);
    REQUIRE(matrix[2][3] == 6);

    /*check memory continue*/
    CAPTURE(&matrix[0][0], &matrix[0][1]);
    REQUIRE((&matrix[0][0] + 1) == &matrix[0][1]);
    CAPTURE(&matrix[0][0], &matrix[1][0]);
    REQUIRE((&matrix[0][0] + CLMS) == &matrix[1][0]);

    /*memory free*/
    PLAT_FREE(matrix);
    REQUIRE(matrix == nullptr);
}