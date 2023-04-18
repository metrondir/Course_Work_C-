#include "Iterator.h"
#include "Exception.h"
Iterator::Iterator(Train_Info* p, size_t Count) :Buffer(p),Count(Count) {
	Position = 0;
}
Iterator::~Iterator() {

}
Train_Info* Iterator::operator++()
{
	if (Buffer == NULL || Count <= 0)
		throw Exception("");
	if (Position > Count)
		throw Exception("");
	Position++;
	Train_Info* pData = Buffer + Position;
	return pData;
}
Train_Info* Iterator::operator->()
{
	Train_Info* pData = Buffer + Position;
	return pData;
}
Train_Info* Iterator::operator=(Train_Info* value)
{
	return Buffer = value;
}
Train_Info Iterator::operator*()
{
	return*(Buffer + Position);
}
bool Iterator::operator!=(Train_Info* value)
{
	bool pr;
	if ((Buffer + Position) != value)
		pr = true;
	pr = false;
	return pr;
}