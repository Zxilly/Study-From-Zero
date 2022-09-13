//
// Created by zxilly on 2022/9/12.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int count;
    cin >> count;
    vector<int> want(count);
    vector<int> have(count);
    for (int i = 0; i < count; ++i) {
        cin >> want[i];
    }
    for (int i = 0; i < count; ++i) {
        cin >> have[i];
    }

    priority_queue<int, vector<int>, greater<>> min_pq;
    priority_queue<int, vector<int>> max_pq;
    int zeroCount = 0;

    for (int i = 0; i < count; ++i) {
        int value = have[i] - want[i];
        if (value > 0) {
            min_pq.emplace(value);
        } else if (value < 0) {
            max_pq.emplace(value);
        } else {
            zeroCount++;
        }
    }

    int result = 0;

    while (true) {
        if (min_pq.empty()) {
            break;
        }
        if (max_pq.empty()) {
            max_pq.emplace(-2e9 - 5);
        }
        int debt = min_pq.top();
        int credit = max_pq.top();
        if ((-debt) > credit) {
            // pair with zero
            if (zeroCount > 0) {
                zeroCount--;
                min_pq.pop();
                result++;
            } else {
                if (min_pq.size() >= 2) {
                    min_pq.pop();
                    min_pq.pop();
                    result++;
                } else {
                    break;
                }
            }
        } else {
            max_pq.pop();
            min_pq.pop();
            result++;
        }
    }
    result += zeroCount / 2;

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}