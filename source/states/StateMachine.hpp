#pragma once

#include <functional>
#include <cassert>
#include <unordered_map>
#include <memory>
#include <vector>

#include "State.hpp"

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		State Machine class. It cannot be copied or assigned. You must register
		states before using!

	===============================================================================
	*/
	class StateMachine final
	{
	public:
		StateMachine( int16_t startState = 0 ) :
			actualState( startState )
		{}

		StateMachine( const StateMachine& ) = delete;
		const StateMachine& operator=( const StateMachine& ) = delete;

		void SetCurrentStateID( int16_t id ) { this->actualState = id; }

		template<class T, typename... Args>
		typename std::enable_if<std::is_base_of<State, T>::value>::type
			RegisterState( int16_t id, Args&&... args )
		{
			this->factories[id] = [&args..., this]()
			{
				return std::make_unique<T>( std::forward<Args>( args )... );
			};
		}

		void Run();

	private:
		std::vector<std::unique_ptr<State>> stack;
		std::unordered_map<int16_t, std::function<std::unique_ptr<State>()>> factories;
		int16_t actualState;

		std::unique_ptr<State> createState( int16_t id );
	};
}
