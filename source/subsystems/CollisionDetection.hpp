#pragma once

#include "components/Drawable.hpp"
#include "ecs/ComponentBlock.hpp"
#include "logger/Logger.hpp"
#include "map/MapManager.hpp"

namespace pg
{
	class CollisionDetection final
	{
	public:

		CollisionDetection() = default;
		~CollisionDetection() = default;

		void Detection();

		void SetComponentBlocks(std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components)
		{
			this->collisionBlocks = components;
		}

		void ClearData()
		{
			this->collisionBlocks.clear();
		}

	private:
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collisionBlocks;
	};
}