//
// Created by zxilly on 2021/8/30.
//

#include <iostream>

class Test {
public:
    virtual void test() {
        std::cout << "Base0" << std::endl;
    }
};

class Test1 : public Test {
public:
    void test() override {
        std::cout << "Base1" << std::endl;
    }
};

class Test2 : public Test1 {
private:
    int aa = 20;
public:
    void test23() const {
        std::cout << "Base" << aa << std::endl;
    }
};

class Test3 {

};

int main() {
    Test2 a;
    Test *b = &a;
    b->test();
    if (auto *c = dynamic_cast<Test2 *>(b)) {
        c->test23();
        auto info = typeid(*c).name();
        std::cout << "Info " << info << std::endl;
    }
}