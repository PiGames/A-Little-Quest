#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "components/Drawable.hpp"
#include "ecs/ComponentBlock.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Renderer uses a component blocks of DrawableCompoents. You should get them
		using Reserve method in ecs::SystemBase. Pass them directly here.

	===============================================================================
	*/
	class Renderer final
	{
	public:
		Renderer( sf::RenderWindow& win ) :
			window( win )
		{}

		void SetComponentBlocks( std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components )
		{
			this->drawableBlocks = components;
		}

		void ClearWindow( sf::Color clearColor = sf::Color::Black ) 
		{ 
			this->window.clear( clearColor ); 
		}
		void Render();
		void Display()
		{
			this->window.display();
		}
		void Clear()
		{
			this->drawableBlocks.clear();
		}

	private:
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> drawableBlocks;
		sf::RenderWindow& window;

		std::pair<int8_t, int8_t> getDrawLayersInterval( const std::vector<std::shared_ptr<DrawableComponent>>& drawables );
	};
}