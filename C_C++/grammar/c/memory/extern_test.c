//
// Created by zxilly on 2021/4/7.
//

#include <stdio.h>

int x=20;
int y=10;

int main(){
    extern int x; //extern 不会改变值
    int y;
    printf("%d %d",x,y);
}