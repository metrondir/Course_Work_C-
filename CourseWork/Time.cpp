#include "Time.h"
#include <iostream>
#pragma warning (disable : 4996)

Time::Time()
{
    Hours = 0;
    Minutes = 0;
    Seconds = 0;
}
Time::Time(int h, int m, int s)
{
    SetHours(h);
    SetMinutes(m);
    SetSeconds(s);
}
Time::Time(const Time& t)
{
    Hours = t.Hours;
    Minutes = t.Minutes;
    Seconds = t.Seconds;
}

void Time::SetHours(int h)
{
    if (h < 0 || h > 23) {
        throw Exception("Invalid hours value");
    }
    Hours = h;
}

void Time::SetMinutes(int m)
{
    if (m < 0 || m > 59) {
        throw Exception("Invalid minutes value");
    }
    Minutes = m;
}

void Time::SetSeconds(int s)
{
    if (s < 0 || s > 59) {
        throw Exception("Invalid seconds value");
    }
    Seconds = s;
}

char* Time::GetTime()
{
    std::cout << "Time:" << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << std::endl;
    return nullptr;
}

int Time::GetHours()
{
    return Hours;
}

int Time::GetMinutes()
{
    return Minutes;
}

int Time::GetSeconds()
{
    return Seconds;
}

Time& Time::operator+=(const Time& t)
{
    //24-hours
    int total_seconds = Hours * 3600 + Minutes * 60 + Seconds + t.Hours * 3600 + t.Minutes * 60 + t.Seconds;
    int new_hours = total_seconds / 3600;
    int remaining_seconds = total_seconds % 3600;
    int new_minutes = remaining_seconds / 60;
    int new_seconds = remaining_seconds % 60;
    Hours = new_hours % 24;
    Minutes = new_minutes;
    Seconds = new_seconds;
    return *this;
    //24+hours
   /* int total_seconds = Hours * 3600 + Minutes * 60 + Seconds + t.Hours * 3600 + t.Minutes * 60 + t.Seconds;
    Hours = total_seconds / 3600;
    Minutes = (total_seconds % 3600) / 60;
    Seconds = total_seconds % 60;
    return *this;*/
}

Time& Time::operator+=(int seconds)
{

    int total_seconds = Hours * 3600 + Minutes * 60 + Seconds;

    total_seconds += seconds;

    int new_hours = total_seconds / 3600;
    int remaining_seconds = total_seconds % 3600;
    int new_minutes = remaining_seconds / 60;
    int new_seconds = remaining_seconds % 60;

    Hours = new_hours % 24;
    Minutes = new_minutes;
    Seconds = new_seconds;
    return *this;
}


Time& Time::operator-=(const Time& t)
{
    int total_seconds = Hours * 3600 + Minutes * 60 + Seconds;

    int subtract_seconds = t.Hours * 3600 + t.Minutes * 60 + t.Seconds;

    total_seconds -= subtract_seconds;

    if (total_seconds < 0) {
        total_seconds += 24 * 3600;
    }

    int new_hours = total_seconds / 3600;
    int remaining_seconds = total_seconds % 3600;
    int new_minutes = remaining_seconds / 60;
    int new_seconds = remaining_seconds % 60;

    Hours = new_hours % 24;
    Minutes = new_minutes;
    Seconds = new_seconds;

    return *this;
}
Time& Time::operator-=(int seconds)
{
    int total_seconds = Hours * 3600 + Minutes * 60 + Seconds;

    total_seconds -= seconds;

    if (total_seconds < 0) {
        total_seconds += 24 * 3600;
    }

    int new_hours = total_seconds / 3600;
    int remaining_seconds = total_seconds % 3600;
    int new_minutes = remaining_seconds / 60;
    int new_seconds = remaining_seconds % 60;

    Hours = new_hours % 24;
    Minutes = new_minutes;
    Seconds = new_seconds;

    return *this;
}
Time& Time::operator=(const Time& t)
{
    if (this == &t)
        return *this;
    SetHours(t.Hours);
    SetMinutes(t.Minutes);
    SetSeconds(t.Seconds);
    return *this;
}

std::istream& operator>>(std::istream& in, Time& t)
{
    bool flag = true;
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
                t.SetHours(parsedValue);
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
                t.SetMinutes(parsedValue);
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
                t.SetSeconds(parsedValue);
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

std::ostream& operator<<(std::ostream& out, Time& t)
{
    out << "Hours: " << t.Hours << "\nMinutes: " << t.Minutes << "\nSeconds: " << t.Seconds << std::endl;
    return out;
}