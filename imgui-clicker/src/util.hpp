#ifndef util_hpp
#define util_hpp

class c_util
{

private:

public:
	c_util( ) = default;
	~c_util( ) = default;

	auto pid( std::string_view p_name ) -> DWORD;
	auto is_foreground_proc(DWORD p_pid) -> bool;

};

inline auto g_util { std::make_unique<c_util>( ) };

#endif