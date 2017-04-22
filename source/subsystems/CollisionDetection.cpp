#include "CollisionDetection.hpp"

namespace pg
{
	void CollisionDetection::Update()
	{
		std::vector<std::shared_ptr<DrawableComponent>> drawables;
		dt++;

		for (ecs::internal::componentBlock_t& block : this->collisionBlocks)
			for (auto& wrapper : block.data)
				if (wrapper.ownerEntityID != ecs::UNASSIGNED_ENTITY_ID)
					drawables.push_back(std::static_pointer_cast<DrawableComponent>(wrapper.data));

		for (auto drawable : drawables)
		{
			for (auto& sprite : drawable->sprites)
			{
				for (auto& spriteToCompare : drawable->sprites)
				{
					if (!sprite.getGlobalBounds().intersects(spriteToCompare.getGlobalBounds()))
					{
						sf::FloatRect& objectA = sprite.getGlobalBounds();
						sf::FloatRect& objectB = spriteToCompare.getGlobalBounds();

					}
				}
			}
		}
	}
}