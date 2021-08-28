//
// Created by zxilly on 2021/8/28.
//

#include <iostream>

template<class T1, class T2>
class Test {
public:
    void test() {
        std::cout << "All free" << std::endl;
    }
};

template<class T1>
class Test<T1, int> {
public:
    void test() {
        std::cout << "T2 not free" << std::endl;
    }
};

template<>
class Test<int, int> {
public:
    void test() {
        std::cout << "No free" << std::endl;

    }
};

int main() {
    Test<float, float> a;
    Test<float, int> b;
    Test<int, int> c;
    a.test();
    b.test();
    c.test();
}