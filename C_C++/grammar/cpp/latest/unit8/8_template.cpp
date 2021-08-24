//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

// TODO: 理解三种具体化，C++PP 8.5.5

template<typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<>
void swap<float>(float &a, float &b) {
    std::cout << "Use specialization." << std::endl;
    float temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x + y) {
    return x + y;
}

int main() {
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << std::endl;

    float c = 1.1, d = 2.2;
    swap(c, d);
}