#pragma once

#include "State.hpp"
#include "ecs/ECS.hpp"
#include "resourceManaging/ResourceHolder.hpp"
#include "subsystems/Renderer.hpp"
#include "components/Drawable.hpp"

namespace pg
{
	class PlayState final :
		public pi::State
	{
	public:
		PlayState( sf::RenderWindow* window ) :
			State( window ),
			renderer( *this->windowPtr )
		{}

		void OnStart() override;
		void OnStop() override;
		int16_t Run() override;

		void UpdateThread( float time, sf::RenderWindow& window ) override;

	private:
		ecs::SystemBase ecsSystem;
		pg::Renderer renderer;

		void loadTextures();
		void freeResources();
	};
}