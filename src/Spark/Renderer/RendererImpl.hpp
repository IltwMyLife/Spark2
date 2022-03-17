#pragma once	

class Window;

////////////////////////////////////////////////////////////
/// \brief Abstract base class of Renderer implementation 
///
////////////////////////////////////////////////////////////
class RendererImpl
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// This constructor doesn't actually create the renderer,
	/// use the other constructors or call create() to do so.
	///
	////////////////////////////////////////////////////////////
	RendererImpl() = default;
	
	////////////////////////////////////////////////////////////
	/// \brief Create renderer
	///
	/// \param window Window
	///
	////////////////////////////////////////////////////////////
	RendererImpl(const Window& window);

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// Destroy renderer.
	///
	////////////////////////////////////////////////////////////
	virtual ~RendererImpl() = default;

public:

	////////////////////////////////////////////////////////////
	/// \brief Create renderer
	///
	/// \param window Window
	///
	////////////////////////////////////////////////////////////
	virtual void create(const Window& window) = 0;
};