//
// Created by 12009 on 2021/1/26.
//
#include <stdio.h>
#include <malloc.h>


int main() {
    long long sum = 0;
    while (malloc(1024*1024))
    {
        sum += 1024*1024;
        printf("sum=%lf\n", (double)sum/1024/1024);
    }

}