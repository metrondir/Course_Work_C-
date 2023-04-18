#pragma once
#include<iostream>
class Exception : public std::exception
{
	char* Info;
public:
	Exception(const char* m);
	~Exception();

	char* ShowException();
};

