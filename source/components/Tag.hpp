/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include "piTypes/Enums.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Tag Component struct contains entityID tag field. Tag is set to UNDEFINED
		by default.

	===============================================================================
	*/
	struct TagComponent final
	{
		entityID_t tag;

		TagComponent( entityID_t tg = entityID_t::UNDEFINED ) :
			tag( tg )
		{}
	};
}