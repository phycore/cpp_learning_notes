add_library(mathematics "")

target_sources(mathematics
    PRIVATE
        mathematics.c
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/mathematics.h
)

target_include_directories(mathematics
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)