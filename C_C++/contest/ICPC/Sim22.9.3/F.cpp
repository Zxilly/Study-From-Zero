//
// Created by zxilly on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > v = {
        {},
        {2, 3},
        {1, 4},
        {1, 4},
        {2, 3, 5, 6},
        {4, 7},
        {4, 7},
        {5, 6}
};

map<pair<int, int>, int> M;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if (b1 > b2) swap(b1, b2);
    if (a1 > a2) swap(a1, a2);

    M.clear();

    queue<pair<int, int> > q;
    q.push({a1, a2});

    M[{a1, a2}] = 0;
    while (!q.empty()) {
        int ab = q.front().first;
        int bb = q.front().second;
        int step = M[{ab, bb}];

        if (ab == b1 && bb == b2) {
            cout << step << endl;
            return;
        }
        q.pop();

        for (auto target: v[ab]) {
            if (target != bb) {
                int tx = min(target, bb);
                int ty = max(target, bb);
                if (M.count({tx, ty})) {
                    continue;
                }
                M[{tx, ty}] = step + 1;
                q.push({tx, ty});
            }
        }
        for (auto target: v[bb])
            if (target != ab) {
                int tx = min(target, ab);
                int ty = max(target, ab);
                if (tx > ty) {
                    swap(tx, ty);
                }
                if (M.count({tx, ty})) {
                    continue;
                }
                M[{tx, ty}] = step + 1;
                q.push({tx, ty});
            }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    };
}