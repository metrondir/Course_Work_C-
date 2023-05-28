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
		Time();
		Time(int h, int m, int s);
		Time(const Time &t);
		virtual ~Time() {};

		void SetHours(int h);
		void SetMinutes(int m);
		void SetSeconds(int s);

		 virtual char* GetTime() ;
		 int GetHours();
		 int GetMinutes();
		 int GetSeconds();

		Time& operator+=(const Time& t);
		Time& operator+=(int seconds);
		Time& operator-=(const Time& t);
		Time& operator-=(int seconds);
		Time& operator=(const Time& t);
		friend std::istream& operator>>(std::istream& in, Time& t);

		friend std::ostream& operator<<(std::ostream& out, Time& t);
		
};

