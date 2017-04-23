#include "CollisionDetection.hpp"

namespace pg
{
	void CollisionDetection::Update(float time)
	{
		std::vector<std::shared_ptr<ColliderComponent>> colliders;

		// Max float range
		if (dt < 34.f * static_cast<float>(pow(10, 37)))
			dt++;
		else
			dt = 0;

		for (ecs::internal::componentBlock_t& block : this->collisionBlocks)
			for (auto& wrapper : block.data)
				if (wrapper.ownerEntityID != ecs::UNASSIGNED_ENTITY_ID)
					colliders.push_back(std::static_pointer_cast<ColliderComponent>(wrapper.data));

		for (auto& objectA : colliders)
		{
			for (auto& objectB : colliders)
			{
				// velocity = dynamic_cast<sf::Vector2f>(*sBase->GetComponent<uint32_t>(this->collisionBlocks[0].get().GetFreeComponentWrapper()->ownerEntityID).data);

				sf::FloatRect objectUpdate = *objectA;
				objectUpdate.left += this->velocity.x * time;
				objectUpdate.top += this->velocity.y * time;

				if (objectA->top >= objectB->top + objectB->height && objectUpdate.top <= objectB->top + objectB->height)
					reaction(collidedDirection_t::TOP);
				else if (objectA->top + objectA->height <= objectB->top && objectUpdate.top + objectUpdate.height >= objectB->top)
					reaction(collidedDirection_t::BOTTOM);
				else if(objectA->left + objectA->width <= objectB->left && objectUpdate.left + objectUpdate.width >= objectB->left)
					reaction(collidedDirection_t::LEFT);
				else if (objectA->left >= objectB->left + objectB->width && objectUpdate.left <= objectB->left + objectB->width)
					reaction(collidedDirection_t::RIGHT);
			}
		}
	}
}