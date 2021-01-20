//
// Created by 12009 on 2020/4/18.
//

#include <bits/stdc++.h>

int dp[1001][1001];

using namespace std;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        dp[1][i] = n - i + 1;
    }
    for (int i = 2; i <= m; i++) {
        if (i & 1) {
            for (int j = n; j >= 1; j--) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j + 1]) % 10000;
            }

        } else {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % 10000;
            }
        }
    }
    if (m & 1) {
        printf("%d", dp[m][n]);
    } else {
        printf("%d", dp[m][1]);
    }
    return 0;
}
