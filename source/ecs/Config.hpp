/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <cinttypes>

namespace ecs
{
	/*
	========================================
		Data types definitions.
	========================================
	*/

	using entityID_t = uint32_t;

	/*
	========================================
		Compile time constants.
	========================================
	*/

	// Initialize entityID_t using this value.
	constexpr entityID_t UNASSIGNED_ENTITY_ID = 0;
	// Amount of components in one data block.
	// TODO: change to 16
	constexpr size_t MAX_COMPONENT_BLOCK_SIZE = 1;
	constexpr size_t MAX_COMPONENT_BLOCKS = 128;
}
