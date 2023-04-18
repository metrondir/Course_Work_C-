#include "Time.h"
#include <iostream>
#pragma warning (disable : 4996)

Time::Time(Time&)
{
	SetHours(0);
	SetMinutes(0);
	SetSeconds(0);
}
Time::Time( int h,  int m,  int s) {
	SetHours(h);
	SetMinutes(m);
	SetSeconds(s);
}
Time::Time(const Time& t )
{
	Hours = t.Hours;
	Minutes = t.Minutes;
	Seconds = t.Seconds;
}
Time::~Time()
{
}

void Time::SetHours(int h)
{
	if (h >= 0 && h <= 23) {
		Hours = h;
	}
	else {
		std::cerr << "Error: Invalid hour value" << std::endl;
	}
}

void Time::SetMinutes(int m)
{
	if (m >= 0 && m <= 59) {
		Minutes = m;
	}
	else {
		std::cerr << "Error: Invalid minute value" << std::endl;
	}

}

void Time::SetSeconds(int s)
{
	if (s >= 0 && s <= 59) {
		Seconds = s;
	}
	else {
		std::cerr << "Error: Invalid second value" << std::endl;
	}
	
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
	Seconds += t.Seconds;
	Minutes += t.Minutes + (Seconds / 60);
	Hours += t.Hours + (Minutes / 60);
	Seconds %= 60;
	Minutes %= 60;
	Hours %= 24;
	return *this;
}

Time& Time::operator-=(const Time& t)
{
	Seconds -= t.Seconds;
	if (Seconds < 0) {
		Seconds += 60;
		Minutes--;
	}
	Minutes -= t.Minutes;
	if (Minutes < 0) {
		Minutes += 60;
		Hours--;
	}
	Hours -= t.Hours;
	if (Hours < 0) {
		Hours += 24;
	}
}

Time& Time::operator=(const Time& t)
{
	Hours = t.Hours;
	Minutes = t.Minutes;
	Seconds = t.Seconds;
	return *this;

}



 std::ostream& operator<<(std::ostream &out,  Time& t)
{
	out << t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds();
	return out;

}
 std::istream& operator>>(std::istream& in, Time& t)
 {
	 in >> t.GetHours() >> t.Minutes >> t.Seconds;// повернутись до того
	 return in;
 }
