#ifndef bstringsH
#define bstringsH
//---------------------------------------------------------------------------

#ifdef __linux__
    #include <string>
	#include <iostream>

	#define MString std::string
#endif

#ifdef _WIN32
	#include <System.hpp>
	#define MString UnicodeString
#endif

#endif
