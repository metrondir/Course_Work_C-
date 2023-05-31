#include "Iterator.h"
#include "Exception.h"
#include "Schedule.h"
Iterator::Iterator(Train_Info* p) :buffer(p) {
}

Iterator::~Iterator() {

}
Train_Info& Iterator::operator++(int)
{
	return *buffer++;
}

Train_Info& Iterator::operator+=(int value)
{
	return *(buffer += value);
}
Train_Info Iterator::operator*()
{
	return *buffer;
}
bool Iterator::operator!=(const Iterator& value)
{
	return buffer != value.buffer;
}

bool Iterator::operator>=(const Iterator& value)
{
	return buffer >= value.buffer;
}

bool Iterator::operator<=(const Iterator& value)
{
	return buffer<=value.buffer;
}

