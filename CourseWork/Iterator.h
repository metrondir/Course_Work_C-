#pragma once
#include "Exception.h"
#include "Train_Info.h"
class Iterator
{
protected:
	Train_Info* Buffer;
public:
	Iterator(Train_Info* pTrain);
	~Iterator();

	Train_Info& operator++(int);
	Train_Info& operator+=(int value);
	bool operator!=(const Iterator& value);
	bool operator>=(const Iterator& value);
	bool operator<=(const Iterator& value); 
	Train_Info operator*();
};

