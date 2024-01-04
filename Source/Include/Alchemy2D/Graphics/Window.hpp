#ifndef ALCHEMY2D_GRAPHICS_WINDOW_HPP
#define ALCHEMY2D_GRAPHICS_WINDOW_HPP

#include "GLFW/glfw3.h"

namespace Alchemy2D::Graphics {
	class Window {
	  private:
		GLFWwindow *_window;
	};
} // namespace Alchemy2D::Graphics

#endif // ALCHEMY2D_GRAPHICS_WINDOW_HPP
