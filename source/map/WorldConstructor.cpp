#include "WorldConstructor.hpp"

namespace pi
{
	void WorldConstructor::createWorld( sf::Vector2i unitWorldSize, int id )
	{
		std::ifstream input( "mapa/data/" + std::to_string( id ) );

		int tempID;

		for ( int j = 0; j < unitWorldSize.y; j++ )
		{
			for ( int i = 0; i < unitWorldSize.x; i++ )
			{

			}
		}
	}
}
