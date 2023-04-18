#pragma once
#include <iostream>
#include "Exception.h"
class Time
{
protected:
	int Hours;
	int Minutes;
	int Seconds;
	public:
		Time() : Hours(0), Minutes(0), Seconds(0) {};
		Time(int h, int m, int s);
		Time(const Time& t) : Hours(t.Hours), Minutes(t.Minutes), Seconds(t.Seconds) {};
		~Time() {};

		void SetHours(int h);
		void SetMinutes(int m);
		void SetSeconds(int s);

		 int GetHours();
		 int GetMinutes();
		 int GetSeconds();

		Time& operator+=(const Time& t);
		Time& operator-=(const Time& t);
		Time& operator=(const Time& t);

		friend std::istream& operator>>(std::istream& in, Time& t);

		friend std::ostream& operator<<(std::ostream& out, Time& t);
		
};

