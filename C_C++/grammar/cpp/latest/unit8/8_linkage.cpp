//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

int global = 1000; // static duration, external linkage
static int one_file = 1000; // static duration, internal linkage

void count() {
    static int count; // static duration, no linkage
    count += 1;
    std::cout << count << std::endl;
}

int main() {
    for (int i = 0; i < 100; i++) {
        count();
    }
}