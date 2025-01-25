add_library(bitwise INTERFACE)

set_property(TARGET bitwise PROPERTY C_STANDARD 99)

target_include_directories(bitwise
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)