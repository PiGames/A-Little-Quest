#pragma once

#include <functional>
#include <cmath>
#include "components/Collider.hpp"
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

		void Update(float);

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
		void SetVelocity(const sf::Vector2f& velocity)
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
		sf::Vector2f velocity;
		float dt;
	};
}