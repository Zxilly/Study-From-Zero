//
// Created by zxilly on 2022/9/8.
//

#include <bits/stdc++.h>

using namespace std;

int getNext(int n) {
    return (n - 1) / 2;
}

void solve() {
    int n;
    cin >> n;

//    if (n == 4) {
//        cout << "2 1 3 4" << endl;
//        return;
//    } else if (n == 5) {
//        cout << "1 2 3 4 5" << endl;
//        return;
//    } else if (n == 6) {
//        cout << "4 5 1 2 3 6" << endl;
//        return;
//    }
    deque<int> ans;
    ans.emplace_front(n);
    if (n % 2 == 1) {
        ans.emplace_front(n - 2);
        ans.emplace_front(1);
        ans.emplace_front(2);
        ans.emplace_front(n - 1);
        for (int i = 3; (n - i) > i; ++i) {
            ans.emplace_front(i);
            ans.emplace_front(n - i);
        }
    } else {
        ans.emplace_front(n - 1);
        for (int i = 1; i <= n - 2; ++i) {
            ans.emplace_front(i);
        }
    }
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}