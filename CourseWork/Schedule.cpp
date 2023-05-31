#include "Schedule.h"
#include <iostream>

Schedule::Schedule()
{
	trains= new Train_Info[count];
	count = 0;
}

Schedule::Schedule(int nCount)
{
	count = nCount;
	trains= new Train_Info[nCount];
}

Schedule::~Schedule(void)
{
	delete[]trains;
}

void Schedule::Input()
{
	for (int i = 0; i < count; i++)
		std::cin >> trains[i];	
}

void Schedule::SetSizeOfSchedule(unsigned int value)
{
	if (value == 0)
		throw Exception("Error typing size of Schedule! It is not integer");
	count = value;
	trains= new Train_Info[count];
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

void Schedule::FindNearestTrain(const char* destination)
{
		bool found_train = false;
		int earliest_time = INT_MAX;
		int count = 0;
			for (int i = 0; i < count; i++)
			{
				if (strcmp(trains[i].GetDestination(), destination) == 0)
				{
					int departure_time = trains[i].GetHours() * 3600 + trains[i].GetMinutes() * 60 + trains[i].GetSeconds();

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
			Train_Info finder = trains[count];
			std::cout << "The earliest train to " << destination << " is: \n" << finder << std::endl;
		}
}

