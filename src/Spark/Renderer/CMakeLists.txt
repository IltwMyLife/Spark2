set(LIB_NAME spark-renderer)

set(INCROOT ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/Renderer)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/Renderer)

set(SRC
    ${INCROOT}/Renderer.hpp
    ${SRCROOT}/Renderer.cpp

    ${SRCROOT}/RendererImpl.hpp
    ${SRCROOT}/RendererImpl.cpp

    ${SRCROOT}/Vulkan/RendererImplVulkan.hpp
    ${SRCROOT}/Vulkan/RendererImplVulkan.cpp

    
)

if(WIN32)
    set(PLATFORM_SRC
        ${SRCROOT}/Vulkan/Win32/VulkanImplWin32.hpp
        ${SRCROOT}/Vulkan/Win32/VulkanImplWin32.cpp
    )
endif()

add_library(${LIB_NAME} STATIC ${SRC} ${PLATFORM_SRC})

find_package(Vulkan REQUIRED)
target_link_libraries(${LIB_NAME} PRIVATE Vulkan::Vulkan)

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)