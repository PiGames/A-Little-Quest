#include "State.hpp"

namespace pi
{
	void State::StartThread()
	{
		this->lockWindowContext();
		this->threadRunning = true;

		this->thread = std::thread( &State::ThreadMethod, this );
	}

	void State::EndThread()
	{
		this->threadRunning = false;
		this->thread.join();

		this->unlockWindowContext();
	}

	void State::ThreadMethod()
	{
		this->unlockWindowContext();

		while ( this->threadRunning )
		{
			this->UpdateThread( 1 / 30.0f, *this->windowPtr );
		}

		this->lockWindowContext();
	}
}