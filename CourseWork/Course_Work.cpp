#include "Schedule.h"
#include "Time.h"

void ChoiceChecker(unsigned int& choice);

int main()
{
	std::cout << "---------------------------------------------------\n";
	std::cout << "|  Course work st. gr. KN-22 Medvedieva Romana    |\n";
	std::cout << "---------------------------------------------------\n";
	char destination[256];
	Schedule schedule;
	unsigned int choice;
	bool flag = true;
	while (flag)
	{
		std::cout << "Enter how many trains will be:\n";
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
	flag = true;
	while (flag) {
		std::cout << "+--------------------------------------------+\n";
		std::cout << "|   Choose what you would like to proceed:   |\n+--------------------------------------------+\n| 0. Exit\t\t\t             |\n| 1. Show schedule\t\t\t     |\n| 2. Find the earliest train in schedule     |\n| 3. Polymorphic time cluster \t\t     |\n| 4. Polymorphic train cluster \t\t     |\n";
		std::cout << "+--------------------------------------------+\n";
		while (true) {
			try {
				ChoiceChecker(choice);
				break;
			}
			catch (Exception ex)
			{
				std::cout << ex.ShowException();
				std::cin.clear();
			}
		}
		flag = true;
		switch (choice)
		{
		case 0: {
			exit(1);
		}
		case 1: {
			try
			{
				schedule.Show();
			}
			catch (Exception ex)
			{
				std::cout << ex.ShowException();
			}
			break;
		}
		case 2: {
			try {
				std::cout << "Enter Destination: " << std::endl;
				std::cin >> destination;
				schedule.FindNearestTrain(destination);
			}
			catch (Exception e) {
				std::cerr << "Exception: " << e.ShowException() << std::endl;
			}
			break;
		}
		case 3: {
			Time time1;
			std::cin >> time1;
			Time* time = &time1;
			time->GetTime();
			break;
		}
		case 4:
		{
			Train_Info train1;
			std::cin >> train1;
			Time* train = &train1;
			train->GetTime();
			break;
		}
		default: {
			std::cout << "Bad enter choice\n";
			break;
		}
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
	
