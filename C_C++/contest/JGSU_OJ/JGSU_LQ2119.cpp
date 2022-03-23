//
// Created by zxilly on 2022/3/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

int f[2100000 << 3];

int find(int x) {
    if (x == f[x]) {
        return x;
    } else {
        f[x] = find(f[x]);
        return f[x];
    }
}

struct Edge {
    int p0, p1, val;
};

Edge edges[2100000 << 1];

int calDis(int a, int b) {
    int ans = 0;
    int a1 = a / 1000;
    int a2 = a % 1000 / 100;
    int a3 = a % 100 / 10;
    int a4 = a % 10;
    int b1 = b / 1000;
    int b2 = b % 1000 / 100;
    int b3 = b % 100 / 10;
    int b4 = b % 10;
    if (a1 != b1) {
        ans += a1 + b1;
    }
    if (a2 != b2) {
        ans += a2 + b2;
    }
    if (a3 != b3) {
        ans += a3 + b3;
    }
    if (a4 != b4) {
        ans += a4 + b4;
    }
    return ans;
}

int main() {
    for (int i = 0; i < (2100000 << 3); ++i) {
        f[i] = i;
    }
    int edgeCount = 0;
    for (int i = 1; i <= 2021; ++i) {
        for (int j = 1; j <= 2021; ++j) {
            if (i == j) continue;
            edges[edgeCount++] = Edge{
                    i, j, calDis(i, j)
            };
        }
    }
    sort(edges, edges + edgeCount, [](Edge a, Edge b) {
        return a.val < b.val;
    });

    int ans = 0;

    for (int i = 0; i < edgeCount; ++i) {
        int p0 = find(edges[i].p0);
        int p1 = find(edges[i].p1);
        if (p0 != p1) {
            ans += edges[i].val;
            f[p0] = p1;
        }
    }

    cout << ans << endl;

    return 0;
}