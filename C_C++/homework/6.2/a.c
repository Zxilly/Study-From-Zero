#include <stdio.h>
#include <string.h>

#define maxn 5001

_Bool number[maxn + 5];
int prime[maxn + 5];

void getprime()
{
    int i, j, c = 0;
    memset(number, 1, sizeof(number));
    for (i = 2; i <= maxn; i++)
    {
        if (number[i])
            prime[c++] = i;
        for (j = 0; j < c && prime[j] * i <= maxn; j++)
        {
            number[prime[j] * i] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    getprime();
    for(int i=0;i<maxn;i++)
    {
        if(prime[i]>=100)
        {
            if(prime[i]>=5000)
            {
                break;
            }
            printf("%d ",prime[i]);
        }
    }
    return 0;
}