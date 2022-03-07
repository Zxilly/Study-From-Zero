//
// Created by zxilly on 2022/3/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 105;

long long a[maxn], b[maxn], c[maxn];
long long dp[2][maxn][maxn * maxn];

using namespace std;

void solve() {
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[n % 2][1][n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            int down = (i + i + j) * (j - 1) / 2 + n, up = (n + n - j + 1) * j / 2;
            for (int k = down; k <= up; k++) {
                dp[i % 2][j + 1][k + i] = max(dp[i % 2][j + 1][k + i], dp[(i + 1) % 2][j][k] + a[i]);
                dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j][k] + (k - i * j) * b[i]);
                dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j][k] + j * c[i]);
            }
        }
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= 5050; k++) {
            ans = max(ans, dp[1][j][k]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}