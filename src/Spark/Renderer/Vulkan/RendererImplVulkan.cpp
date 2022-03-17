////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Spark/Renderer/Vulkan/RendererImplVulkan.hpp>
#include <cassert>
#include <iostream>

#ifdef WIN32

#include <Spark/Renderer/Vulkan/Win32/VulkanImplWin32.hpp>
using VulkanImplType = VulkanImplWin32;

#endif

////////////////////////////////////////////////////////////
RendererImplVulkan::RendererImplVulkan()
{
}

////////////////////////////////////////////////////////////
RendererImplVulkan::RendererImplVulkan(const Window& window)
{
	create(window);
}

////////////////////////////////////////////////////////////
RendererImplVulkan::~RendererImplVulkan()
{
	vkDestroyInstance(m_instance, nullptr);
}

////////////////////////////////////////////////////////////
void RendererImplVulkan::create(const Window& window)
{
	m_validationLayers.emplace_back("VK_LAYER_KHRONOS_validation");

	createInstance();
}

////////////////////////////////////////////////////////////
void RendererImplVulkan::createInstance()
{
	assert(checkValidationLayerSupport());

	VkApplicationInfo appInfo{};
	appInfo.sType			   = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName   = "Spark";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName		   = "No Engine";
	appInfo.engineVersion	   = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion		   = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType			= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	auto& extensions = VulkanImplType::getRequiredExtensions();

	createInfo.enabledExtensionCount   = extensions.size();
	createInfo.ppEnabledExtensionNames = extensions.data();
	createInfo.enabledLayerCount	   = 0;
	createInfo.pNext				   = nullptr;

	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
#ifndef NDEBUG
	createInfo.enabledLayerCount   = static_cast<uint32_t>(m_validationLayers.size());
	createInfo.ppEnabledLayerNames = m_validationLayers.data();

	populateDebugMessengerCreateInfo(debugCreateInfo);
	createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
#endif	

	VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);
	assert(result == VK_SUCCESS);
}

////////////////////////////////////////////////////////////
bool RendererImplVulkan::checkValidationLayerSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : m_validationLayers)
	{
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)  return false; 
	}

	return true;
}

////////////////////////////////////////////////////////////
void RendererImplVulkan::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
{
	createInfo				   = {};
	createInfo.sType		   = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
							 VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	createInfo.pfnUserCallback = debugCallback;
}

////////////////////////////////////////////////////////////
VKAPI_ATTR VkBool32 VKAPI_CALL RendererImplVulkan::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT		 messageSeverity,
																 VkDebugUtilsMessageTypeFlagsEXT			 messageType,
																 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
																 void*										 pUserData)
{
	std::cout << "validation layer: " << pCallbackData->pMessage << std::endl;

	return VK_FALSE;
}
