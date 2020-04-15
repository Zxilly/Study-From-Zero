#include <bits/stdc++.h>

using namespace std;

void case_func()
{
    int n;
    int array[200];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        array[n]=tmp%2;
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        case_func();
    }
}