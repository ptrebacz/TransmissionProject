//---------------------------------------------------------------------------

#ifndef b_transmissionH
#define b_transmissionH

#include "b_collection.h"
#include <System.hpp>

class BTransmission;
class BTransaction;

//---------------------------------------------------------------------------
//	BTransmission
//
//
//---------------------------------------------------------------------------
class BTransmission : public BCollection
{
	public:
		BTransmission();
		~BTransmission();

		void Add(BTransaction *);
		BTransaction *GetItem(int index){return((index<0 || index >= Count)?NULL:(BTransaction*)Items[index]);};
};

//---------------------------------------------------------------------------
//	BTransaction
//
//
//---------------------------------------------------------------------------
class BTransaction : public BCollection
{
	public:
		BTransaction();
		~BTransaction();

		UnicodeString name;
};

#endif


