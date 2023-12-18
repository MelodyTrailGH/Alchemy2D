#pragma once

#include <Alchemy2D/Graphics/WindowManager.hh>

namespace Alchemy2D {
	class Application {
	  private:
		Graphics::WindowManager *WindowManager;
		bool shouldClose = false;

	  public:
		~Application( );
		void setWindowManager( Graphics::WindowManager *windowManager );
		Graphics::WindowManager *getWindowManager( );
		void run( );
	};
} // namespace Alchemy2D