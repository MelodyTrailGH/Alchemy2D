#pragma once

using WindowFlag = enum class WindowFlag {
	None = 0U,
	Fullscreen = 1U,
	ExclusiveFullscreen = 2U,
	Hidden = 4U,
	Borderless = 8U,
	Resizable = 16U,
	Minimized = 32U,
	Maximized = 64U,
	HighDPI = 128U,
	AlwaysOnTop = 256U
};
