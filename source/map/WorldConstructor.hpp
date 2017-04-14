#pragma once

#include <fstream>
#include <string>

#include <SFML/System/Vector2.hpp>

#include "Config.hpp"

namespace pi
{
	class WorldConstructor
	{
	public:

		//Creates world 
		void createWorld( sf::Vector2i unitWorldSize, int id );
	private:
	};
}
