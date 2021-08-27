//
// Created by zxilly on 2021/8/26.
//

#include <iostream>

class Test {
private:
    char *p;
public:
    Test() {
        this->p = new char[200]();
    }

    ~Test() {
        delete[] this->p;
    }

    char &operator[](int c) {
        return *(this->p + c);
    }

    const char &operator[](int c) const {
        return *(this->p + c);
    }

    friend std::ostream &operator<<(std::ostream &os, const Test &t);
};

std::ostream &operator<<(std::ostream &os, const Test &t) {
    return os << t.p;
}

int main() {
    Test p;
    for (int i = 0; i < 10; ++i) {
        p[i] = 'a';
    }
    p[10] = '\0';
    std::cout << p;
    return 0;
}