//
// Created by zxilly on 2021/4/7.
//

#include <stdio.h>

int main() {
    int a[20];
    int *restrict b = a; //b是操作a数组的唯一方式
}