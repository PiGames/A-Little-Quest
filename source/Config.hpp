#pragma once

namespace constants
{
	constexpr int16_t EXIT_STATE = 0xdad;

	namespace worldConstructor
	{
		constexpr auto MAP_PREFIX = "MAP";
	}

	namespace logger
	{
		constexpr auto PREFIX_INFO = "[INFO]";
		constexpr auto PREFIX_SUGGESTION = "[SUGGESTION]";
		constexpr auto PREFIX_WARNING = "[WARNING]";
		constexpr auto PREFIX_ERROR = "[ERROR]";
	}
}