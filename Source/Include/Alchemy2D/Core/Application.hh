#pragma once

namespace Alchemy2D::Core {
	class Application {

	  public:
		Application( );
		Application( Application const &other );
		Application( Application &&other ) noexcept;
		~Application( );
		Application &operator=( Application &other );
		Application &operator=( Application &&other ) noexcept;
	};
} // namespace Alchemy2D::Core