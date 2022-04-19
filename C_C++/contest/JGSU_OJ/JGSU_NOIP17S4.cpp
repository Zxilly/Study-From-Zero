//
// Created by zxilly on 2022/3/30.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>

typedef long long ll;

using namespace std;

struct Location {
    ll x, y, z;
};

Location la[1005];
int fa[1005];

int find(int x) {
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void reset() {
    memset(fa, 0, sizeof fa);
    for (int i = 0; i < 1005; ++i) {
        fa[i] = i;
    }
}

bool isConnect(Location a, Location b, ll r) {
    auto distance2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    if (distance2 > ((r * 2) * (r * 2))) {
        return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        reset();
        ll n, h, r;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            la[i] = Location{x, y, z};

            // check point to point
            if (i > 1) {
                for (int j = 1; j < i; ++j) {
                    if (isConnect(la[i], la[j], r)) {
                        unionSet(i, j);
                    }
                }
            }
            // check point to top (0)
            if (z >= h - r) {
                unionSet(i, 0);
            }
            // check point to bottom (n+1)
            if (z <= r) {
                unionSet(i, n + 1);
            }
        }
        // check top to bottom
        bool li = find(0) == find(n + 1);
        if (li) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}