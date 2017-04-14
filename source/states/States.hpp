#pragma once

#include "Config.hpp"

namespace pg
{
	// Game state enumerations
	enum class state_t
	{
		// Change to config value later.
		EXIT = constants::EXIT_STATE,
		INIT = 0,
		MENU,
		PLAY
	};
}