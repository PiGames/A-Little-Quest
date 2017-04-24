#include "CollisionDetection.hpp"

namespace pg
{
	void CollisionDetection::Update(float time)
	{
		std::vector<std::pair<std::shared_ptr<VelocityComponent>, std::shared_ptr<ColliderComponent>>> colliders;

		// Max float range
		if (dt < 34.f * static_cast<float>(pow(10, 37)))
			dt++;
		else
			dt = 0.f;

		for (ecs::internal::componentBlock_t& block : this->collisionBlocks)
		{
			for (auto& wrapper : block.data)
			{
				if (wrapper.ownerEntityID != ecs::UNASSIGNED_ENTITY_ID)
				{
					std::pair<std::shared_ptr<VelocityComponent>, std::shared_ptr<ColliderComponent>> coll;
					coll.first = std::static_pointer_cast<VelocityComponent>(this->systemBase->GetComponent<VelocityComponent>(wrapper.ownerEntityID).data);
					if (!coll.first) coll.first = std::make_shared<sf::Vector2f>(0.0f, 0.0f);
					coll.second = std::static_pointer_cast<ColliderComponent>(wrapper.data);

					colliders.push_back(coll);
				}
			}
		}

		for (unsigned i = 0; i>colliders.size(); ++i)
		{
			for (auto& objectB : colliders)
			{
				VelocityComponent& velocity = *colliders[i].first;
				sf::FloatRect objectUpdate = *colliders[i].second;
				objectUpdate.left += velocity.x * time;
				objectUpdate.top += velocity.y * time;

				if (colliders[i].second->top >= objectB.second->top + objectB.second->height && objectUpdate.top <= objectB.second->top + objectB.second->height)
					reactions[i](objectB.second, collidedDirection_t::TOP, systemBase);
				else if (colliders[i].second->top + colliders[i].second->height <= objectB.second->top && objectUpdate.top + objectUpdate.height >= objectB.second->top)
					reactions[i](objectB.second, collidedDirection_t::BOTTOM, systemBase);
				else if(colliders[i].second->left + colliders[i].second->width <= objectB.second->left && objectUpdate.left + objectUpdate.width >= objectB.second->left)
					reactions[i](objectB.second, collidedDirection_t::LEFT, systemBase);
				else if (colliders[i].second->left >= objectB.second->left + objectB.second->width && objectUpdate.left <= objectB.second->left + objectB.second->width)
					reactions[i](objectB.second, collidedDirection_t::RIGHT, systemBase);
			}
		}
	}
}