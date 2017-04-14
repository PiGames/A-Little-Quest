#pragma once

namespace pi
{
	template<class T>
	struct coord_t
	{
		T x, y;
		constexpr coord_t( T xx, T yy ) :
			x( xx ), y( yy )
		{}
	};
}