#ifndef clicker_hpp
#define clicker_hpp

#include "stdafx.hpp"

class c_clicker
{
public:
	int cps { 10 };
	char bind { 'F' };

public:
	c_clicker( ) = default;
	~c_clicker( ) = default;
	auto click_thread( ) -> void;

};

inline auto g_clicker { std::make_unique<c_clicker>( ) };

#endif
