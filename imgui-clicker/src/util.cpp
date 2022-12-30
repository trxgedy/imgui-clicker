#include "stdafx.hpp"
#include "util.hpp"

auto c_util::pid( std::string_view p_name ) -> DWORD
{
	const auto handle { CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, NULL ) };
	PROCESSENTRY32 entry; entry.dwSize = sizeof( entry );

	if ( !Process32First( handle, &entry ) )
		return 0;

	do
	{
		if ( p_name == entry.szExeFile )
		{
			CloseHandle( handle );
			return entry.th32ProcessID;
		}

	} while ( Process32Next( handle, &entry ) );

	CloseHandle( handle );
	return 0;
}


auto c_util::is_foreground_proc( DWORD p_pid ) -> bool
{
	HWND hwnd { GetForegroundWindow( ) }; 
	DWORD w_pid;

	GetWindowThreadProcessId( hwnd, &w_pid );

	if ( w_pid == p_pid )
		return true;

	return false;
}
