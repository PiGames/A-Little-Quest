/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

namespace pi
{
	enum class entityID
	{
		UNDEFINED = 0,
		PLAYER,
		ENEMY,

		GUI_BUTTON_PLAY,
		GUI_BUTTON_EXIT
	};

	/*
	===============================================================================
		Tag Component struct contains entityID tag field. Tag is set to UNDEFINED
		by default.

	===============================================================================
	*/
	struct TagComponent final
	{
		entityID tag;

		TagComponent( entityID tg = entityID::UNDEFINED ) :
			tag( tg )
		{}
	};
}