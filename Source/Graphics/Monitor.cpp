#include "Alchemy2D/Graphics/Monitor.hpp"
#include "Alchemy2D/Core/Exceptions.hpp"
#include "GLFW/glfw3.h"
#include <exception>
namespace Alchemy2D::Graphics {
	Monitor::Monitor( ) {
		if ( glfwInit( ) != GLFW_TRUE ) {
			try {
				throw Core::Exceptions::GLFWInitializationFailure{ };
			} catch ( Core::Exceptions::GLFWInitializationFailure& e ) {
				std::cout << e.what( );
			}
		}

		this->monitors = glfwGetMonitors( &this->monitorCount );
		if ( this->monitors == nullptr ) {
			const char* error = nullptr;
			glfwGetError( &error );
		}
	}

	Monitor& Monitor::GetManager( ) {
		static Monitor instance;
		return instance;
	}

	GLFWmonitor* Monitor::Get( std::int32_t index ) {
		if ( index > this->monitorCount ) {
			return nullptr;
		}
		return this->monitors[index];
	}

	std::int32_t Monitor::GetWidth( std::int32_t index ) {
		return glfwGetVideoMode( this->Get( index ) )->width;
	}
	std::int32_t Monitor::GetHeight( std::int32_t index ) {
		return glfwGetVideoMode( this->Get( index ) )->height;
	}
	std::int32_t Monitor::GetPhysicalWidth( std::int32_t index ) {
		int32_t width = 0;
		glfwGetMonitorPhysicalSize( this->Get( index ), &width, nullptr );
		return width;
	}
	std::int32_t Monitor::GetPhysicalHeight( std::int32_t index ) {
		int32_t width = 0;
		glfwGetMonitorPhysicalSize( this->Get( index ), &width, nullptr );
		return width;
	}
} // namespace Alchemy2D::Graphics