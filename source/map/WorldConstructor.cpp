#include "WorldConstructor.hpp"

namespace pi
{
	void WorldConstructor::CreateWorld( int mapNumber )
	{
		std::ifstream input( "data/maps/map" + std::to_string( mapNumber ) +".txt" );

		if ( !input.good() )
		{
			Logger::Log( constants::error::worldConstructor::FAILED_OPEN, Logger::stream_t::BOTH, Logger::type_t::ERROR );
		}

		sf::Vector2i unitDimensions;

		input >> unitDimensions.x >> unitDimensions.y;

		int tempID;

		for ( int j = 0; j < unitDimensions.y; j++ )
		{
			for ( int i = 0; i < unitDimensions.x; i++ )
			{
				input >> tempID;
				MapManager::GetInstance().addCell( tempID, sf::Vector2i(i,j));
			}
		}
	}
}
