#include <cstdio>

int numberOfSteps (int num)
{
    int count=0;
    while(1)
    {
    if(num==0)
    {
        break;
    }
    else if(num%2)
    {
        num--;
        count++;
    }
    else
    {
        num/=2;
        count++;
    }
    }
    return count;
}

int main()
{

}