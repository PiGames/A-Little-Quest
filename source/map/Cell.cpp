#include "Cell.hpp"
#include <iostream>
namespace pi
{
	Cell::Cell( int identifier, sf::Vector2i unitPosition )
		: id( identifier/4 )
	{
		object.setOrigin( object.getGlobalBounds().width / 2, object.getGlobalBounds().height / 2 );
		object.setPosition( unitPosition.x * 64, unitPosition.y * 64 );
		object.setRotation( id % 4 * 90 );
	}
}
