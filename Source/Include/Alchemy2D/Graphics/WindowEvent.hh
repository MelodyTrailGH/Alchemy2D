#pragma once
#include <functional>
#include <cstdint>
using OnWindowResized = std::function< void( std::int32_t width, std::int32_t height ) >;
using OnWindowShown = std::function< void( ) >;
using OnWindowHidden = std::function< void( ) >;
using OnWindowMoved = std::function< void( std::int32_t xPosition, std::int32_t yPosition ) >;
using OnWindowMinimized = std::function< void( ) >;
using OnWindowMaximized = std::function< void( ) >;
using OnWindowMouseEnter = std::function< void( ) >;
using OnWindowMouseExit = std::function< void( ) >;
using OnWindowMouseFocusGained = std::function< void( ) >;
using OnWindowMouseFocusLost = std::function< void( ) >;