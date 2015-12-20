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
	mcs = new MCriticalSection();
	Counter = new int;
	*Counter = 0;
	ItemIndex = new int;
	*ItemIndex = -1;
	Parent = NULL;
	Items = NULL;
}

//---------------------------------------------------------------------------
//	ActionOnCollection
//
//
//---------------------------------------------------------------------------
BCollection *BCollection::ActionOnCollection(int type, BCollection* object, int index, int *res)
{
	try
	{
        mcs->Enter();
		switch(type)
		{
			//Add
			case 0:
			{
				PrivateAddItem(object, index);
				break;
			}
			//GetItem
			case 1:
			{
				return PrivateGetItem(index);
				break;
			}
			//GetItemIndex
			case 2:
			{
				*res = PrivateGetItemIndex();
				break;
			}
			//Delete item
			case 3:
			{
				PrivateDeleteItem(index);
				break;
			}
			//Delete object
			case 4:
			{
				PrivateDelete(object);
				break;
			}
			//Delete all
			case 5:
			{
				PrivateDeleteAll();
				break;
			}
			//GetCount
			case 6:
			{
				*res = PrivateCount();
				break;
			}
		}
	}
	__finally
	{
		mcs->Leave();
    }
}

//---------------------------------------------------------------------------
//	PrivateGetItem
//
//
//---------------------------------------------------------------------------
BCollection *BCollection::PrivateGetItem(int index)
{
	if(index<0 || index>=*Counter)
		return NULL;
	else
		return Items[index];
}

//---------------------------------------------------------------------------
//	PrivateAddItem
//
//
//---------------------------------------------------------------------------
BCollection *BCollection::GetItem(int index)
{
	return ActionOnCollection(1, NULL, index);
}

//---------------------------------------------------------------------------
//	PrivateAddItem
//
//
//---------------------------------------------------------------------------
void BCollection::PrivateAddItem(BCollection *obj, int index)
{
	Items = (BCollection**)realloc(Items, ((*Counter)+1)*sizeof(BCollection*));
	if(index >= *Counter)
	{
		Items[*Counter] = obj;
	}
	else if(index < *Counter)
	{
		for(int i=*Counter; i>index; i--)
			Items[i] = Items[i-1];

		Items[index] = obj;
	}
	*obj->ItemIndex = index;
	obj->Parent = this;
	(*Counter)++;
}

//---------------------------------------------------------------------------
//	AddItem
//
//
//---------------------------------------------------------------------------
void BCollection::AddItem(BCollection *obj, int index)
{
	if(index < 0)
		ActionOnCollection(0, obj, *Counter);
	else
		ActionOnCollection(0, obj, index);
}

//---------------------------------------------------------------------------
//	PrivateDelete
//
//
//---------------------------------------------------------------------------
void BCollection::PrivateDelete(BCollection *obj)
{
	for(int i=(*Counter)-1; i>=0; i--)
	{
		if(Items[i] == obj)
		{
			SAFEDELETE(Items[i]);
			for(int ii=i; ii<(*Counter)-1; ii++)
				Items[ii] = Items[ii+1];

			if(((*Counter)-1)>0)
				Items = (BCollection**)realloc(Items, ((*Counter)-1)*sizeof(BCollection*));
			else
				SAFEDELETE(Items);
			(*Counter)--;
			break;
		}
	}
}

//---------------------------------------------------------------------------
//	Delete
//
//
//---------------------------------------------------------------------------
void BCollection::Delete(BCollection *obj)
{
	ActionOnCollection(4, obj, -1);
}

//---------------------------------------------------------------------------
// 	PrivateDeleteItem
//
//
//---------------------------------------------------------------------------
void BCollection::PrivateDeleteItem(int index)
{
	if(index >=0 && index < *Counter)
		Delete(Items[index]);
}

//---------------------------------------------------------------------------
// 	DeleteItem
//
//
//---------------------------------------------------------------------------
void BCollection::DeleteItem(int index)
{
	ActionOnCollection(3, NULL, index);
}


//---------------------------------------------------------------------------
//	PrivateDeleteAll
//
//
//---------------------------------------------------------------------------
void BCollection::PrivateDeleteAll()
{
	for(int i=(*Counter)-1; i>=0; i--)
	{
		SAFEDELETE(Items[i]);
		(*Counter)--;
	}
	SAFEDELETEA(Items);
}

//---------------------------------------------------------------------------
//	DeleteAll
//
//
//---------------------------------------------------------------------------
void BCollection::DeleteAll()
{
	ActionOnCollection(5, NULL, -1);
}

//---------------------------------------------------------------------------
//	PrivateGetItemIndex
//
//
//---------------------------------------------------------------------------
int BCollection::PrivateGetItemIndex()
{
	return *ItemIndex;
}

//---------------------------------------------------------------------------
//	GetItemIndex
//
//
//---------------------------------------------------------------------------
int BCollection::GetItemIndex()
{
	int index = -1;
	ActionOnCollection(2,NULL, -1, &index);
	return index;
}

//---------------------------------------------------------------------------
//	PrivateGetItemIndex
//
//
//---------------------------------------------------------------------------
int BCollection::PrivateCount()
{
	return *Counter;
}

//---------------------------------------------------------------------------
//	GetItemIndex
//
//
//---------------------------------------------------------------------------
int BCollection::Count()
{
	int count = -1;
	ActionOnCollection(6,NULL, -1, &count);
	return count;
}

//---------------------------------------------------------------------------
// 	~BCollection
//
//
//---------------------------------------------------------------------------
BCollection::~BCollection()
{
	Parent = NULL;
	if(Counter>0)
		ActionOnCollection(5,NULL,-1);

	Items = NULL;
	SAFEDELETE(mcs);
	SAFEDELETE(Counter);
	SAFEDELETE(ItemIndex);
}

