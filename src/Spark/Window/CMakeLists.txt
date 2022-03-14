set(LIB_NAME spark-window)

set(INCROOT ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/Window)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/Window)

set(SRC
    ${INCROOT}/Window.hpp
    ${SRCROOT}/Window.cpp

    ${SRCROOT}/WindowImpl.hpp
    ${SRCROOT}/WindowImpl.cpp
)

if(WIN32)
    set(PLATFORM_SRC 
        ${SRCROOT}/Win32/WindowImplWin32.hpp
        ${SRCROOT}/Win32/WindowImplWin32.cpp
    )
endif()

add_library(${LIB_NAME} STATIC ${SRC} ${PLATFORM_SRC})

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)