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
		COLLISION_NONE = 0,
		COLLISION_TOP,
		COLISION_BOTTOM,
		COLLISION_LEFT,
		COLLISION_RIGHT
	};

	/*
	===============================================================================
	Created by: Uriel
		CollisionDetection is class where you can set coponenty blocks to chechked
		for collision event.

	===============================================================================
	*/
	class CollisionDetection final
	{
	public:

		CollisionDetection( ecs::SystemBase* base ) :
			systemBase( base )
		{}

		void Update( float dt );

		// Set objects
		void SetComponentBlocks( std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components )
		{
			this->collisionBlocks = components;
		}

		// Clear collisionBlocks vector and reactions vector
		void ClearData()
		{
			this->collisionBlocks.clear();
		}

	private:
		std::shared_ptr<ecs::SystemBase> systemBase;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collisionBlocks;

		std::vector<std::pair<std::shared_ptr<VelocityComponent>, std::shared_ptr<ColliderComponent>>> getColliders();
	};
}