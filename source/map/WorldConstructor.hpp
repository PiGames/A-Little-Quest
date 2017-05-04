#pragma once

#include <fstream>
#include <string>

#include <SFML/System/Vector2.hpp>

#include "Config.hpp"
#include "MapManager.hpp"

namespace pi
{
	class WorldConstructor
	{
	public:
		//Creates world 
		void CreateWorld( int mapNumber );
	};
}
