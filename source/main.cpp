#include <iostream>

#include "map/MapManager.hpp"
#include "map/WorldConstructor.hpp"

int main()
{
	std::cout << "Hello World!\n";

	pi::MapManager::createInstance(sf::Vector2i(5,5));

	{
		pi::WorldConstructor worldConstructor;
		worldConstructor.createWorld( sf::Vector2i( 5, 5 ), 0 );
	}

	return 0;
}