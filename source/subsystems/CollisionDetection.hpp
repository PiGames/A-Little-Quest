#pragma once

#include <functional>
#include <cmath>
#include "components/Collider.hpp"
#include "components/Velocity.hpp"
#include "ecs/ComponentBlock.hpp"
#include "ecs/SystemBase.hpp"

namespace pg
{
	enum collidedDirection_t
	{
		TOP,
		BOTTOM,
		LEFT,
		RIGHT
	};

	class CollisionDetection final
	{
	public:

		CollisionDetection(std::shared_ptr<ecs::SystemBase> base) :
			systemBase(base)
		{}

		void Update(float);

		// Set objects
		void SetComponentBlocks(std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components)
		{
			this->collisionBlocks = components;
		}

		// Set function for reaction
		void SetReactionOnCollision(std::vector <std::function<void(std::shared_ptr<ColliderComponent>, collidedDirection_t, std::shared_ptr<ecs::SystemBase>)>> functions)
		{
			this->reactions = functions;
		}

		// Clear collisionBlocks vector and reactions vector
		void ClearData()
		{
			this->collisionBlocks.clear();
			this->reactions.clear();
		}

	private:
		std::shared_ptr<ecs::SystemBase> systemBase;
		std::vector <std::function<void(std::shared_ptr<ColliderComponent>, collidedDirection_t, std::shared_ptr<ecs::SystemBase>)>> reactions;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collisionBlocks;
		float dt;
	};
}