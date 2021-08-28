//
// Created by zxilly on 2021/8/26.
//

#include <iostream>

class Test {
private:
    int value;
public:
    explicit Test(int a) {
        value = a;
    }

    Test(const Test &t) {
        std::cout << "Use Copy Constructor." << std::endl;
        value = t.value;
    }

    Test &operator=(const Test &t) {
        if (this == &t) {
            return *this;
        } else {
            std::cout << "Not Self" << std::endl;
            this->value = t.value;
            return *this;
        }
    }
};

int main() {
    using namespace std;
    Test a = (Test) 2;
    Test b = a;
}