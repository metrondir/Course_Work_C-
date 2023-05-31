#pragma once
#include "Train_Info.h"
#include "Iterator.h"
class Schedule 
{
	Train_Info* trains;
	int count;
public:
	Schedule();
	Schedule(int);
	void Input();
	void SetSizeOfSchedule(unsigned int value);
	void Show();
	 ~Schedule();
	
	void FindNearestTrain(const char*);
	Iterator BeginOfSchedule() { return trains; }
	Iterator EndOfSchedule() { return trains+ count; }
};

