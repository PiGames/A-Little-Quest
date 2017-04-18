#include "PlayMainSubState.hpp"

namespace pg
{
	void pg::PlayMainSubState::OnStart()
	{
		ecs::entityID_t testEntity = this->ecsSystem.CreateEntity();
		auto wrapper = this->ecsSystem.AddComponent<DrawableComponent>( testEntity );
		std::static_pointer_cast<DrawableComponent>( wrapper.data )->sprites.clear();
		std::static_pointer_cast<DrawableComponent>( wrapper.data )->drawLayer = 0;

		sf::Sprite spr;
		spr.setTexture( *this->resourceCache.GetTexture( 0 ).lock() );
		std::static_pointer_cast<DrawableComponent>( wrapper.data )->sprites.push_back( spr );

		auto tag = this->ecsSystem.AddComponent<TagComponent>( testEntity );
		std::static_pointer_cast<TagComponent>( tag.data )->tag = entityID_t::PLAYER;
	}

	void PlayMainSubState::OnStop()
	{
		this->ecsSystem.ForEachLambda<TagComponent>( []( ecs::SystemBase& sys, ecs::componentWrapper_t& comp ) -> void
		{
			if ( std::static_pointer_cast<TagComponent>( comp.data )->tag == entityID_t::PLAYER )
				sys.DeleteEntity( comp.ownerEntityID );
		} );
	}

	uint8_t PlayMainSubState::Run()
	{
		while ( this->returnState == STATE_MENU )
		{
			this->checkEvents();
			this->updateECS();
			this->draw();
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

	void PlayMainSubState::updateECS()
	{
		// ...
	}

	void PlayMainSubState::draw()
	{
		this->renderer.ClearWindow();
		this->renderer.Render();
		this->renderer.Display();
	}
}
