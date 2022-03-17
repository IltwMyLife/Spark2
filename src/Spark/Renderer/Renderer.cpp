////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Spark/Renderer/Renderer.hpp>
#include <Spark/Renderer/Vulkan/RendererImplVulkan.hpp>

////////////////////////////////////////////////////////////
Renderer::Renderer(Renderer::API api)
{
	switch (api)
	{
		case Renderer::API::Vulkan: m_impl = new RendererImplVulkan(); break;
		default: m_impl = nullptr;
	}
}

////////////////////////////////////////////////////////////
Renderer::Renderer(Renderer::API api, const Window& window)
{
	switch (api)
	{
		case Renderer::API::Vulkan: m_impl = new RendererImplVulkan(window); break;
		default: m_impl = nullptr;
	}
}

////////////////////////////////////////////////////////////
Renderer::~Renderer()
{
	delete m_impl;
}

////////////////////////////////////////////////////////////
void Renderer::create(const Window& window)
{
	m_impl->create(window);
}
