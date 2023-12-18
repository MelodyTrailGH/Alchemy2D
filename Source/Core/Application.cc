#include "SDL_events.h"
#include <Alchemy2D/Core/Application.hh>
#include <SDL2/SDL.h>

namespace Alchemy2D {
	Application::~Application( ) {
		SDL_Quit( );
	}
	void Application::setWindowManager( Graphics::WindowManager *windowManager ) {
		this->WindowManager = windowManager;
	}

	Graphics::WindowManager *Application::getWindowManager( ) {
		return this->WindowManager;
	}

	void Application::run( ) {
		while ( !this->shouldClose ) {
			if ( WindowManager->getWindowCount( ) == 0 ) {
				this->shouldClose = true;
			}
			SDL_Event event;
#pragma unroll
			while ( SDL_PollEvent( &event ) != 0 ) {
				if ( event.type == SDL_WINDOWEVENT ) {
					WindowManager->update( &event );
				}
				if ( event.type == SDL_QUIT ) {
					this->shouldClose = true;
				}
			}
		}
	}
} // namespace Alchemy2D