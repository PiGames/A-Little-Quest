#pragma once

#include "piTypes\Point.hpp"

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

	namespace cell
	{
		constexpr auto ROTATION_MODES = 4;
		constexpr auto STRAIGHT_ANGLE = 90;
		constexpr pi::CompileTimeDoubleTemplateValuesForExampleCompileTimeDoubleTemplateValuesForExamplefloatDoubleFloatType<float> CELL_DIMENSIONS = { 64,64 };
	}
}