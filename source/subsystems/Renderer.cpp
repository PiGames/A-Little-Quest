#include "Renderer.hpp"

namespace pg
{
	void Renderer::Render()
	{
		std::vector<std::shared_ptr<DrawableComponent>> drawables;

		for ( ecs::internal::componentBlock_t& block : this->drawableBlocks )
			for ( auto& wrapper : block.data )
				if ( wrapper.ownerEntityID != ecs::UNASSIGNED_ENTITY_ID )
					drawables.push_back( std::static_pointer_cast<DrawableComponent>( wrapper.data ) );

		auto drawLayersInterval = this->getDrawLayersInterval( drawables );
		size_t entitiesAlreadyDrawn = 0;
		for (
			int8_t currentLayer = drawLayersInterval.first;
			( currentLayer < drawLayersInterval.second + 1 && entitiesAlreadyDrawn < drawables.size() );
			currentLayer++
			)
		{
			for ( auto drawable : drawables )
				if ( drawable->drawLayer == currentLayer )
				{
					for ( auto& sprite : drawable->sprites )
						this->window.draw( sprite );
					entitiesAlreadyDrawn++;
				}
		}
	}

	std::pair<int8_t, int8_t> Renderer::getDrawLayersInterval( const std::vector<std::shared_ptr<DrawableComponent>>& drawables )
	{
		int8_t min = INT8_MAX, max = INT8_MIN;
		int8_t currentLayer = 0;

		for ( auto drawable : drawables )
		{
			currentLayer = drawable->drawLayer;

			if ( currentLayer > max ) max = currentLayer;
			if ( currentLayer < min ) min = currentLayer;
		}

		return std::pair<int8_t, int8_t>( min, max );
	}
}