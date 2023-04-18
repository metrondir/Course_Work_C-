#include "Time.h"
#include <iostream>
#pragma warning (disable : 4996)

Time::Time(int h, int m, int s)
{
	SetHours(h);
	SetMinutes(m);
	SetSeconds(s);
}
void Time::SetHours(int h)
{
	if (h < 0 && h > 23) {
		throw Exception("");
	}
		Hours = h;
}

void Time::SetMinutes(int m)
{
	if (m < 0 && m > 59) {
		throw Exception("");
	}
		Minutes = m;
}

void Time::SetSeconds(int s)
{
	if (s < 0 && s > 59) {
		throw Exception("");
	}
		Seconds = s;
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
	int total_seconds = Hours * 3600 + Minutes * 60 + Seconds + t.Hours * 3600 + t.Minutes * 60 + t.Seconds;
	Hours = total_seconds / 3600;
	Minutes = (total_seconds % 3600) / 60;
	Seconds = total_seconds % 60;
	return *this;
}

Time& Time::operator-=(const Time& t)
{
	int total_seconds = Hours * 3600 + Minutes * 60 + Seconds - t.Hours * 3600 - t.Minutes * 60 - t.Seconds;
	if (total_seconds < 0) {
		total_seconds += 24 * 3600;
	}
	Hours = total_seconds / 3600;
	Minutes = (total_seconds % 3600) / 60;
	Seconds = total_seconds % 60;
	return *this;
}

Time& Time::operator=(const Time& t)
{
	if (this == &t)
		return *this;
	Hours = t.Hours;
	Minutes = t.Minutes;
	Seconds = t.Seconds;
	return *this;

}

std::istream& operator>>(std::istream& in, Time& t)
{		
		in.ignore();
		std::cout << "Enter a hour:\n";
		in >> t.Hours;
		std::cout << "Enter a minute: \n";
		in >> t.Minutes;
		std::cout << "Enter a second: \n";
		in >> t.Seconds;
		in.clear();
		return in;
}

std::ostream& operator<<(std::ostream& out, Time& t)
{
			out << "Hour: " << t.Hours << "\nMinute: " << t.Minutes << "\nSecond: " << t.Seconds << std::endl;
			return out;
}