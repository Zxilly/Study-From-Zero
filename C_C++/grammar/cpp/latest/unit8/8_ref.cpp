//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

using namespace std;

void swapr(int &a, int &b) {
    int c = b;
    b = a;
    a = c;
}

struct per {
    int a;
    int b;
};

void set_perp(per &a){
    a.a = 20;
}

int main() {
    int a = 1, b = 2;
    swapr(a, b);
    cout << a << ' ' << b << endl;

    per aa = {1, 2};
    set_perp(aa);
}