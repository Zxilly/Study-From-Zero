//
// Created by zxilly on 2021/11/7.
//

#include <iostream>

using namespace std;

int map[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> map[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += map[i] > map[i - 1] ? map[i] - map[i - 1] : 0;
    }
    cout << ans;
}