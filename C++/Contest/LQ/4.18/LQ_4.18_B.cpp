//
// Created by 12009 on 2020/4/18.
//
#include <bits/stdc++.h>

using namespace std;

char encrypt(char str[300])
{
    int strlength;
    strlength = int(strlen(str));
    //printf("%d",strlength);
    for(int i=0;i<strlength;i++)
    {
        str[i]+=3;
        if(str[i]>122)
        {
            str[i]-=26;
        }
        printf("%c",str[i]);
    }
    return 0;
}

int main()
{
    char input[300];
    scanf("%s",&input);
    encrypt(input);
    return 0;
}
