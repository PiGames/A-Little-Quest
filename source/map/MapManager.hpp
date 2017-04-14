#pragma once

#include <vector>

#include "Cell.hpp"
#include "logger/Logger.hpp"

namespace pi
{
	class MapManager
	{
	public:
		static MapManager& getInstance();

		static void createInstance( sf::Vector2i uWorldSize);

		//Returns world size in units
		sf::Vector2i getUnitWorldSize();

		//Checks that object with given position is in map
		bool isInMap( sf::Vector2i& unitPosition );

		//Checks that object with given position is in map
		bool isInMap( unsigned int i, unsigned int j );

		//Adds new cell
		void addCell( int id, sf::Vector2i unitPosition );

	private:
		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		sf::Vector2i unitWorldSize{ 0,0 };

		//Dimensions of cell(in px)
		sf::Vector2f cellDimensions{ 0,0 };

		static MapManager* instance;

		MapManager( sf::Vector2i uWorldSize );
		MapManager() = delete;  // Not Implemented
		MapManager( MapManager const& copy ) = delete;            // Not Implemented
		MapManager& operator=( MapManager const& copy ) = delete; // Not Implemented
	};
}