//---------------------------------------------------------------------------

#pragma hdrstop

#include "b_collection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
//	BCollection
//
//
//---------------------------------------------------------------------------
BCollection::BCollection()
{
	Count = 0;
	ItemIndex = -1;
	Parent = NULL;
	Items = NULL;

}

//---------------------------------------------------------------------------
//	AddItem
//
//
//---------------------------------------------------------------------------
void BCollection::AddItem(BCollection *obj, int index)
{
	Items = (BCollection**)realloc(Items, (Count+1)*sizeof(BCollection*));
	if(index >= Count)
	{
		Items[Count] = obj;
	}
	else if(index < Count)
	{
		for(int i=Count; i>index; i--)
			Items[i] = Items[i-1];

		Items[index] = obj;
	}
	obj->ItemIndex = index;
	obj->Parent = this;
	Count++;
}

//---------------------------------------------------------------------------
//	Delete
//
//
//---------------------------------------------------------------------------
void BCollection::Delete(BCollection *obj)
{
	for(int i=Count-1; i>=0; i--)
	{
		if(Items[i] == obj)
		{
			SAFEDELETE(Items[i]);
			for(int ii=i; ii<Count-1; ii++)
				Items[ii] = Items[ii+1];

			if((Count-1)>0)
				Items = (BCollection**)realloc(Items, (Count-1)*sizeof(BCollection*));
			else
				SAFEDELETE(Items);
			Count--;
			break;
		}
	}
}

//---------------------------------------------------------------------------
// 	DeleteItem
//
//
//---------------------------------------------------------------------------
void BCollection::DeleteItem(int index)
{
	if(index >=0 && index < Count)
		Delete(Items[index]);
}

//---------------------------------------------------------------------------
//	DeleteAll
//
//
//---------------------------------------------------------------------------
void BCollection::DeleteAll()
{
	for(int i=Count-1; i>=0; i--)
	{
		SAFEDELETE(Items[i]);
		Count--;
	}
	SAFEDELETEA(Items);
}

//---------------------------------------------------------------------------
//	GetItemIndex
//
//
//---------------------------------------------------------------------------
int BCollection::GetItemIndex()
{
	return ItemIndex;
}

//---------------------------------------------------------------------------
// 	~BCollection
//
//
//---------------------------------------------------------------------------
BCollection::~BCollection()
{
	DeleteAll();
}

