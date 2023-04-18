#include "Schedule.h"

Schedule::Schedule(void)
{
	pTrain = new Train_Info[0];
	Count = 0;
	uiPosition = 0;
}
Schedule::Schedule(int nCount)
{
	Count = nCount;
	uiPosition = 0;
	pTrain = new Train_Info[nCount];

}
Schedule::~Schedule(void)
{
	if (pTrain)
		delete[]pTrain;
}
void Schedule::Input()
{
	for (int i = 0; i < Count; i++)
	{
		std::cout << "List ¹" << i + 1 << std::endl;
		std::cin >> *(pTrain + i);
	}
}
Train_Info* Schedule::GetTrain()
{
	return pTrain;
}
int Schedule::GetCount()
{
	return Count;
}

void Schedule::Show()
{
	std::cout << std::endl;
	std::cout << "Schedule " << std::endl;
	for (int i = 0; i < Count; i++)
		std::cout << *(pTrain + i);
}
void Schedule::Find(char* _punkt)
{
	for (int i = 0; i < Count; i++)
	{
		if (strcmp(pTrain[i].GetDestination(), _punkt) == 0)
		{
			std::cout << pTrain[i] << std::endl;
		}
		else
		{
			std::cout << "There is no train to the given point " << std::endl;
		}
	}

}
Train_Info* Schedule::begin()
{
	if (pTrain == NULL || Count <= 0)
	{
		throw Exception("There are no trains yet");
	}
	uiPosition = 0;
	return pTrain;
}
Train_Info* Schedule::end()
{
	if (pTrain == NULL || Count <= 0)
	{
		throw Exception("There are no other trains");
	}
	return pTrain + Count;
}
