#include "Train_Info.h"
#include "Time.h"
#pragma warning(disable : 4996)

Train_Info::Train_Info(char* d, int p , int h , int m,int s) : Time(h, m, s) {
    SetDestination("Unknown");
    Platform = p;
}

Train_Info::Train_Info(const Train_Info& train)
{
    Destination = new char[strlen(train.Destination) + 1];
    strcpy(Destination, train.Destination);
    Hours = train.Hours;
    Minutes = train.Minutes;
    Seconds = train.Seconds;
    Platform = train.Platform;  
}

Train_Info::Train_Info()
{
    SetDestination("Unknown");
    SetPlatform(1);
}

Train_Info::~Train_Info()
{
    delete[] Destination;
}

void Train_Info::SetPlatform(int p)
{
    if (p <= 0) {
        throw Exception("Invalid platform value\n");
    }
    Platform = p;
}

void Train_Info::SetDestination(const char* d)
{
    Destination = new char[strlen(d) +1];
    strcpy(Destination, d);
}

int Train_Info::GetPlatform()
{
    return Platform;
}

char* Train_Info::GetDestination()
{
    return Destination;
}

char* Train_Info::GetTime()
{
    if (strcmp(Destination, "Unknown") == -1) {
        std::cout << "Destination: " << GetDestination() << " Platform: " << GetPlatform() << " Time:" << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << std::endl;
    }
    return nullptr;  
}

std::istream& operator>>(std::istream& in, Train_Info& tr)
{
    bool flag = true;
    while (flag) {
        char input[256];
        std::cout << "Enter Destination: \n";
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
        std::cout << "Enter Platform: \n";
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
        std::cout << "Enter Hours: \n";
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
        std::cout << "Enter Minutes: \n";
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
        std::cout << "Enter Seconds: \n";
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
        if (strcmp(tr.Destination, "Unknown") ==0) {
            throw Exception("Empty Train");
        }
        else
        {
            out << "====================================" << std::endl;
            out << "Destination :" << tr.Destination << "\nPlatform: " << tr.Platform << "\nHour: " << tr.Hours << "\nMinute: " << tr.Minutes << "\nSecond: " << tr.Seconds << std::endl;
        }
    }
    catch (Exception ex) {
        std::cout << "Exception: " << ex.ShowException() << "\n";
    }
    return out;
}

