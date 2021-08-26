//
// Created by zxilly on 2021/8/25.
//

#include <iostream>

class number {
private:
    int value;
public:
    number() {
        value = 0;
    }

    explicit number(int n) {
        value = n;
    }

    void set(int n) {
        this->value = n;
    }

    int get() const {
        return this->value;
    }

    number operator+(int number1) const;

    friend number operator+(int m, const number &n);

    friend std::ostream &operator<<(std::ostream &os, const number &n);
};

number operator+(int m, const number &n) {
    return n + m;
} // 友元

number number::operator+(const int number1) const {
    number temp;
    temp.set(this->value + number1);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const number &n) {
    return os << "value is " << n.value;
}
// 成员

int main() {
    number a(20);
    number b = a + 20;
    number c = 20 + a;
    std::cout << c << std::endl;
}