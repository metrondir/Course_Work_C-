#include "Iterator.h"
#include "Exception.h"
#include "Schedule.h"
Iterator::Iterator(Train_Info* p) :Buffer(p) {
}

Iterator::~Iterator() {

}
Train_Info& Iterator::operator++(int)
{
	return *Buffer++;
}

Train_Info& Iterator::operator+=(int value)
{
	return *(Buffer += value);
}
Train_Info Iterator::operator*()
{
	return *Buffer;
}
bool Iterator::operator!=(const Iterator& value)
{
	return Buffer != value.Buffer;
}

bool Iterator::operator>=(const Iterator& value)
{
	return Buffer >= value.Buffer;
}

bool Iterator::operator<=(const Iterator& value)
{
	return Buffer<=value.Buffer;
}

