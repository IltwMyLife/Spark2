////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Spark/Application.hpp"

////////////////////////////////////////////////////////////
Application::Application()
{
	m_window.create("Spark", 800, 600);
}

////////////////////////////////////////////////////////////
Application::~Application()
{
}

////////////////////////////////////////////////////////////
void Application::run()
{
	while (m_window.isOpen()) m_window.processMessages(); 
}
