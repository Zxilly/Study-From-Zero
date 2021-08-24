//
// Created by zxilly on 2021/8/24.
//

#include <iostream>

class Stock {
private:
    std::string company;
    long share;

    void set() {
        this->share = 200; // 自动成为内联函数
    }

public:
    Stock(long n);

    Stock(const std::string &test, long n);

    ~Stock();

    void buy(long num, double price) const; // 可用于const对象

    void show();
};

inline void Stock::show() {
    int a = 1;
    std::string b = company;
}

Stock::Stock(const std::string &test, long n) {
    company = test;
    share = n;
}

void Stock::buy(long num, double price) const {

}

Stock::~Stock() {
    std::cout << "Bye Bye";
}

Stock::Stock(long n) {
    company = "test";
    share = n;
}

int main() {
    Stock apple("Something", 20);
    Stock apple2 = Stock("Something", 20);
    Stock apple3{"Something", 20};
    Stock apple4 = 30; // 单值构造函数特性
}