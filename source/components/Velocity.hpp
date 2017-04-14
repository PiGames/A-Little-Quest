/*
Conrad 'Condzi' Kubacki 2017
https://github.com/condzi
*/

#pragma once

#include <SFML/System/Vector2.hpp>

namespace pi
{
	/*
	===============================================================================
	Velocity Component structure.

	===============================================================================
	*/
	struct VelocityComponent final
	{
		sf::Vector2f velocity;

		VelocityComponent( const sf::Vector2f& vel = sf::Vector2f() ) :
			velocity( vel )
		{}
	};
}
