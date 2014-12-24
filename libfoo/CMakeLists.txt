SET(libfoo_SRCS
    foo.h
    foo.cpp
    ibar.h
)

# Declare the library
ADD_LIBRARY(libfoo STATIC
    ${libfoo_SRCS}
)

# Specify here the include directories exported
# by this library
TARGET_INCLUDE_DIRECTORIES(libfoo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
