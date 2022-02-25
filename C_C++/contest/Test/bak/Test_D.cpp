//
// Created by zxilly on 2021/11/6.
//

#include <iostream>

using namespace std;

long long store[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        store[i] = store[i - 1] + value;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << store[r] - store[l - 1] << endl;
    }
    return 0;
}