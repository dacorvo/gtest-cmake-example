set(libfoo_SRCS
    foo.h
    foo.cpp
    ibar.h
)

# Declare the library
add_library(libfoo STATIC
    ${libfoo_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libfoo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
