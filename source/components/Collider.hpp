#pragma once

#include <SFML/Graphics/Rect.hpp>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Collider Component structure extended by sf::FloatRect.

	===============================================================================
	*/
	struct ColliderComponent final :
		public sf::FloatRect
	{
		ColliderComponent( const sf::FloatRect rect = sf::FloatRect() ) :
			sf::FloatRect( rect )
		{}
	};
}