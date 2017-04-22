#pragma once

#include <functional>
#include "components/Drawable.hpp"
#include "ecs/ComponentBlock.hpp"


namespace pg
{
	enum direction_t
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	class CollisionDetection final
	{
	public:

		void Update();

		void SetComponentBlocks(std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components)
		{
			this->collisionBlocks = components;
		}

		void SetReactionOnCollision(std::function<void(direction_t)> function)
		{
			this->reaction = function;
		}

		void ClearData()
		{
			this->collisionBlocks.clear();
		}

	private:
		std::function<void(direction_t)> reaction;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collisionBlocks;
		float dt;
	};
}