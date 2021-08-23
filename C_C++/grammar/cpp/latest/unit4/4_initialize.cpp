//
// Created by zxilly on 2021/8/20.
//

#include <iostream>

int main() {
    int a[3] = {0}; // 0 0 0 0具有特权，和 memset 同效果
    int a2[3] = {}; // 0 0 0 等效
    int b[3] = {1}; // 1 0 0
    return 0;
}