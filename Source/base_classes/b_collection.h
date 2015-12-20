#ifndef b_collectionH
#define b_collectionH

#include <stdlib.h>
#include "b_defines.h"
#include "b_thread_synchronize.h"

//---------------------------------------------------------------------------
//	BCollection
//
//
//---------------------------------------------------------------------------
class BCollection
{
	private:
		MCriticalSection *mcs;
		int *ItemIndex;
		BCollection *Parent;

		BCollection *ActionOnCollection(int, BCollection*, int, int *res = NULL);

        virtual BCollection *PrivateGetItem(int);
		void PrivateAddItem(BCollection *, int);
		void PrivateDelete(BCollection *);
		void PrivateDeleteItem(int);
		void PrivateDeleteAll();
		virtual int PrivateGetItemIndex();
		int PrivateCount();

		int *Counter;
		BCollection **Items;

	public:
		BCollection();
		virtual ~BCollection();

        virtual BCollection *GetItem(int);
		void AddItem(BCollection *, int index = -1);
		void Delete(BCollection *);
		void DeleteItem(int);
		void DeleteAll();
		virtual int GetItemIndex();
		int Count();
};

#endif
