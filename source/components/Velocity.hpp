/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <SFML/System/Vector2.hpp>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Velocity Component structure.

	===============================================================================
	*/
	struct VelocityComponent final
	{
		float x, y;

		VelocityComponent( float xx, float yy ) :
			x( xx ), y( yy )
		{}
	};
}
