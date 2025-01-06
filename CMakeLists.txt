cmake_minimum_required(VERSION 3.14)

project(cpp_learning_notes LANGUAGES CXX C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

#include(GNUInstallDirs)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
#    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
#    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
#    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Operating system
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
    set(OS_SYSTEM "windows")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
    set(OS_SYSTEM "linux")
endif()

# External project
include(FetchContent)
message(STATUS "Package spdlog will be used.")
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        8e5613379f5140fefb0b60412fbf1f5406e7c7f8 #release v1.15.0
)

FetchContent_MakeAvailable(spdlog)

add_subdirectory(src)
add_subdirectory(platforms)

enable_testing()
add_subdirectory(tests)