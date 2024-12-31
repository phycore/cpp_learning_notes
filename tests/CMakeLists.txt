cmake_minimum_required(VERSION 3.14)
project(cpp_learning_notes_utests CXX C)

include(FetchContent)
message(STATUS "Package C++ Catch2 Test framework will be downloaded and used.")
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        53d0d913a422d356b23dd927547febdf69ee9081 #v3.5.0
)
FetchContent_MakeAvailable(Catch2)

set(CPP_LEARN_NOTES_UTESTS_SOURCES
    test_counter.cpp
)

enable_testing()

function(cpp_learn_utests test_target test_lib)
    add_executable(${test_target} ${CPP_LEARN_NOTES_UTESTS_SOURCES})

    target_link_libraries(${test_target} PRIVATE ${test_lib})
    target_link_libraries(${test_target} PRIVATE Catch2::Catch2WithMain)

    add_test(NAME ${test_target} COMMAND ${test_target})
    set_tests_properties(${test_target} PROPERTIES FAIL_REGULAR_EXPRESSION "[^a-z]Error;ERROR;Failed")
endfunction()

cpp_learn_utests(counter_utests counter)