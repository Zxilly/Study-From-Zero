//
// Created by zxilly on 2021/8/25.
//

#include <iostream>

using namespace std;

enum T1 {
    A, B, C, D, E
};

//enum T2 {
//    A
//}; 枚举量冲突

enum class T3 {
    A, B, C, D, E
}; // C11 默认底层实现为 int

enum class T4 : short {
    A, B, C, D, E
};

enum struct T5 {
    A, B, C, D, E
};

int main() {
    T1 a = A;
    T3 b = T3::A;// 无法隐式转换为 int， 但是可以显式强制转换
}