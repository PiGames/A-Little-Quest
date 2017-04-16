#include "Cell.hpp"
#include <iostream>
namespace pi
{
	Cell::Cell( int identifier, const sf::Vector2i& unitPosition )
		: id( identifier / constants::cell::ROTATION_MODES )
	{
		object.setOrigin( object.getGlobalBounds().width / 2, object.getGlobalBounds().height / 2 );
		object.setPosition( unitPosition.x * constants::cell::CELL_DIMENSIONS.x, unitPosition.y * constants::cell::CELL_DIMENSIONS.y );
	//	object.setRotation( id % constants::cell::ROTATION_MODES * constants::cell::STRAIGHT_ANGLE );
	}
}
