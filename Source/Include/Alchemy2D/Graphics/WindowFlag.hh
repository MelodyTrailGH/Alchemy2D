#pragma once

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
