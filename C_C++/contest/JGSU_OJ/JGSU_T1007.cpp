#include <iostream>
#include <algorithm>

using namespace std;

int f[100005 << 3];

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

Edge edges[100005 << 1];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 400020; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge{
                u, v, w
        };
    }
    sort(edges, edges + m, [](Edge a, Edge b) {
        return a.val < b.val;
    });

    int ans = 0;

    for (int i = 0; i < m; ++i) {
        int p0 = find(edges[i].p0);
        int p1 = find(edges[i].p1);
        if (p0 != p1) {
            n--;
            ans += edges[i].val;
            f[p0] = p1;
        }
    }

    if (n == 1) cout << ans << endl;
    else cout << "Disconnected" << endl;

    return 0;
}