//
// Created by 12009 on 2021/1/26.
//
#include <stdio.h>
#include <malloc.h>
#include <time.h>


int main() {
    time_t tmp = time(NULL);
    struct tm *tmptime = localtime(&tmp);
    printf("%d",tmptime->tm_wday);
}