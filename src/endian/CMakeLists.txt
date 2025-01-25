add_library(endian INTERFACE)

set_property(TARGET endian PROPERTY C_STANDARD 99)

target_include_directories(endian
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)