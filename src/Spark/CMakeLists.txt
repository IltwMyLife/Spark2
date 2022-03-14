add_subdirectory(Window)

set(INCROOT ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME})
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME})

set(SRC
    ${SRCROOT}/Main.cpp

    ${INCROOT}/Application.hpp
    ${SRCROOT}/Application.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE spark-window)