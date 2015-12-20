#ifndef b_definesH
#define b_definesH

//---------------------------------------------------------------------------
//	Universal definitions
//
//
//---------------------------------------------------------------------------

#ifndef __linux
    #define NULL 0
#endif

#define SAFEDELETE(ptr){if(ptr){delete ptr; ptr = NULL;}}
#define SAFEDELETEA(ptr){if(ptr){delete[] ptr; ptr = NULL;}}
#define SAFEDELETEAA(ptr, size){if(ptr){for(int i=size-1; i>=0; i--){delete[] ptr[i]; ptr[i] = NULL;}}}

#endif
