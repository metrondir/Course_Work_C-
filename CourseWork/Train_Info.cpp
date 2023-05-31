#include "Train_Info.h"
#include "Time.h"
#pragma warning(disable : 4996)

Train_Info::Train_Info(char* d, int p , int h , int m,int s) : Time(h, m, s) {
    SetDestination(d);
    SetPlatform(p);
}

Train_Info::Train_Info(const Train_Info& train)
{
    destination = new char[strlen(train.destination) + 1];
    strcpy(destination, train.destination);
    hours = train.hours;
    minutes = train.minutes;
    seconds = train.seconds;
    platform = train.platform;  
}

Train_Info::Train_Info()
{
    SetDestination("Unknown");
    SetPlatform(1);
}

Train_Info::~Train_Info()
{
    delete[] destination;
}

void Train_Info::SetPlatform(int p)
{
    if (p <= 0) {
        throw Exception("Invalid platform value");
    }
    platform = p;
}

void Train_Info::SetDestination(const char* d)
{
    destination = new char[strlen(d) +1];
    strcpy(destination, d);
}

int Train_Info::GetPlatform()
{
    return platform;
}

char* Train_Info::GetDestination()
{
    return destination;
}

char* Train_Info::GetTime()
{
    std::cout << "Destination: " << GetDestination() << " Platform: " << GetPlatform() << " Time:" << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << std::endl;
    return nullptr;  
}

std::istream& operator>>(std::istream& in, Train_Info& tr)
{
    bool flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter destination: \n";
        in >> input;
        try {
            bool hasNumericCharacters = false;
            for (int i = 0; input[i] != '\0'; i++) {
                if (isdigit(input[i])) {
                    hasNumericCharacters = true;
                    break;
                }
            }
            if (!hasNumericCharacters) {
                tr.SetDestination(input);
                flag = false;
            }
            else {
                throw Exception("Invalid input. Destination cannot contain numeric characters.");
            }

            in.ignore(INT_MAX, '\n');
        }
        catch (Exception& ex) {
            std::cerr << "Exception: " << ex.ShowException() << std::endl;
            in.clear();
            in.ignore(INT_MAX, '\n');
        }
    }

    flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter platform: \n";
        in >> input;
        try {
            char* endPtr;
            long parsedValue = std::strtol(input, &endPtr, 10);
         
            if (*endPtr != '\0' || parsedValue < INT_MIN || parsedValue > INT_MAX || in.peek() != '\n') {
                throw Exception("Invalid input. Please enter a valid integer value.");
            }
            else {
                tr.SetPlatform(parsedValue);
                flag = false;
            }
            in.ignore(INT_MAX, '\n');  
        }
        catch (Exception ex) {
            std::cerr << "Exception: " << ex.ShowException() << std::endl;
            in.clear();
            in.ignore(INT_MAX, '\n');  
        }
    }

    flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter hours: \n";
        in >> input;
        try {
            char* endPtr;
            long parsedValue = std::strtol(input, &endPtr, 10);


            if (*endPtr != '\0' || parsedValue < INT_MIN || parsedValue > INT_MAX || in.peek() != '\n') {
                throw Exception("Invalid input. Please enter a valid integer value.");
            }
            else {
                tr.SetHours(parsedValue);
                flag = false;
            }
            in.ignore(INT_MAX, '\n');  
        }
        catch (Exception ex) {
            std::cerr << "Exception: " << ex.ShowException() << std::endl;
            in.clear();
            in.ignore(INT_MAX, '\n');  
        }
    }

    flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter minutes: \n";
        in >> input;
        try {
            char* endPtr;
            long parsedValue = std::strtol(input, &endPtr, 10);
           
            if (*endPtr != '\0' || parsedValue < INT_MIN || parsedValue > INT_MAX || in.peek() != '\n') {
                throw Exception("Invalid input. Please enter a valid integer value.");
            }
            else {
                tr.SetMinutes(parsedValue);
                flag = false;
            }
            in.ignore(INT_MAX, '\n');  
        }
        catch (Exception ex) {
            std::cerr << "Exception: " << ex.ShowException() << std::endl;
            in.clear();
            in.ignore(INT_MAX, '\n');  
        }
    }
    flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter seconds: \n";
        in >> input;
        try {
            char* endPtr;
            long parsedValue = std::strtol(input, &endPtr, 10);
            
            if (*endPtr != '\0' || parsedValue < INT_MIN || parsedValue > INT_MAX || in.peek() != '\n') {
                throw Exception("Invalid input. Please enter a valid integer value.");
            }
            else {
                tr.SetSeconds(parsedValue);
                flag = false;
            }
            in.ignore(INT_MAX, '\n'); 
        }
        catch (Exception ex) {
            std::cerr << "Exception: " << ex.ShowException() << std::endl;
            in.clear();
            in.ignore(INT_MAX, '\n');  
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Train_Info& tr)
{
    try {
        if (strcmp(tr.destination, "Unknown") ==0) {
            throw Exception("Empty Train");
        }
        else
        {
            out << "====================================" << std::endl;
            out << "Destination :" << tr.destination << "\nPlatform: " << tr.platform << "\nHour: " << tr.hours << "\nMinute: " << tr.minutes << "\nSecond: " << tr.seconds << std::endl;
        }
    }
    catch (Exception ex) {
        std::cout << "Exception: " << ex.ShowException() << "\n";
    }
    return out;
}

