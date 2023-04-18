#include "Train_Info.h"
#include "Time.h"
Train_Info::Train_Info():Destination(NULL),Platform(0)
{

}
Train_Info::Train_Info(char* d, int p , int h , int m,int s) : Time(h, m, s) {
    Destination = new char[strlen(Destination)];
    strcpy(Destination, d);
    Platform = p;
}

Train_Info::Train_Info(const Train_Info& t) {
    Destination = new char[strlen(t.Destination) ];
    Platform = t.Platform;
}

Train_Info::~Train_Info()
{
    delete[]Destination;
}

void Train_Info::SetPlatform(int p)
{
    Platform = p;
}

void Train_Info::SetDestination(const char* d)
{
    Destination = new char[strlen(d) ];
    strcpy(Destination, d);
}

int Train_Info::GetPlatform()
{
    return Platform;
}

char* Train_Info::GetDestination()
{
    return Destination;
}

std::istream& operator>>(std::istream& in, Train_Info& tr)
{
    in.ignore();
    std::cout << ":\n";
    in.getline(tr.Destination,256);
    std::cout << " :\n";
    in >> tr.Platform;
    std::cout << " :\n";
    in >> tr.Hours;
    std::cout << " :\n";
    in >> tr.Minutes;
    std::cout << " :\n";
    in >> tr.Seconds;
    std::cout << " :\n";
    return in;
}

std::ostream& operator<<(std::ostream& out, const Train_Info& tr)
{
    out << "Destination :" << tr.Destination << "\nPlatform: " << tr.Platform << "\nHour: " << tr.Hours << "\nMinute: " << tr.Minutes << "\nSecond: " << tr.Seconds << std::endl;
    return out;
}
