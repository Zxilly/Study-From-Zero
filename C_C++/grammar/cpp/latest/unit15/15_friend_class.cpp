//
// Created by zxilly on 2021/8/29.
//

#include <iostream>

class Test {
private:
    int aa = 50;
public:
    friend class TestFriend;
};

class TestFriend {
public:
    void test(Test &t) {
        std::cout << t.aa << std::endl;
    }
};

int main() {
    Test a;
    TestFriend b;
    b.test(a);
}