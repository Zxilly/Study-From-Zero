//
// Created by zxilly on 2022/9/4.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> as;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        as.emplace_back(a);
    }
    sort(as.begin(), as.end());
    int ans = 0;
    while (as.size() != 1) {
        ans++;
        int max = as.back();
        int min = as.front();
        as.pop_back();
        int mod = max % min;
        if (mod != 0) {
            as.emplace_front(mod);
        }
    }
    cout << ans << endl;
}