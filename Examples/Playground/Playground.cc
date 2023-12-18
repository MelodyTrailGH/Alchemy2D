

#include "Alchemy2D/Core/Application.hh"
#include "Alchemy2D/Graphics/Window.hh"
#include "Alchemy2D/Graphics/WindowManager.hh"
int main( ) {
	Alchemy2D::Application app;
	Alchemy2D::Graphics::WindowManager windowManager;
	auto window1 = Alchemy2D::Graphics::Window( 40, 40, 640, 480, "Window 1" );
	auto window2 = Alchemy2D::Graphics::Window( 500, 40, 640, 480, "Window 2" );
	windowManager.addWindow( &window1 );
	windowManager.addWindow( &window2 );
	app.setWindowManager( &windowManager );
	app.run( );
}