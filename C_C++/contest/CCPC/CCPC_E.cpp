//
// Created by zxilly on 2021/10/10.
//

#include <iostream>
#include <ctime>

using namespace std;
clock_t c1;

inline void exit() {
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <cstring>

const int maxn = 5e5 + 5;
typedef long long ll;
ll pre[maxn];

#include <map>

map<ll, int> mp;

signed main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin >> t;
    while (t--) {
        memset(pre, 0, sizeof(pre));
        mp.clear();
        int n, m;
        cin >> n >> m;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
            pre[i] = pre[i - 1] + tmp;
            if (!mp[pre[i]]) mp[pre[i]] = i;
        }
        while (m--) {
            ll x;
            cin >> x;
            if (!sum) { if (x) cout << -1 << endl; else cout << 0 << endl; }
            if (!x) {
                cout << 0 << endl;
                continue;
            }
            ll ans = 0;
            auto it = mp.find(x % sum ? x - x / sum * sum : ((x / sum) - 1) * sum);
            if (it != mp.end()) {
                ll tmp = (x - it->first) / sum;
                ans = tmp * n + it->second;
            } else {
                ans = (x / sum) * n + x % sum;
            }
            if (ans < 0) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    //======================================
    exit();
}