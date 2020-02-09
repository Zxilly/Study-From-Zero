#include <cstdio>

double angleClock(int hour, int minutes)
{
    if(hour==12)
    {
        hour=0;
    }
    double output=0;
    double opangle=(hour*30)+(minutes*0.5)-(minutes*6);
    if(opangle<0)
    {
        opangle=-opangle;
    }
    if(opangle>180)
    {
        opangle=360-opangle;
    }
    return opangle;
}


int main()
{

}