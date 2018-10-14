file(GLOB SRCS *.cpp)

add_executable(testfoo ${SRCS})

target_link_libraries()(testfoo
    libfoo
    libgtest
    libgmock
)

add_test(NAME testfoo
         COMMAND testfoo)
