add_library(drink "")

target_sources(drink
    PRIVATE
        recipe.cpp
        coke.cpp
        zero_cola.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/recipe.hpp
        ${CMAKE_CURRENT_LIST_DIR}/coke.hpp
        ${CMAKE_CURRENT_LIST_DIR}/zero_cola.hpp
)

target_include_directories(drink
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)