#include "Alchemy2D/Graphics/Monitor.hpp"
#include <iostream>
int main( ) {
	std::cout << Alchemy2D::Graphics::Monitor::GetManager( ).GetWidth( 0 );
}