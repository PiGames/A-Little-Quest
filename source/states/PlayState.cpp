#include "PlayState.hpp"

namespace pg
{
	void PlayState::OnStart()
	{
		this->StartThread();

		this->loadTextures();
		this->renderer.SetComponentBlocks( *this->ecsSystem.ReserveComponentBlocks<DrawableComponent>( 8 ) );
		this->renderer.SetMapTextureSheet( pi::ResourceHolder::GetTexture( 1 ) );
		this->renderer.GenerateMapTexture();
		auto wrapper = this->ecsSystem.AddComponent<DrawableComponent>( this->ecsSystem.CreateEntity() );
		wrapper.ResetComponent<DrawableComponent>( 1 );
		sf::Sprite spr;
		spr.setTexture( *pi::ResourceHolder::GetTexture( 0 ).lock() );
		std::static_pointer_cast<DrawableComponent>( wrapper.data )->sprites.push_back( spr );

		this->EndThread();
	}

	void PlayState::OnStop()
	{
		this->StartThread();
		this->ecsSystem.ClearAll();
		this->freeResources();
		this->EndThread();
	}

	int16_t PlayState::Run()
	{
		while ( true )
		{
			this->renderer.ClearWindow( sf::Color::Cyan );
			this->renderer.Render();
			this->renderer.Display();
		}
		return 0;
	}

	void PlayState::UpdateThread( float time, sf::RenderWindow& window )
	{
		// Draw loading screen or smh
	}

	void PlayState::loadTextures()
	{
		pi::ResourceHolder::textures.emplace_back( std::make_shared<pi::textureResource_t>() );
		pi::ResourceHolder::textures.back()->loadFromFile( "data/textures/playerPlaceholder.png" );
		pi::ResourceHolder::textures.back()->SetResourcePriority( 0 );
		pi::ResourceHolder::textures.back()->SetResourceID( 0 );


		pi::ResourceHolder::textures.emplace_back( std::make_shared<pi::textureResource_t>() );
		pi::ResourceHolder::textures.back()->loadFromFile( "data/textures/cellAtlas.png" );
		pi::ResourceHolder::textures.back()->SetResourcePriority( 0 );
		pi::ResourceHolder::textures.back()->SetResourceID( 1 );
	}

	void PlayState::freeResources()
	{
		pi::ResourceHolder::DeleteAllResourcesByPriority( 0 );
	}
}