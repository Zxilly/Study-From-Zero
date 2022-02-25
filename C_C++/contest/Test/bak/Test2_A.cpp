//
// Created by zxilly on 2021/11/7.
//

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int in[3];
    cin >> in[0] >> in[1] >> in[2];
    sort(in, in + 3);
    int j = gcd(in[0], in[2]);
    cout << in[0] / j << "/" << in[2] / j;
    return 0;
}