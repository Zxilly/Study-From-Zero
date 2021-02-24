//
// Created by 12009 on 2021/2/24.
//

#include <stdio.h>
#include <string.h>

int main(){
    char ta[200]="thisisasentence.";
    char tb[200]="thisisanothersentence.";

    strcat(ta,tb);
    puts(ta);
    strncat(ta,tb,3);
    puts(ta);

    char tc[200];

    strcpy(tc,ta);
    puts(tc);

    memset(tc,0,sizeof tc);

    strncpy(tc,ta,5);
    puts(tc);


}