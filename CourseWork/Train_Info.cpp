#include "Train_Info.h"
#include "Time.h"
Train_Info::Train_Info(int h = 0, int m = 0, int s = 0, int p = 0,const char* dest = "", const char* dept = "") : Time(h, m, s) {
    Platform = p;
    strcpy(Destination, dest);
    strcpy(Departure, dept);
}

Train_Info::Train_Info(const Train_Info& t) : Time(t)
{
    Platform = t.Platform;
    strcpy(Destination, t.Destination);
    strcpy(Departure, t.Departure);
}

Train_Info::~Train_Info()
{
}

void Train_Info::SetPlatform(int p)
{
    Platform = p;
}

void Train_Info::SetDestination(const char* dest)
{
    strcpy(Destination, dest);
}

int Train_Info::GetPlatform()
{
    return Platform;
}

char* Train_Info::GetDestination()
{
    return Destination;
}

void Train_Info::SetDeparture(const char* depar)
{
    strcpy(Departure, depar);
}


char* Train_Info::GetDeparture()
{
   return Departure;
}


