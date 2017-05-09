#include "MenuState.hpp"

namespace pg
{
	void MenuState::OnStart()
	{
		this->StartThread();
		this->loadTextures();
		this->renderer.SetComponentBlocks(*this->ecsSystem.ReserveComponentBlocks<DrawableComponent>(9));
		this->renderer.SetMapTextureSheet(this->resourceCache.GetTexture(1));
		this->renderer.GenerateMapTexture();

		this->addSubState<MenuSubState>(SUB_STATE_MENU_MAIN, this->window, this->resourceCache, this->ecsSystem, this->renderer);
		this->EndThread();
	}

	void MenuState::OnStop()
	{
		this->StartThread();
		this->ecsSystem.ClearAll();
		this->freeResources();
		this->EndThread();
	}

	uint8_t MenuState::Run()
	{
		this->initFirstSubState(SUB_STATE_MENU_MAIN);

		uint8_t returnState = STATE_MENU;
		while (returnState == STATE_MENU)
			returnState = this->subStates[this->currentSubStateRO]->Run();

		return STATE_EXIT;
	}

	void MenuState::UpdateThread( float time )
	{
		// Draw loading screen or smh
	}

	void MenuState::loadTextures()
	{
		this->resourceCache.textures.emplace_back(std::make_shared<pi::textureResource_t>());
		this->resourceCache.textures.back()->loadFromFile("data/textures/menuBackground.png");
		this->resourceCache.textures.back()->SetResourcePriority(0);
		this->resourceCache.textures.back()->SetResourceID(0);

		this->resourceCache.textures.emplace_back(std::make_shared<pi::textureResource_t>());
		this->resourceCache.textures.back()->loadFromFile("data/textures/playButton.png");
		this->resourceCache.textures.back()->SetResourcePriority(0);
		this->resourceCache.textures.back()->SetResourceID(1);

		this->resourceCache.textures.emplace_back(std::make_shared<pi::textureResource_t>());
		this->resourceCache.textures.back()->loadFromFile("data/textures/exitButton.png");
		this->resourceCache.textures.back()->SetResourcePriority(0);
		this->resourceCache.textures.back()->SetResourceID(2);
	}

	void MenuState::freeResources()
	{
		this->resourceCache.DeleteAllResourcesByPriority(0);
	}
}