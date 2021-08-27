//
// Created by zxilly on 2021/8/27.
//

#include <iostream>

class Test {
private:
    int a = 20;
    double e = 50; // C++ 11 的类内初始化语法，不适用于 static 值
    int b;
    int c;
    int d;
public:
    void out() const {
        std::cout << a << b << c << d << std::endl;
    }

    Test() {
        this->a = 10;
        this->b = 20;
        this->c = 30;
        this->d = 40;
    }
};

int main() {
    Test a;
    a.out();
}