#include "Cell.hpp"
#include <iostream>
namespace pi
{
	Cell::Cell( int identifier, sf::Vector2i unitPosition )
		: id( identifier )
	{
		object.setOrigin( object.getGlobalBounds().width / 2, object.getGlobalBounds().height / 2 );
		object.setPosition( unitPosition.x * 64, unitPosition.y * 64 );

		std::cout << "Cell has been created ==> Position x: " << unitPosition.x << " | y: " << unitPosition.y << " | id: " <<id<< std::endl;
	}
}
