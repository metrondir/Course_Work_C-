#pragma once
#include "Exception.h"
#include "Train_Info.h"
class Iterator
{
protected:
	Train_Info* Buffer;
	size_t Count;
	size_t Position;
public:
	Iterator(Train_Info* pTrain ,size_t Count);
	~Iterator();
	Train_Info* operator++();
	Train_Info* operator->();
	Train_Info* operator=(Train_Info* value);
	bool operator !=(Train_Info* value);
	Train_Info operator*();
};

