//
// Created by zxilly on 2021/8/28.
//

#include <iostream>
#include <valarray>

class Test : private std::string, private std::valarray<double> {
public:
    Test(std::string str, const valarray<double> &dbarray);


    void test();

    int a;
};

Test::Test(std::string str, const std::valarray<double> &dbarray) : std::string(std::move(str)),
                                                                    std::valarray<double>(dbarray), a(20) {}

void Test::test() {
    std::cout << (const std::string &) *this << std::endl;
}

int main() {
    double tmp[]{2, 3, 4, 5};
    Test a(std::string("A Long Str"), std::valarray<double>(tmp, 10));
    a.test();
}

