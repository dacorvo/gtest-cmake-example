FIND_PACKAGE(Threads REQUIRED)

# Enable ExternalProject CMake module
INCLUDE(ExternalProject)

# Download and install GoogleTest
EXTERNALPROJECT_ADD(
    gtest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Create a libgtest target to be used as a dependency by test programs
ADD_LIBRARY(libgtest IMPORTED STATIC GLOBAL)
ADD_DEPENDENCIES(libgtest gtest)

# Set gtest properties
EXTERNALPROJECT_GET_PROPERTY(gtest source_dir binary_dir)
SET_TARGET_PROPERTIES(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
INCLUDE_DIRECTORIES("${source_dir}/include")

# Download and install GoogleMock
EXTERNALPROJECT_ADD(
    gmock
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    # Disable install step
    INSTALL_COMMAND ""
)

# Create a libgmock target to be used as a dependency by test programs
ADD_LIBRARY(libgmock IMPORTED STATIC GLOBAL)
ADD_DEPENDENCIES(libgmock gmock)

# Set gmock properties
EXTERNALPROJECT_GET_PROPERTY(gmock source_dir binary_dir)
SET_TARGET_PROPERTIES(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
INCLUDE_DIRECTORIES("${source_dir}/include")

ADD_SUBDIRECTORY(testfoo)
