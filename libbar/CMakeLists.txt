set(libbar_SRCS
    bar.h
    bar.cpp
)

# Declare the library
add_library(libbar STATIC
    ${libbar_SRCS}
)

target_link_libraries(libbar
    libfoo
)

# Specify here the include directories exported
# by this library
target_include_directories(libbar PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
