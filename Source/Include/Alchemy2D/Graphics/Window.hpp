#pragma once
#include "GLFW/glfw3.h"
#include <cstdint>
#include <string>

namespace Alchemy2D::Graphics {
	class Window {
	  private:
		GLFWwindow *_window;

	  public:
		Window( );
		~Window( );

		void SetCaption( std::string const &caption );
		void SetPosition( std::int32_t xpos, std::int32_t ypos );
		void SetSize( std::int32_t width, std::int32_t height );
	};
} // namespace Alchemy2D::Graphics
