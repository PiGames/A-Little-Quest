#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Config.hpp"

namespace pi
{
	class Cell
	{
	public:
		Cell( int identifier, sf::Vector2i unitPosition );
	private:
		const int id;
		
		sf::Sprite object;
	};
}