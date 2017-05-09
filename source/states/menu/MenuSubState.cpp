#include "MenuSubState.hpp"

namespace pg
{
	void MenuSubState::OnStart()
	{
		this->play = this->ui.add<ui::Button>();
		this->play->setTexture(*this->resourceCache.GetTexture(1).lock(), *this->resourceCache.GetTexture(1).lock());
		this->play->setPosition({ this->ui.getPercent(70, this->ui.getWindowSize().x), this->ui.getPercent(60, this->ui.getWindowSize().y) });
		this->play->setSize( { this->ui.getPercent(20, this->ui.getWindowSize().x), this->ui.getPercent(10, this->ui.getWindowSize().y) } );
		this->play->addCallback([]()->void{

		});

		this->exit = this->ui.add<ui::Button>();
		this->exit->setTexture(*this->resourceCache.GetTexture(2).lock(), *this->resourceCache.GetTexture(2).lock());
		this->exit->setPosition({ this->ui.getPercent(70, this->ui.getWindowSize().x), this->ui.getPercent(80, this->ui.getWindowSize().y) });
		this->exit->setSize({ this->ui.getPercent(20, this->ui.getWindowSize().x), this->ui.getPercent(10, this->ui.getWindowSize().y) });
		this->exit->addCallback([]()->void {

		});
	}

	void MenuSubState::OnStop()
	{
	}

	uint8_t MenuSubState::Run()
	{
		float dt = 0.0f;
		while ( this->returnState == STATE_MENU )
		{
			sf::Clock c;
			this->checkEvents();
			this->updateECS( dt );
			this->ui.update();
			this->draw();
			dt = c.restart().asSeconds();
		}

		return returnState;
	}

	void MenuSubState::checkEvents()
	{
		sf::Event event;
		while ( this->window.pollEvent( event ) )
		{
			if ( sf::Event::Closed == event.type )
				this->returnState = STATE_EXIT;
			if ( sf::Event::KeyReleased == event.type )
				if ( sf::Keyboard::Escape == event.key.code )
					this->returnState = STATE_EXIT;

			ui.useButtons( event );
		}
	}

	void MenuSubState::updateECS( float dt )
	{
	}

	void MenuSubState::draw()
	{
		this->renderer.ClearWindow();
		this->renderer.Render();
		this->renderer.Display();
	}
}
