//
// Created by zxilly on 2021/8/27.
//

#include <iostream>

class Base {
public:
    virtual void test() { // 非 virtual 函数将使用静态联编/绑定 binding
        std::cout << "Base Test" << std::endl;
    };

    virtual ~Base() {
        std::cout << "Delete Base" << std::endl;
    }

    virtual void out() const = 0; // pure virtual function

    virtual Base &self() {
        return *this;
    }
    // friend 不能为 virtual
};

class Extend : public Base {
public:
    void test() override {
        std::cout << "Extend Test" << std::endl;
    }

    Extend &self() override {
        return *this; // 返回类型协变
    }

    ~Extend() override {
        std::cout << "Delete Extend" << std::endl;
    }
};

int main() {
    //Extend a;
    //a.test();
    Base *array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i % 2 ? new Base : new Extend;
    }
    for (Base *pt: array) {
        pt->test();
    }
    for (auto &i: array) {
        delete i;
    }
}