#include "Schedule.h"
#include "Time.h"

void Menu(Time& time, Train_Info& train, Schedule schedule);
void ChoiceChecker(unsigned int& choice);

int main() {
	
	Time time;
	Train_Info train;
	Schedule schedule;
	Menu(time, train, schedule);
}

void Menu(Time& time, Train_Info& train, Schedule schedule)
{
	char destination[256];
	std::cout << "+--------------------------------------------+\n";
	std::cout << "|   Choose what you would like to proceed:   |\n+--------------------------------------------+\n|\t0. Exit\t\t\t             |\n|\t1. Options about time\t\t     |\n|\t2. Options about train\t\t     |\n|\t3. Options about schedule\t     |\n";
	std::cout << "+--------------------------------------------+\n";
	unsigned int choice;
	ChoiceChecker(choice);
	switch (choice) {
	case 0:
	{
		exit(1);
	}
	case 1: {
		std::cout << "+--------------------------------------------+\n";
		std::cout << "|\t  What do you want to do:\t     |\n|   1. Write information about time\t     |\n|   2. Show information about time\t     |\n|   3. Increasing the value of time\t     |\n|   4. To reduce the time value\t\t     |\n|   5. Object assignment operation about time|\n|   6. Show information about time (virtual method GetTime)\t   \n";
		std::cout << "+--------------------------------------------+\n";
		ChoiceChecker(choice);
		switch (choice)
		{
		case 1:
		{		
			std::cin >> time;
			Menu(time, train, schedule);
			break;
		case 2:
		{
			std::cout << time;
			Menu(time, train, schedule);
			break;
		}
		case 3:
		{
			Time time1;
			std::cout << "Write first time\n";
			std::cin >> time;
			std::cout << "Write second time\n";
			std::cin >> time1;
			time += time1;
			std::cout << time;
			Menu(time, train, schedule);
			break;
		}
		case 4:
		{
			Time time1;
			std::cout << "Write first time\n";
			std::cin >> time;
			std::cout << "Write second time\n";
			std::cin >> time1;
			time -= time1;
			std::cout << time;
			Menu(time, train, schedule);
			break;
		}
		case 5:
		{
			Time time1;
			std::cout << "Write first time\n";
			std::cin >> time;
			std::cout << "Write second time\n";
			std::cin >> time1;
			time = time1;
			std::cout << time;
			Menu(time, train, schedule);
			break;
		}
		case 6:
		{
			Time time1;
			std::cout << "Write a time\n";
			std::cin >> time1;
			Time* time2 = &time1;
			std::cout << "Information about time\n";
			time2->GetTime(); 
			Menu(time, train, schedule);
			break;
		}
		default:
		{
			std::cout << "This function has not yet been added to the menu." << std::endl;
			Menu(time, train, schedule);
			break;
		}
		}
		}
		
	}
	case 2: {
		std::cout << "+--------------------------------------------+\n";
		std::cout << "|\t  What do you want to do:\t     |\n|   1. Write information about train\t     |\n|   2. Show information about train\t     |\n|   3. Show information about train (virtual method GetTime)\t\n";
		std::cout << "+--------------------------------------------+\n";
	
		ChoiceChecker(choice);
		switch (choice)
		{
		case 1:
		{
			std::cin >> train;
			Menu(time, train, schedule);
			break;
		case 2:
		{
			std::cout<<train;
			Menu(time, train, schedule);
			break;
		}
		case 3:
		{
			Train_Info train1;
			std::cout << "Write a train\n";
			std::cin >> train1;
			Train_Info* train2 = &train1;
			std::cout << "Inforamtion about train\n";
			train2->GetTime();
			Menu(time, train, schedule);
			break;
		}
		default:
		{
			std::cout << "This function has not yet been added to the menu." << std::endl;
			Menu(time, train, schedule);
			break;
		}
		}
		}
	}
	case 3: {
	std::cout << "+--------------------------------------------+\n";
	std::cout << "|\t  What do you want to do:\t     |\n|   1. Write information about schedule\t     |\n|   2. Show information about schedule\t     |\n|   3. Find the earliest train in schedule   |\n";
	std::cout << "+--------------------------------------------+\n";
	bool flag = true;
	ChoiceChecker(choice);
		switch (choice)
		{
		case 1:
		{
		while (flag){
			std::cout << "Type how many trains will be:\n";
			ChoiceChecker(choice);
			try {
				schedule.SetSizeOfSchedule(choice);
				flag = false;
			}
			catch (Exception ex) {
				std::cout << "Exception: " << ex.ShowException() << "\n";			
			}
		}
			std::cout << "Your schedule:\n";
			schedule.Input();
			Menu(time, train, schedule);
			break;
		case 2:
		{
			try
			{
				schedule.Show();
			}
			catch (Exception ex)
			{
				std::cout << ex.ShowException();
			}
			Menu(time, train, schedule);
			break;
		}
		case 3:
		{
			try {
				std::cout << "Enter Destination: " << std::endl;
				std::cin >> destination;
				schedule.Find(destination);
			}
			catch (Exception e) {
				std::cerr <<"Exception: " << e.ShowException() << std::endl;
			}
			Menu(time, train, schedule);
			break;
		}
		default:
		{
			std::cout << "This function has not yet been added to the menu." << std::endl;
			Menu(time, train, schedule);
			break;
		}
		
		}
		}
		}
	default:
	{
		std::cout << "This function has not yet been added to the menu." << std::endl;
		Menu(time, train, schedule);
		break;
	}
	}
	
	}
	void ChoiceChecker(unsigned int& choice) {
		bool flag = true;
		while (flag) {
			char input[256];
			try {
				std::cin >> input;
				char* endPtr;
				long parsedValue = std::strtol(input, &endPtr, 10);
				if (*endPtr != '\0' || parsedValue < INT_MIN || parsedValue > INT_MAX|| std::cin.peek() != '\n') {
					throw Exception("Invalid input. Please enter a valid integer value.");
				}
				else {
					if (parsedValue < 0) {
						throw Exception("Input value must be greater than 0.");
					}
					choice = parsedValue;
					flag = false;
				}
				std::cin.ignore(INT_MAX, '\n');  
			}
			catch (Exception& ex) {
				std::cout << "Exception: " << ex.ShowException() << "\nEnter a new choice\n";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');  
			}
		}
	}
	
