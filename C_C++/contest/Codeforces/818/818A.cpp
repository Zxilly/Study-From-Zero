//
// Created by zxilly on 2022/9/2.
//
#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int twos = num / 2;
        int threes = num / 3;
        int result = num + twos * 2 + threes * 2;

        cout << result << endl;
    }
}