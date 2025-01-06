add_library(platforms "")

target_sources(platforms
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/plat_memory_${OS_SYSTEM}.c
)

target_include_directories(platforms
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)