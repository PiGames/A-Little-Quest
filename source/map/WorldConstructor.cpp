#include "WorldConstructor.hpp"

namespace pi
{
	void WorldConstructor::createWorld( sf::Vector2i unitWorldSize, int mapNumber )
	{
		std::ifstream input( "data/maps/map" + std::to_string( mapNumber ) +".txt" );

		if ( !input.good() )
		{
			//Logger
		}
		int tempID;

		for ( int j = 0; j < unitWorldSize.y; j++ )
		{
			for ( int i = 0; i < unitWorldSize.x; i++ )
			{
				input >> tempID;
				MapManager::getInstance().addCell( tempID, sf::Vector2i(i,j));
			}
		}
	}
}
