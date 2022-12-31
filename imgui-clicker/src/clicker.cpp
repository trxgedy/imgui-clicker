#include "clicker.hpp"

auto c_clicker::click_thread( ) -> void
{
	auto toggle { false };
	
	while ( true )
	{
		if ( g_util->is_javaw_foreground( ) )
		{
			if ( GetAsyncKeyState( g_clicker->bind) )
			{
				toggle = !toggle;
				std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
			}

			if ( toggle && GetAsyncKeyState( VK_LBUTTON ) )
			{
				SendMessageW( GetForegroundWindow( ), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM( 0, 0 ) );
				SendMessageW( GetForegroundWindow( ), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM( 0, 0 ) );
			}

			std::this_thread::sleep_for( std::chrono::milliseconds( 790 / g_clicker->cps ) );
		}

		std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
	}

}
