#pragma once

#include <SFML/Window/Event.hpp>

#include "SubState.hpp"
#include "States.hpp"
#include "ecs/ECS.hpp"
#include "resourceManaging/ResourceHolder.hpp"
#include "components/Tag.hpp"
#include "subsystems/Renderer.hpp"

namespace pg
{
	class PlayMainSubState final :
		public pi::SubState
	{
	public:
		explicit PlayMainSubState( sf::RenderWindow& win, pi::ResourceHolder& resCache, ecs::SystemBase& ecsSys, Renderer& rend ) :
			SubState( win ),
			resourceCache( resCache ),
			ecsSystem( ecsSys ),
			renderer( rend ),
			returnState( STATE_MENU )
		{}

		void OnStart() override;
		void OnStop() override;
		uint8_t Run() override;

	private:
		pi::ResourceHolder& resourceCache;
		ecs::SystemBase& ecsSystem;
		Renderer& renderer;
		uint8_t returnState;

		void checkEvents();
		void updateECS();
		void draw();
	};
}