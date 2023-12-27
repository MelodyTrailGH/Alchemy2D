#ifndef ALCHEMY2D_GRAPHICS_WINDOW_EVENT_HH
#define ALCHEMY2D_GRAPHICS_WINDOW_EVENT_HH
#pragma once
#include <functional>
#include <cstdint>
namespace Alchemy2D::Graphics {

	///@brief A template event function for handling when a window is resized.
	using OnWindowResized = std::function< void( std::int32_t width, std::int32_t height ) >;

	///@brief A template event function for handling when a window is shown.
	using OnWindowShown = std::function< void( ) >;

	///@brief A template event function for handling when a window is hidden.
	using OnWindowHidden = std::function< void( ) >;

	///@brief A template event function for handling when a window is moved.
	///@arg xPosition The horizontal position of the window.
	///@arg yPosition The vertical position of the window.
	using OnWindowMoved = std::function< void( std::int32_t xPosition, std::int32_t yPosition ) >;

	///@brief A template event function for handling when a window is minimized.
	using OnWindowMinimized = std::function< void( ) >;

	///@brief A template event function for handling when a window is maximized.
	using OnWindowMaximized = std::function< void( ) >;

	///@brief A template event function for handling when a mouse has entered the window.
	using OnWindowMouseEnter = std::function< void( ) >;

	///@brief A template event function for handling when a mouse has exited the window.
	using OnWindowMouseExit = std::function< void( ) >;

	///@brief A template event function for handling when the window has gained focus via the mouse.
	using OnWindowMouseFocusGained = std::function< void( ) >;

	///@brief A template event function for handling when the window has lost focus via the mouse.
	using OnWindowMouseFocusLost = std::function< void( ) >;

} // namespace Alchemy2D::Graphics
#endif // ALCHEMY2D_GRAPHICS_WINDOW_EVENT_HH
