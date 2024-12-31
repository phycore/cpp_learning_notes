add_library(counter "")

target_sources(counter
    PRIVATE
        counter.cpp
        counter_impl.c
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/counter.hpp
        ${CMAKE_CURRENT_LIST_DIR}/counter.h
)

target_include_directories(counter
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(counter
    PRIVATE
        platforms
)