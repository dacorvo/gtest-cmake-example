SET(Main_SRCS
    main.cpp
)

ADD_EXECUTABLE(myApp
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
TARGET_LINK_LIBRARIES(myApp
    libfoo
    libbar
)

INSTALL(TARGETS myApp DESTINATION bin)
