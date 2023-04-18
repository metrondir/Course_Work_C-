#include "Exception.h"
#include <iostream>
#pragma warning(disable : 4996)

Exception::Exception(const char* m) {
	Info = new char[255];
	strcpy(Info, m);
}
Exception::~Exception() {

}
char* Exception::ShowException() {
	return Info;
}