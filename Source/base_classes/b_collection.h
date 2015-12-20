#ifndef b_collectionH
#define b_collectionH

#include <stdlib.h>

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

//---------------------------------------------------------------------------
//	BCollection
//
//
//---------------------------------------------------------------------------
class BCollection
{
	private:
		int ItemIndex;
		BCollection *Parent;

	public:
		int Count;
		BCollection **Items;

		BCollection();
		virtual ~BCollection();

		void AddItem(BCollection *, int);
		void Delete(BCollection *);
		void DeleteItem(int);
		void DeleteAll();
		virtual int GetItemIndex();
};

#endif
