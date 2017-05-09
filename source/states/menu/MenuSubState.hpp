#pragma once

#include <SFML/Window/Event.hpp>

#include "states/base/SubState.hpp"
#include "states/States.hpp"
#include "resourceManaging/ResourceHolder.hpp"
#include "subsystems/Renderer.hpp"
#include "prefabs/Player.hpp"
#include "ui/UI.hpp"

namespace pg
{
	class MenuSubState final :
		public pi::SubState
	{
	public:
		explicit MenuSubState( sf::RenderWindow& win, pi::ResourceHolder& resCache, ecs::SystemBase& ecsSys, Renderer& rend ) :
			SubState( win ),
			resourceCache( resCache ),
			ecsSystem( ecsSys ),
			renderer( rend ),
			returnState( STATE_MENU ),
			ui( win )
		{}

		void OnStart() override;
		void OnStop() override;
		uint8_t Run() override;

	private:
		ui::UI ui;
		ui::Button* play, *exit;

		pi::ResourceHolder& resourceCache;
		ecs::SystemBase& ecsSystem;
		Renderer& renderer;
		uint8_t returnState;

		void checkEvents();
		void updateECS( float dt );
		void draw();
	};
}