//
// Created by zxilly on 2022/9/8.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }
    auto b = max_element(balls.begin(), balls.end());
    auto ans = distance(balls.begin(), b);
    cout << ans + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}