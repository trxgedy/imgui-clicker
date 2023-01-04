#include "stdafx.hpp"
#include "util.hpp"

auto c_util::is_javaw_foreground() -> bool
{
	HWND hwnd { FindWindowA( "LWJGL", nullptr ) };
	DWORD w_pid = GetWindowThreadProcessId( hwnd, &w_pid );

	if ( w_pid )
		return true;

	return false;
}
