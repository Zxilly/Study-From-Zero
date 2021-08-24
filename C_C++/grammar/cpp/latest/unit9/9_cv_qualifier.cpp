//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

struct cc{
    int a;
    mutable int b; // 即使结构体为 const， 此成员依然可修改
};

int main() {
    const int a = 1; // 不可变
    volatile int b = 1; // 可能与硬件关联，禁止缓存优化
}

// const 会使全局变量作用域变为 static