#pragma once
#include "Train_Info.h"
class Schedule
{
	Train_Info* pTrain;
	int Count;
	int uiPosition;
public:
	Schedule();
	Schedule(int);
	void Input();
	void Show();
	~Schedule();
	Train_Info* GetTrain();
	void Find(char*);
	Train_Info* begin();
	Train_Info* end();
	int GetCount();
};

