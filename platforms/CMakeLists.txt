add_library(platforms "")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

target_sources(platforms
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/plat_memory_${OS_SYSTEM}.c
)

target_include_directories(platforms
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)