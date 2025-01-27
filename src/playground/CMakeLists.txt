add_library(playground "")

target_sources(playground
    PRIVATE
        playground.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/playground.hpp
)

target_include_directories(playground
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(playground
    PUBLIC
        spdlog
)