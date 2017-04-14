#pragma once

#include <atomic>
#include <thread>

#include <SFML/Graphics/RenderWindow.hpp>

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		Virtual State class. You can make load screen with it. You must overwrite
		OnStart, OnStop, Run and UpdateThread.

	===============================================================================
	*/
	class State
	{
	public:
		State( sf::RenderWindow* window ) :
			windowPtr( window ),
			threadRunning( false )
		{}

		State( const State& ) = delete;
		const State& operator =( const State& ) = delete;

		virtual ~State() = default;

		void SetWindowPtr( sf::RenderWindow* window )
		{
			this->windowPtr = window;
		}

		virtual void OnStart() = 0;
		virtual void OnStop() = 0;
		virtual int16_t Run() = 0;

		// Call it when you need to load resources and you don't want to freeze window.
		// Don't forget to call EndThread().
		void StartThread();
		void EndThread();
		// Updates thread.
		virtual void UpdateThread( float time, sf::RenderWindow& window ) = 0;
		// This method is called when thread is stared - it's its loop.
		virtual void ThreadMethod();

	protected:
		void unlockWindowContext()
		{
			this->windowPtr->setActive( true );
		}
		void lockWindowContext()
		{
			this->windowPtr->setActive( false );
		}

		sf::RenderWindow* windowPtr;

	private:
		std::thread thread;
		std::atomic_bool threadRunning;
	};
}