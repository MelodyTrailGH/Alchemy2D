

#include "Alchemy2D/Core/Application.hh"
#include "Alchemy2D/Graphics/Window.hh"
#include "Alchemy2D/Graphics/WindowManager.hh"
#include <cstdint>
int main( ) {
	Alchemy2D::Application app;
	Alchemy2D::Graphics::WindowManager windowManager;
	auto window1 = Alchemy2D::Graphics::Window( 40, 40, 640, 480, "Window 1", 0 );
	windowManager.addWindow( &window1 );
	app.setWindowManager( &windowManager );
	app.run( );
}