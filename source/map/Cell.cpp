#include "Cell.hpp"
#include <iostream>
namespace pi
{
	Cell::Cell( int identifier, const sf::Vector2i& unitPosition )
		: id( identifier / constants::cell::ROTATION_MODES  )
	{
		object.setPosition( unitPosition.x * constants::cell::CELL_DIMENSIONS.x, unitPosition.y * constants::cell::CELL_DIMENSIONS.y );
	}
}
