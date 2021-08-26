//
// Created by zxilly on 2021/8/25.
//

#include <iostream>

class number0 {
private:
    int value;
public:
    number0() {
        value = 0;
    }

    void set(int n) {
        this->value = n;
    }

    int get() const {
        return this->value;
    }

    number0 operator+(const number0 &number1) const;
};

number0 number0::operator+(const number0 &number1) const {
    number0 tmp;
    tmp.value = this->value + number1.value;
    return tmp;
}

int main() {
    number0 a;
    a.set(20);
    number0 b;
    b.set(30);
    number0 c = a + b;
    //    number0 d = a * b; Invalid operands to binary expression ('number' and 'number')
    std::cout << c.get() << std::endl;
}