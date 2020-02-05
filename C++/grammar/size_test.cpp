//
// Created by 12009 on 2020/2/5.
//
#include <bits/stdc++.h>

#define STRING "123456789"

char str[100];

int main()
{
    scanf("%s",str);
    printf("%d %d\n", sizeof(str),strlen(str));
    printf("%d %d",sizeof(STRING),strlen(STRING));
    return 0;
}