/**
 * @file Window.hh
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <SDL2/SDL_video.h>
#include <string>
#include <vector>

#include "Alchemy2D/Graphics/WindowEvent.hh"
#include "Alchemy2D/Graphics/WindowFlag.hh"
#include "Alchemy2D/Utility/Math/Vector2.hh"

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_X SDL_WINDOWPOS_CENTERED
#define DEFAULT_WINDOW_Y SDL_WINDOWPOS_CENTERED

namespace Alchemy2D::Graphics {

	class Window {
	  private:
		////////////////////////////////////////////////////////////////////////
		//// 							Variables							////
		////////////////////////////////////////////////////////////////////////

		/// @brief The underlying window from SDL.
		SDL_Window* _window;

		std::uint32_t _id; // Don't get this confused with an id from the engine. This is exclusive to SDL.

		// This large list of lists... of window events.
		std::vector< OnWindowResized* > onWindowResized;
		std::vector< OnWindowShown* > onWindowShown;
		std::vector< OnWindowHidden* > onWindowHidden;
		std::vector< OnWindowMoved* > onWindowMoved;
		std::vector< OnWindowMinimized* > onWindowMinimized;
		std::vector< OnWindowMaximized* > onWindowMaximized;
		std::vector< OnWindowMouseEnter* > onWindowMouseEntered;
		std::vector< OnWindowMouseExit* > onWindowMouseExited;
		std::vector< OnWindowMouseFocusGained* > onWindowFocusGained;
		std::vector< OnWindowMouseFocusLost* > onWindowFocusLost;

		////////////////////////////////////////////////////////////////////////
		//// 							Methods								////
		////////////////////////////////////////////////////////////////////////
		static SDL_Window* CreateWindow( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name,
		                                 WindowFlag flags );

	  public:
		////////////////////////////////////////////////////////////////////////
		//// 							Methods								////
		////////////////////////////////////////////////////////////////////////
		~Window( ); // Still need the deconstructor since SDL has a special function for removing windows.

		// This is way too many constructors but I don't care.
		Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name, std::uint32 flags );
		Window( Utility::Math::Vector2 position, Utility::Math::Vector2 size, const std::string& name );
		Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
		        const std::string& name, std::uint32 flags );
		Window( std::int32_t xPosition, std::int32_t yPosition, std::int32_t width, std::int32_t height,
		        const std::string& name );

		////////////////////////////////////////////////////////////////////////
		//// 						Geters and Setters						////
		////////////////////////////////////////////////////////////////////////

		// Gotta love having no public variables.
		[[nodiscard]] std::uint32_t getId( ) const;

		void hide( ) const;
		void show( ) const;

		// Specifically for window events.
		void addOnWindowResizedEvent( OnWindowShown* function );
		void addOnWindowShownEvent( OnWindowShown* function );
		void addOnWindowHiddenEvent( OnWindowHidden* function );
		void addOnWindowMovedEvent( OnWindowMoved* function );
		void addOnWindowMinimizedEvent( OnWindowMinimized* function );
		void addOnWindowMaximizedEvent( OnWindowMaximized* function );
		void addOnWindowMouseEnteredEvent( OnWindowMouseEnter* function );
		void addOnWindowMouseExitedEvent( OnWindowMouseExit* function );
		void addOnWindowGainedFocusEvent( OnWindowMouseFocusGained* function );
		void addOnWindowLostFocusEvent( OnWindowMouseFocusLost* function );
	};

} // namespace Alchemy2D::Graphics