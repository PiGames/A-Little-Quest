#include "UI.hpp"

namespace ui
{
	// Public

	UI::UI( )
	{
		this->elementArrayLenght = 0;
	}

	UI::UI( sf::RenderWindow& window )
	{
		this->window = &window;
		this->elementArrayLenght = 0;
	}

	void UI::setWindow( sf::RenderWindow& window )
	{
		this->window = &window;
	}

	// Button methods

	void UI::useButtons( sf::Event& event )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::BUTTON )
				{
					i->use( event );
				}
			}
		}
	}

	void UI::updateButtons( sf::RenderWindow& window )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::BUTTON )
				{
					i->update( window );
				}
			}
		}
	}

	void UI::updateButtons()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				if (i->type == elementType_t::BUTTON)
				{
					i->update( *this->window );
				}
			}
		}
	}

	// Checkbox methods

	void UI::useCheckboxs( sf::Event& event )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::CHECKBOX )
				{
					i->use( event );
				}
			}
		}
	}

	void UI::updateCheckboxs( sf::RenderWindow& window )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::CHECKBOX )
				{
					i->update( window );
				}
			}
		}
	}

	void UI::updateCheckboxs()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				if (i->type == elementType_t::CHECKBOX)
				{
					i->update( *this->window );
				}
			}
		}
	}

	// Slider methods

	void UI::useSliders( sf::Event& event )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::SLIDER )
				{
					i->use( event );
				}
			}
		}
	}

	void UI::updateSliders( sf::RenderWindow& window )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::SLIDER )
				{
					i->update( window );
				}
			}
		}
	}

	void UI::updateSliders()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				if (i->type == elementType_t::SLIDER)
				{
					i->update(*this->window);
				}
			}
		}
	}

	// List methods

	void UI::useLists( sf::Event& event )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::LIST )
				{
					i->use( event );
				}
			}
		}
	}

	void UI::updateLists( sf::RenderWindow& window )
	{
		for( auto &i : this->elements )
		{
			if( i )
			{
				if( i->type == elementType_t::LIST )
				{
					i->update( window );
				}
			}
		}
	}

	void UI::updateLists()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				if (i->type == elementType_t::LIST)
				{
					i->update(*this->window);
				}
			}
		}
	}

	// Textbox methods

	void UI::useTextbox( sf::Event& event )
	{
		for ( auto &i : this->elements )
		{
			if ( i )
			{
				if ( i->type == elementType_t::TEXTBOX )
				{
					i->use( event );
				}
			}
		}
	}

	void UI::updateTextbox( sf::RenderWindow& window )
	{
		for ( auto &i : this->elements )
		{
			if ( i )
			{
				if ( i->type == elementType_t::TEXTBOX )
				{
					i->update( window );
				}
			}
		}
	}
	void UI::updateTextbox()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				if (i->type == elementType_t::TEXTBOX)
				{
					i->update(*this->window);
				}
			}
		}
	}

	// All section

	void UI::update(sf::RenderWindow& window)
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				i->update(window);
			}
		}
	}

	void UI::update()
	{
		for (auto &i : this->elements)
		{
			if (i)
			{
				i->update(*this->window);
			}
		}
	}
}