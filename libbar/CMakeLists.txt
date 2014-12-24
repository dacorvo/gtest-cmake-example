SET(libbar_SRCS
    bar.h
    bar.cpp
)

# Declare the library
ADD_LIBRARY(libbar STATIC
    ${libbar_SRCS}
)

TARGET_LINK_LIBRARIES(libbar
    libfoo
)

# Specify here the include directories exported
# by this library
TARGET_INCLUDE_DIRECTORIES(libbar PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
