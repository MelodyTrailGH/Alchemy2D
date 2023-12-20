#include <Alchemy2D/Graphics/Window.hh>
#include <Alchemy2D/Utility/Math/Vector2.hh>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <exception>

namespace Alchemy2D::Graphics {

	// Bro this goofy function is nearly impossible to read.
	SDL_Window* Window::CreateWindow( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name,
	                                  std::uint32 flags ) {
		if ( ( SDL_WasInit( SDL_INIT_VIDEO ) != SDL_INIT_VIDEO ) && ( SDL_InitSubSystem( SDL_INIT_VIDEO ) != 0 ) ) {
			std::terminate( );
		}

		std::uint32_t _flags = 0;
		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Fullscreen ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::Fullscreen ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_FULLSCREEN_DESKTOP );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::ExclusiveFullscreen ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::ExclusiveFullscreen ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_FULLSCREEN );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Hidden ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::Hidden ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_HIDDEN );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Borderless ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::Borderless ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_BORDERLESS );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Resizable ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::Resizable ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_RESIZABLE );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Minimized ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::Minimized ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_MINIMIZED );
		} else if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::Maximized ) ) ==
		            static_cast< std::uint32_t >( WindowFlag::Maximized ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_MAXIMIZED );
		}

		if ( ( static_cast< std::uint32_t >( flags ) & static_cast< std::uint32_t >( WindowFlag::HighDPI ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::HighDPI ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_ALLOW_HIGHDPI );
		}

		if ( ( static_cast< std::uint32_t >( flags ) | static_cast< std::uint32_t >( WindowFlag::AlwaysOnTop ) ) ==
		     static_cast< std::uint32_t >( WindowFlag::AlwaysOnTop ) ) {
			_flags = _flags | static_cast< std::uint32_t >( SDL_WINDOW_ALWAYS_ON_TOP );
		}

		return SDL_CreateWindow( name.c_str( ), static_cast< std::int32_t >( position.getX( ) ),
		                         static_cast< std::int32_t >( position.getY( ) ), static_cast< std::int32_t >( size.getX( ) ),
		                         static_cast< std::int32_t >( size.getY( ) ),
		                         _flags | static_cast< std::uint32_t >( SDL_WINDOW_OPENGL ) );
	}

	Window::Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name, WindowFlag flags )
	    : _window( CreateWindow( position, size, name, flags ) ), _id( SDL_GetWindowID( _window ) ) {
	}

	Window::Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name )
	    : _window( CreateWindow( position, size, name, WindowFlag::None ) ), _id( SDL_GetWindowID( _window ) ) {
	}

	Window::Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
	                const std::string& name, WindowFlag flags )
	    : _window( CreateWindow( Utility::Math::Vector2{ static_cast< float >( xPosition ), static_cast< float >( yPosition ) },
	                             Utility::Math::Vector2{ static_cast< float >( width ), static_cast< float >( height ) }, name,
	                             flags ) ),
	      _id( SDL_GetWindowID( _window ) ) {
	}

	Window::Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
	                const std::string& name )
	    : _window( CreateWindow( Utility::Math::Vector2{ static_cast< float >( xPosition ), static_cast< float >( yPosition ) },
	                             Utility::Math::Vector2{ static_cast< float >( width ), static_cast< float >( height ) }, name,
	                             WindowFlag::None ) ),
	      _id( SDL_GetWindowID( _window ) ) {
	}

	Window::~Window( ) {
		SDL_DestroyWindow( this->_window );
	}

	std::uint32_t Window::getId( ) const {
		return this->_id;
	}

	void Window::hide( ) const {
		SDL_HideWindow( this->_window );
	}
	void Window::show( ) const {
		SDL_ShowWindow( this->_window );
	}

} // namespace Alchemy2D::Graphics