cmake_minimum_required(VERSION 3.14)
project(cpp_learning_notes_utests CXX C)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
if(MSVC)
#error c7555: use of designated initializers requires at least '/std:c++20
    set(CMAKE_CXX_STANDARD 20)
endif()
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
message(STATUS "Package C++ Catch2 Test framework will be downloaded and used.")
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        53d0d913a422d356b23dd927547febdf69ee9081 #v3.5.0
)
FetchContent_MakeAvailable(Catch2)

enable_testing()

function(add_test_target target_name test_lib)
    target_link_libraries(${target_name} PRIVATE ${test_lib})
    target_link_libraries(${target_name} PRIVATE platforms)
    target_link_libraries(${target_name} PRIVATE Catch2::Catch2WithMain)

    add_test(NAME ${target_name} COMMAND ${target_name})
endfunction()

add_library(dummy INTERFACE) # dummy is empty source.

add_executable(counter_utests test_counter.cpp)
add_test_target(counter_utests counter)

add_executable(structure_utests test_struct.cpp)
add_test_target(structure_utests structure) #structure is header only lib.

add_executable(pointer_utests test_pointer.cpp)
add_test_target(pointer_utests dummy)

add_executable(memory_utests test_memory.cpp)
add_test_target(memory_utests dummy)

add_executable(math_utests test_math.cpp)
add_test_target(math_utests mathematics)

add_executable(alignment_utests test_alignment.cpp)
add_test_target(alignment_utests dummy)

add_executable(union_utests test_union.cpp)
add_test_target(union_utests dummy)

add_executable(endian_utests test_endian.cpp)
add_test_target(endian_utests endian)

add_executable(bitwise_utests test_bitwise.cpp)
add_test_target(bitwise_utests bitwise)

set_tests_properties(
    counter_utests
    structure_utests
    pointer_utests
    memory_utests
    math_utests
    alignment_utests
    union_utests
    endian_utests
    bitwise_utests
    PROPERTIES FAIL_REGULAR_EXPRESSION "[^a-z]Error;ERROR;Failed"
)