file(GLOB SRCS *.cpp)

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")

endif()

add_executable(testfoo ${SRCS})

target_link_libraries(testfoo
    libfoo
    libgtest
    libgmock
)

add_test(NAME testfoo
         COMMAND testfoo)
