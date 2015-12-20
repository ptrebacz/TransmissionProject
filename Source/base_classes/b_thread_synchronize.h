//---------------------------------------------------------------------------

#ifndef b_thread_synchronizeH
#define b_thread_synchronizeH

#include "b_defines.h"

#ifdef _WIN32
	#include <windows.h>
#elif __linux__
	#include <pthread.h>
#endif

class MCriticalSection;

//---------------------------------------------------------------------------

class MCriticalSection
{
	private:
		#ifdef _WIN32
			CRITICAL_SECTION *sc;
		#elif __linux__
			pthread_mutex_t sc;
		#endif

	public:
		MCriticalSection();
		~MCriticalSection();

		void Enter();
		void Leave();
};

#endif
