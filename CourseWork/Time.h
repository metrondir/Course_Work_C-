#pragma once
class Time
{
protected:
	int Hours;
	int Minutes;
	int Seconds;
	public:
		
		Time(Time&);
		Time(const Time& t);
		Time(int h,  int m,  int s);
		~Time();

		void SetHours(int h);
		void SetMinutes(int m);
		void SetSeconds(int s);

		 int GetHours();
		 int GetMinutes();
		 int GetSeconds();

		Time& operator+=(const Time& t);
		Time& operator-=(const Time& t);
		Time& operator=(const Time& t);

		friend std::istream& operator>>(std::istream &in, Time& t);
		friend std::ostream& operator<<(std::ostream &out, Time& t);
};

