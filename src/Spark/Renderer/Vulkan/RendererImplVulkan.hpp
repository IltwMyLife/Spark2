#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Spark/Renderer/RendererImpl.hpp>
#include <vector>
#include <vulkan/vulkan.hpp>

////////////////////////////////////////////////////////////
/// \brief Vulkan RendererImpl
///
////////////////////////////////////////////////////////////
class RendererImplVulkan final : public RendererImpl
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// This constructor doesn't actually create the renderer,
	/// use the other constructors or call create() to do so.
	///
	////////////////////////////////////////////////////////////
	RendererImplVulkan();

	////////////////////////////////////////////////////////////
	/// \brief Create renderer
	///
	/// \param window Window
	///
	////////////////////////////////////////////////////////////
	RendererImplVulkan(const Window& window);

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// Destroy renderer.
	///
	////////////////////////////////////////////////////////////
	~RendererImplVulkan() override;

public:

	////////////////////////////////////////////////////////////
	/// \brief Create renderer
	///
	/// \param window Window
	///
	////////////////////////////////////////////////////////////
	void create(const Window& window) override;

private:

	////////////////////////////////////////////////////////////
	/// \brief Create instance
	///
	/// Create VkInstance - vulkan handle.
	///
	////////////////////////////////////////////////////////////
	void createInstance();

	////////////////////////////////////////////////////////////
	/// \brief Check validation layres support
	///
	/// \return Validation layers available?
	///
	////////////////////////////////////////////////////////////
	bool checkValidationLayerSupport();

	////////////////////////////////////////////////////////////
	/// \brief Populate debug messenger create info
	///
	////////////////////////////////////////////////////////////
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	////////////////////////////////////////////////////////////
	/// \brief Debug callback
	/// 
	/// Print vulkan errors
	///
	////////////////////////////////////////////////////////////
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT		messageSeverity,
														VkDebugUtilsMessageTypeFlagsEXT				messageType,
														const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
														void*										pUserData);

private:

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	std::vector<const char*> m_validationLayers; // Validation layers for debugging vulkan
	VkInstance				 m_instance;		 //!< Vulkan handle
};
