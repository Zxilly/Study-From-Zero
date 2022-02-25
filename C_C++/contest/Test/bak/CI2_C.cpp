//
// Created by zxilly on 2021/12/26.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> mp;

const int maxn = 1e4 + 5;

int main() {
    int l, n, m;
    cin >> l >> n >> m;
    int pre;
    cin >> pre;
    for (int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;
        mp.emplace(cur - pre);
        pre = cur;
    }
    while (m--) {
        int biggest = mp.top();
        mp.pop();
        if (biggest % 2 == 0) {
            mp.emplace(biggest / 2);
            mp.emplace(biggest / 2);
        } else {
            mp.emplace(biggest / 2);
            mp.emplace(biggest / 2 + 1);
        }
    }
    cout << mp.top() << endl;
    return 0;
}