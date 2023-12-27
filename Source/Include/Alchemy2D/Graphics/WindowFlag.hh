#ifndef ALCHEMY2D_GRAPHICS_WINDOW_FLAG_HH
#define ALCHEMY2D_GRAPHICS_WINDOW_FLAG_HH
#pragma once
namespace Alchemy2D::Graphics {

	/**
	 * @brief A set of options to configure a window.
	 *
	 */
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
} // namespace Alchemy2D::Graphics
#endif // ALCHEMY2D_GRAPHICS_WINDOW_FLAG_HH
