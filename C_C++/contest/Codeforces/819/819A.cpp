//
// Created by zxilly on 2022/9/6.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int maxa = -1, mina = 10000;
    cin >> n;
    vector<int> nums;
    if (n == 1) {
        int a;
        cin >> a;
        cout << 0 << endl;
        return;
    }
    while (n--) {
        int a;
        cin >> a;
        if (a > maxa) {
            maxa = a;
        }
        if (a < mina) {
            mina = a;
        }
        nums.emplace_back(a);
    }
    int currentStart = nums.front();
    int currentEnd = nums.back();
    int ans = 0;

    int option1 = currentEnd - mina;
    int option2 = maxa - currentStart;
    ans = max(option1, option2);
    for (int i = 0; i < nums.size(); ++i) {
        int pre = nums[i];
        int post = nums[(i + 1) % nums.size()];
        int option3 = pre - post;
        ans = max(ans, option3);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}