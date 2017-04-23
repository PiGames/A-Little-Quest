#pragma once

#include <functional>
#include <cmath>
#include "components/Drawable.hpp"
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
			sBase(base)
		{}

		void Update();

		// Set objects
		void SetComponentBlocks(std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components)
		{
			this->collisionBlocks = components;
		}

		// Set function for reaction
		void SetReactionOnCollision(std::function<void(collidedDirection_t)> function)
		{
			this->reaction = function;
		}

		// Set objects velocity
		void SetVelocity(float velocity)
		{
			this->velocity = velocity;
		}

		// Clear collisionBlocks vector
		void ClearData()
		{
			this->collisionBlocks.clear();
		}

	private:
		std::shared_ptr<ecs::SystemBase> sBase;
		std::function<void(collidedDirection_t)> reaction;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collisionBlocks;
		float velocity, dt;
	};
}