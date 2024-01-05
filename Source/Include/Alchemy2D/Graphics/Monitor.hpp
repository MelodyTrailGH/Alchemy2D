#pragma once
#include <cstdint>
#include "GLFW/glfw3.h"
namespace Alchemy2D::Graphics {
	class Monitor {
	  public:
		static Monitor& GetManager( );

	  private:
		GLFWmonitor** monitors = nullptr;
		int32_t monitorCount = 0;
		Monitor( );

		GLFWmonitor* Get( std::int32_t index );

	  public:
		Monitor( Monitor const& );

		std::int32_t GetWidth( std::int32_t index );
		std::int32_t GetHeight( std::int32_t index );
		std::int32_t GetPhysicalWidth( std::int32_t index );
		std::int32_t GetPhysicalHeight( std::int32_t index );
	};
} // namespace Alchemy2D::Graphics