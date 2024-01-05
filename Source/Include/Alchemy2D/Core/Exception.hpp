#pragma once
#include <exception>
#include <string>
#include <iostream>
namespace Alchemy2D::Core {
	class Exception : public std::exception {
	  private:
		std::string _message;

	  public:
		[[noreturn]] explicit Exception( const std::string& message );
		[[nodiscard]] const char* what( ) const noexcept override;
	};

	inline Exception::Exception( const std::string& message ) : _message( message ) {
		std::cout << message << std::endl;
		std::terminate( );
	}

	inline const char* Exception::what( ) const noexcept {
		return this->_message.c_str( );
	}

} // namespace Alchemy2D::Core
