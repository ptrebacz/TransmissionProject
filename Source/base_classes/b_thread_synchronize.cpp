//---------------------------------------------------------------------------

#pragma hdrstop

#include "b_thread_synchronize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//	MCriticalSection
//
//
//---------------------------------------------------------------------------
MCriticalSection::MCriticalSection()
{
	#ifdef _WIN32
		sc = new CRITICAL_SECTION;
		InitializeCriticalSection(sc);
	#elif __linux__
		sc = PTHREAD_MUTEX_INITIALIZER;
	#endif
}

//---------------------------------------------------------------------------
//	Enter
//
//
//---------------------------------------------------------------------------
void MCriticalSection::Enter()
{
	#ifdef _WIN32
		EnterCriticalSection(sc);
	#elif __linux__
		pthread_mutex_lock(&sc);
	#endif
}

//---------------------------------------------------------------------------
//	Leave
//
//
//---------------------------------------------------------------------------
void MCriticalSection::Leave()
{
	#ifdef _WIN32
		LeaveCriticalSection(sc);
	#elif __linux__
		pthread_mutex_unlock(&sc);
	#endif
}

//---------------------------------------------------------------------------
//	~MCriticalSection
//
//
//---------------------------------------------------------------------------
MCriticalSection::~MCriticalSection()
{
	#ifdef _WIN32
		DeleteCriticalSection(sc);
		SAFEDELETE(sc);
//	#elif __linux__
//
	#endif
}


