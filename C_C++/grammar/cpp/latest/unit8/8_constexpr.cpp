//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

constexpr int func() {
    return 10;
}

int main() {
    int arr[func()];
}