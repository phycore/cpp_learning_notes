add_library(structure INTERFACE)

set_property(TARGET structure PROPERTY C_STANDARD 99)

target_include_directories(structure
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(structure
    INTERFACE
        platforms
)