//
// Created by zxilly on 2021/8/29.
//
#include <iostream>


class Testa {
public:
    class Testb {
    public:
        int a = 1;
    };

    int a = 1;
    Testb b;
};

int main() {
    using namespace std;
    Testa a;
    cout<<a.a<<endl;
    cout << a.b.a << endl;
};