#include "MapManager.hpp"


namespace pi
{

	MapManager* MapManager::instance;

	MapManager & MapManager::GetInstance()
	{
		if ( instance == nullptr )
		{
			Logger::Log( constants::error::singleton::SINGLETON_NOT_INITED, Logger::stream_t::BOTH, Logger::type_t::ERROR );
		}
		return *instance;
	}

	MapManager::MapManager( sf::Vector2i uWorldSize )
	{
		if ( uWorldSize.x <= 0 || uWorldSize.y <= 0 )
		{
			Logger::Log( constants::error::mapManager::NEGATIVE_VALUES, Logger::stream_t::BOTH, Logger::type_t::ERROR );
			return;
		}
		MapManager::unitWorldSize = uWorldSize;
	}

	void MapManager::CreateInstance( sf::Vector2i uWorldSize )
	{
		if ( instance == nullptr )
			instance = new MapManager( uWorldSize );
		else
		{
			Logger::Log( constants::error::singleton::SINGLETON_INITED, Logger::stream_t::CONSOLE, Logger::type_t::INFO );
		}
	}

	sf::Vector2i MapManager::GetUnitWorldSize()
	{
		return MapManager::unitWorldSize;
	}


	bool MapManager::IsInMap( sf::Vector2i & unitPosition )
	{
		return IsInMap( unitPosition.x, unitPosition.y );
	}

	bool MapManager::IsInMap( unsigned int i, unsigned int j )
	{
		return i >= 0 && i < unitWorldSize.x &&
			j >= 0 && j < unitWorldSize.y;
	}

	void MapManager::addCell( int id, sf::Vector2i unitPosition )
	{
		map.emplace_back( id, unitPosition );
	}

}
