#include <iostream>

#include "map/MapManager.hpp"
#include "map/WorldConstructor.hpp"

#include "states/play/PlayState.hpp"
#include "states/Game.hpp"

int main()
{
	pi::MapManager::CreateInstance( sf::Vector2i( 5, 5 ) );
	{
		pi::WorldConstructor worldConstructor;
		worldConstructor.CreateWorld( sf::Vector2i( 5, 5 ), 0 );
	}

	pg::Game game("settings.ini", pg::STATE_PLAY);
	game.RegisterState<pg::PlayState>( pg::STATE_PLAY );
	
	game.Run();

	return 0;
}