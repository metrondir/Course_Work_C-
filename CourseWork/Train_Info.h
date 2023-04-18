#pragma once
#include "Time.h"
#include<iostream>
class Train_Info : public Time {
	int Platform;
	char* Destination;
	char* Departure;
public:
	Train_Info(int h = 0, int m = 0, int s = 0, int p = 0, const char* dest = "", const char* dept = "");
	Train_Info(const Train_Info& t);
	~Train_Info();

	void SetDeparture(const char* depar);
	void SetPlatform(int platform);
	void SetDestination(const char* dest);
	

	char* GetDeparture();
	int GetPlatform();
	char* GetDestination();
	

	friend std::istream& operator>>(std::istream& in, Train_Info& t);
	friend std::ostream& operator<<(std::ostream& out, const Train_Info& t);




};