#pragma once
#include "Train_Info.h"
#include "Iterator.h"
class Schedule 
{
	Train_Info* pTrain;
	int Count;
public:
	Schedule();
	Schedule(int);
	void Input();
	void SetSizeOfSchedule(unsigned int value);
	void Show();
	 ~Schedule();
	
	void Find(const char*);
	Iterator BeginOfSchedule() { return pTrain; }
	Iterator EndOfSchedule() { return pTrain + Count; }
};

