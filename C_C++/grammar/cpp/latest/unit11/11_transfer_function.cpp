//
// Created by zxilly on 2021/8/26.
//

#include <iostream>

class Test {
private:
    int value;
public:
    Test() {
        (*this).value = 20;
    }

    explicit operator double() const {
        return (double) value;
    }
};

int main() {

}