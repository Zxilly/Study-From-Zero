//
// Created by zxilly on 2021/10/18.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    n += 1;
    // n = n+1
    // n/2
    // n
    // 1 0
    if (n == 1) {
        cout << 0 << endl;
    } else if (n % 2 == 1) {
        cout << n << endl;
    } else {
        cout << n / 2 << endl;
    }
    return 0;
}

/*
 * OI Olympic Information
 * ACM ICPC
 */