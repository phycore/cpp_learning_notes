cmake_minimum_required(VERSION 3.14)
project(cpp_learning_notes CXX C)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
if(MSVC)
#error c7555: use of designated initializers requires at least '/std:c++20
    set(CMAKE_CXX_STANDARD 20)
endif()
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp)

target_link_libraries(main
    PUBLIC
        spdlog
        playground
)