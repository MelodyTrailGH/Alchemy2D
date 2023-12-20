#include "Alchemy2D/Graphics/Window.hh"
#include <Alchemy2D/Core/Application.hh>
#include <Alchemy2D/Graphics/WindowManager.hh>

#include <SDL2/SDL_events.h>
namespace Alchemy2D::Graphics {
	void WindowManager::addWindow( Window* window ) {
		this->windows.push_back( window );
	}

	std::uint64_t WindowManager::getWindowCount( ) const {
		return this->windows.size( );
	}

	void WindowManager::update( const SDL_Event* event ) {
		for ( std::uint64_t windowIndex = 0; windowIndex < this->getWindowCount( ); ++windowIndex ) {
			const Window* window = this->windows.at( windowIndex );
			if ( event->window.windowID == window->getId( ) ) {
				switch ( event->window.event ) {
				case SDL_WINDOWEVENT_CLOSE: {
					window->hide( );
					this->windows.erase( std::find( this->windows.begin( ), this->windows.end( ), window ) );
					continue;
				}

				default: {
					continue;
				}
				}
			}
		}
	}
} // namespace Alchemy2D::Graphics
