#include <iostream>

#include "map/MapManager.hpp"
#include "map/WorldConstructor.hpp"

#include "states/PlayState.hpp"
#include "states/StateMachine.hpp"

int main()
{
	std::cout << "Hello World!\n";

	pi::MapManager::CreateInstance( sf::Vector2i( 15, 15 ) );

	{
		pi::WorldConstructor worldConstructor;
		worldConstructor.CreateWorld( sf::Vector2i( 15, 15 ), 0 );
	}

	sf::RenderWindow win( { 800,600 }, "title!" );
	pi::StateMachine stateMachine;

	stateMachine.RegisterState<pg::PlayState>( 0, &win );
	stateMachine.Run();
	return 0;
}