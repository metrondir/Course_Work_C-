#include "Schedule.h"
#include <iostream>

Schedule::Schedule()
{
	pTrain = new Train_Info[Count];
	Count = 0;
}

Schedule::Schedule(int nCount)
{
	Count = nCount;
	pTrain = new Train_Info[nCount];
}

Schedule::~Schedule(void)
{
	delete[]pTrain;
}

void Schedule::Input()
{
	for (int i = 0; i < Count; i++)
		std::cin >> pTrain[i];	
}

void Schedule::SetSizeOfSchedule(unsigned int value)
{
	if (value == 0)
		throw Exception("Error typing size of Schedule! It is not integer");
	Count = value;
	pTrain = new Train_Info[Count];
}

void Schedule::Show()
{
	if (BeginOfSchedule() != EndOfSchedule()) {
		for (Iterator it = BeginOfSchedule(); it != EndOfSchedule(); it++) {
			if (strcmp((*it).GetDestination(), "Unknown") == 0) {
				break;
			}
			else {
				std::cout << *it << std::endl;
			}
		}
	}
	else {
		throw Exception("Empty schedule\n");
	}
}

void Schedule::Find(const char* destination)
{
		bool found_train = false;
		int earliest_time = INT_MAX;
		int count = 0;
			for (int i = 0; i < Count; i++)
			{
				if (strcmp(pTrain[i].GetDestination(), destination) == 0)
				{
					int departure_time = pTrain[i].GetHours() * 3600 + pTrain[i].GetMinutes() * 60 + pTrain[i].GetSeconds();

					if (departure_time < earliest_time)
					{
						earliest_time = departure_time;
						count = i;
						found_train = true;
					}
				}
			}
			if (!found_train)
			{
				throw Exception("No train was found to the destination.");
			}		
		if (found_train)
		{
			Train_Info finder = pTrain[count];
			std::cout << "The earliest train to " << destination << " is: \n" << finder << std::endl;
		}
}

