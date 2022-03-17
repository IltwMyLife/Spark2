////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Spark/Renderer/Vulkan/Win32/VulkanImplWin32.hpp>
#include <vulkan/vulkan.hpp>
#include <Windows.h>
#include <vulkan/vulkan_win32.h>

////////////////////////////////////////////////////////////
const std::vector<const char*>& VulkanImplWin32::getRequiredExtensions()
{
	static std::vector<const char*> extensions;

	extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
	extensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);

	return extensions;
}
