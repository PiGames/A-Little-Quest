#include "MapManager.hpp"


namespace pi
{
	MapManager & MapManager::getInstance()
	{
	}

	MapManager::MapManager( sf::Vector2i uWorldSize )
	{
		if ( uWorldSize.x <= 0 || uWorldSize.y <= 0 )
		{
			Logger::Log( constants::error::mapManager::NEGATIVE_VALUES, Logger::STREAM::BOTH, Logger::TYPE::ERROR );
			return;
		}
		MapManager::unitWorldSize = uWorldSize;
		MapManager::cellDimensions = cellDim;
	}
}
