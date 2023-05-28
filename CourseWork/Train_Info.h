#pragma once
#include "Time.h"
#include "Exception.h"
#include<iostream>

class Train_Info : public Time {
protected:
	char* Destination;
	int Platform;

public:
	Train_Info();
	Train_Info(char* d, int p, int h, int m, int s);
	Train_Info(const Train_Info& train);
	virtual ~Train_Info();

	void SetPlatform(int p);
	void SetDestination(const char* d);

	int GetPlatform();
	char* GetDestination();
	char* GetTime() override;
	friend std::istream& operator>>(std::istream& in, Train_Info& tr);
	friend std::ostream& operator<<(std::ostream& out, const Train_Info& tr);
};