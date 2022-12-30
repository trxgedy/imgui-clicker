#include "stdafx.hpp"

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow )
{
	std::thread(&c_clicker::click_thread, g_clicker.get( ) ).detach( );

	gui::CreateHWindow( "clicker" );
	gui::CreateDevice( );
	gui::CreateImGui( );

	while ( gui::isRunning )
	{
		gui::BeginRender( );
		gui::Render( );
		gui::EndRender( );

		std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
	}

	gui::DestroyImGui( );
	gui::DestroyDevice( );
	gui::DestroyHWindow( );

	return EXIT_SUCCESS;
}