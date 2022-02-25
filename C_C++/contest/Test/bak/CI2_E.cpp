//
// Created by zxilly on 2021/12/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ns;
vector<int> cache;

int main() {
    ios::sync_with_stdio(false);
    int n, l, v;
    cin >> n >> l >> v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ns.push_back(t);
    }
    sort(ns.begin(), ns.end(), greater<int>());
    cache.push_back(ns.at(0));
    for (int i = 1; i < ns.size(); ++i) {
        cache.push_back(cache.at(i - 1) + ns.at(i));
    }
    int q;
    cin >> q;
    while (q--) {
        int j;
        cin >> j;
        int require = v * j - l;
        if (require <= 0) {
            cout << -1 << endl;
            continue;
        }
        // find element greater than require in cache
        auto index = lower_bound(cache.begin(), cache.end(), require,greater<int>());
        if (index == cache.end()) {
            cout << -1 << endl;
        } else {
            cout << index - cache.begin() + 1 << endl;
        }
    }
}