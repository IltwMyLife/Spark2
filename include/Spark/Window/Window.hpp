#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>

class WindowImpl;

////////////////////////////////////////////////////////////
/// \brief Window
///
////////////////////////////////////////////////////////////
class Window
{
public:
	
	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// This constructor doesn't actually create the window,
	/// use the other constructors or call create() to do so.
	///
	////////////////////////////////////////////////////////////
	Window();

	////////////////////////////////////////////////////////////
	/// \brief Constructor
	/// 
	/// Create window implementation.
	///
	/// \param title  Title of the window
	/// \param width  Width of the window
	/// \param height Height of the window
	///
	////////////////////////////////////////////////////////////
	Window(std::string title, uint32_t width, uint32_t height);

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// Destroy window implementation.
	///
	////////////////////////////////////////////////////////////
	~Window();

public:
	
	////////////////////////////////////////////////////////////
	/// \brief Create window
	///
	/// \param title Title of the window
	/// \param width Width of the window
	/// \param height Height of the window
	///
	////////////////////////////////////////////////////////////
	void create(std::string title, uint32_t width, uint32_t height);

	////////////////////////////////////////////////////////////
	/// \brief Destroy window
	///
	/// Close the window and destroy all the attached resources.
	///
	////////////////////////////////////////////////////////////
	void destroy();

	////////////////////////////////////////////////////////////
	/// \brief Proccess messages
	///
	/// \return True if have another message.
	///
	////////////////////////////////////////////////////////////
	bool processMessages();

	////////////////////////////////////////////////////////////
	/// \brief Tell whether or not the window is open
	///
	/// \return True if the window is open, false if it has been closed.
	///
	////////////////////////////////////////////////////////////
	bool isOpen() const;

private:
	
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	WindowImpl* m_impl; //!< Window implementation 
};