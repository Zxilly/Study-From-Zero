//
// Created by 12009 on 2020/4/18.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c;
    int num = 0;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=1;i<=n;i++)
    {
        if(i%a!=0&&i%b!=0&&i%c!=0)
        {
            num++;
        }
    }
    printf("%d",num);
}