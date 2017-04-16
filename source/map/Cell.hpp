#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Config.hpp"

namespace pi
{
	class Cell
	{
	public:
		Cell( int identifier, const sf::Vector2i& unitPosition );

		int GetID()
		{
			return this->id;
		}

		sf::Sprite& GetSprite()
		{
			return this->object;
		}

		void SetCenter()
		{
			this->object.setOrigin( object.getGlobalBounds().width / 2, object.getGlobalBounds().height / 2 );
		}

		void ConfirmRotation()
		{
			this->object.setRotation( (id % constants::cell::ROTATION_MODES+2) * constants::cell::STRAIGHT_ANGLE);
		}

	private:
		const int id;
		
		sf::Sprite object;
	};
}