//
// Created by zxilly on 2021/8/21.
//

#include <iostream>

using namespace std;

int main() {
    struct __attribute__((unused)) inflatable {
        int a;
        double b;
        bool c;
    };

    struct inflatable a = {
            2,
            2.0,
            true
    };
    inflatable b{
            3,
            3.0,
            false
    }; // C++ 中可以省略 struct

    struct {
        int x;
        int y;
    } postion = {
            2,
            4
    }; // 匿名结构

    struct bit_struct {
        unsigned int SN: 4;
        unsigned int : 4;
        bool goodIn: 1;
        bool goodOut: 1;
    }; // 我也不知道干啥的
}