#pragma once
#include <Alchemy2D/Utility/Math/Vector2.hh>
#include <SDL2/SDL_video.h>
#include <functional>
#include <string>
#include <vector>

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_X SDL_WINDOWPOS_CENTERED
#define DEFAULT_WINDOW_Y SDL_WINDOWPOS_CENTERED

namespace Alchemy2D::Graphics {
	using WindowFlag = enum class WindowFlag {
		None = 0,
		Fullscreen = 1,
		ExclusiveFullscreen = 2,
		Hidden = 4,
		Borderless = 8,
		Resizable = 16,
		Minimized = 32,
		Maximized = 64,
		HighDPI = 128,
		AlwaysOnTop = 256
	};

	using OnWindowResized = std::function< void( std::int32_t width, std::int32_t height ) >;
	using OnWindowShown = std::function< void( ) >;
	using OnWindowHidden = std::function< void( ) >;
	using OnWindowMoved = std::function< void( std::int32_t xPosition, std::int32_t yPosition ) >;
	using OnWindowMinimized = std::function< void( ) >;
	using OnWindowMaximized = std::function< void( ) >;
	using OnWindowMouseEnter = std::function< void( ) >;
	using OnWindowMouseExit = std::function< void( ) >;
	using OnWindowMouseFocusGained = std::function< void( ) >;
	using OnWindowMouseFocusLost = std::function< void( ) >;

	class Window {
	  private:
		SDL_Window* _window;
		std::uint32_t _id;

		static SDL_Window* CreateWindow( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name,
		                                 WindowFlag flags );

		std::vector< OnWindowShown* > onWindowShown;
		std::vector< OnWindowHidden* > onWindowHidden;
		std::vector< OnWindowMoved* > onWindowMoved;
		std::vector< OnWindowMinimized* > onWindowMinimized;
		std::vector< OnWindowMaximized* > onWindowMaximized;
		std::vector< OnWindowMouseEnter* > onWindowMouseEntered;
		std::vector< OnWindowMouseExit* > onWindowMouseExited;
		std::vector< OnWindowMouseFocusGained* > onWindowFocusGained;
		std::vector< OnWindowMouseFocusLost* > onWindowFocusLost;

	  public:
		~Window( );

		Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name, WindowFlag flags );
		Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name );
		Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
		        const std::string& name, WindowFlag flags );
		Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
		        const std::string& name );

		[[nodiscard]] std::uint32_t getId( ) const;

		void hide( ) const;
		void show( ) const;

		void addEvent( );
	};

} // namespace Alchemy2D::Graphics