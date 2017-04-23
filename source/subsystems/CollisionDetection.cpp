#include "CollisionDetection.hpp"

namespace pg
{
	void CollisionDetection::Update()
	{
		std::vector<std::shared_ptr<DrawableComponent>> drawables;

		// Max float range
		if (dt < 34.f * pow(10, 37))
			dt++;
		else
			dt = 0;

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

						// float velocity = dynamic_cast<float>(*sBase->GetComponent<uint32_t>(this->collisionBlocks[0].get().GetFreeComponentWrapper()->ownerEntityID).data);

						if (objectA.top >= objectB.top + objectB.height && objectA.top <= objectB.top + objectB.height)
							reaction(collidedDirection_t::TOP);
						else if (objectA.top + objectA.height <= objectB.top && objectA.top + objectA.height >= objectB.top)
							reaction(collidedDirection_t::BOTTOM);
						else if(objectA.left + objectA.width <= objectB.left && objectA.left + objectA.width >= objectB.left)
							reaction(collidedDirection_t::LEFT);
						else if (objectA.left >= objectB.left + objectB.width && objectA.left <= objectB.left + objectB.width)
							reaction(collidedDirection_t::RIGHT);
				}
			}
		}
	}
}