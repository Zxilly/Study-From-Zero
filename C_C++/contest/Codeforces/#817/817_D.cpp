//
// Created by zxilly on 2022/8/30.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long length;
        cin >> length;
        string s;
        cin >> s;
        vector<int> error;
        vector<int> errorCount;
        auto middle = (length + 1) / 2;
        for (int j = 1; j <= length; ++j) {
            if (j <= middle) {
                if (s[j - 1] == 'L') {
                    error.emplace_back(j);
                }
            } else {
                if (s[j - 1] == 'R') {
                    error.emplace_back(j);
                }
            }
        }
        for (auto index: error) {
            int value = abs(2 * index - 1 - length);
            if (value != 0) {
                errorCount.emplace_back(value);
            }
        }
        sort(errorCount.begin(), errorCount.end(), greater<>());

        long long mostPossible = 0;
        if (length % 2 == 0) {
            mostPossible = (3 * length * length - 2 * length) / 4;
        } else {
            mostPossible = (3 * length * length - 2 * length - 1) / 4;
        }
        long long possible = mostPossible;
        for (auto count: errorCount) {
            possible -= count;
        }
        for (auto count: errorCount) {
            possible += count;
            cout << possible << " ";
        }
        for (int j = 0; j < (length - errorCount.size()); ++j) {
            cout << mostPossible << " ";
        }

        cout << endl;
    }
}