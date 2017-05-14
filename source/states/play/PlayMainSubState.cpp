#include "PlayMainSubState.hpp"

namespace pg
{
	void pg::PlayMainSubState::OnStart()
	{
		this->physic.SetColliderComponentBlocks( *this->ecsSystem.ReserveComponentBlocks<ColliderComponent>( 8 ) );
		this->physic.SetVelocityComponentBlocks( *this->ecsSystem.ReserveComponentBlocks<VelocityComponent>( 8 ) );
		auto player = std::make_shared<Player>( this->ecsSystem );
		player->SetUpComponents();
		auto drawable = player->AddComponent<DrawableComponent>();
		drawable->drawLayer = LAYER_PLAYER;
		drawable->sprites.emplace_back();
		drawable->sprites.back().setTexture( *this->resourceCache.GetTexture( 0 ).lock() );

		pi::Logger::Log( std::to_string( player->GetID() ) );
		entities.push_back( player );
		this->updateECS( 0.0f );
		player->GetComponent<PositionComponent>()->x = 100.0f;
	}

	void PlayMainSubState::OnStop()
	{
	}

	uint8_t PlayMainSubState::Run()
	{
		float dt = 0.0f;
		while ( this->returnState == STATE_MENU )
		{
			sf::Clock c;
			this->checkEvents();
			this->physic.Update( dt );
			this->updateECS( dt );
			this->draw();
			dt = c.restart().asSeconds();
		}

		return returnState;
	}

	void PlayMainSubState::checkEvents()
	{
		sf::Event event;
		while ( this->window.pollEvent( event ) )
		{
			if ( sf::Event::Closed == event.type )
				this->returnState = STATE_EXIT;
			if ( sf::Event::KeyReleased == event.type )
				if ( sf::Keyboard::Escape == event.key.code )
					this->returnState = STATE_EXIT;
		}
	}

	void PlayMainSubState::updateECS( float dt )
	{
		ecs::removeUnusedEntities( this->entities, this->ecsSystem, []( std::shared_ptr<ecs::Entity>& entity ) -> ecs::entityID_t
		{
			return entity->GetID();
		} );

		for ( auto entity : this->entities )
			entity->Update();
	}

	void PlayMainSubState::draw()
	{
		this->renderer.ClearWindow();
		this->renderer.Render();
		this->renderer.Display();
	}
}
