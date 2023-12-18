#pragma once

#include <Alchemy2D/Graphics/Window.hh>
#include <SDL2/SDL_events.h>
#include <functional>
#include <vector>

namespace Alchemy2D::Graphics {

	class WindowManager {
	  private:
		std::vector< Window* > windows;

	  public:
		WindowManager( ) = default;
		~WindowManager( ) = default;

		std::vector< Window* > getWindows( );
		[[nodiscard]] std::uint64_t getWindowCount( ) const;
		void addWindow( Window* window );
		void update( const SDL_Event* event );
	};
} // namespace Alchemy2D::Graphics