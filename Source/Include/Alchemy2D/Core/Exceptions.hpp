#pragma once
#include "Alchemy2D/Core/Exception.hpp"
#include <GLFW/glfw3.h>
#include <fmt/format.h>

namespace Alchemy2D::Core::Exceptions {
	class GLFWInitializationFailure : public Exception {

	  private:
		static std::string GetGLFWError( );

	  public:
		GLFWInitializationFailure( ) : Exception( fmt::format( "GLFW failed to initialize. Error: {}", GetGLFWError( ) ) ) {
		}
	};

	inline std::string GLFWInitializationFailure::GetGLFWError( ) {
		const char *error = nullptr;
		glfwGetError( &error );
		if ( error == nullptr ) {
			return "None.";
		}
		return { error };
	}
} // namespace Alchemy2D::Core::Exceptions