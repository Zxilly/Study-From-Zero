#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by zxilly on 2022/2/28.
//

#include <iostream>

using namespace std;

int mp[2001][2001];
int post_mp[2001][2001];

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            post_mp[i][j] = post_mp[i - 1][j] + post_mp[i][j - 1] - post_mp[i - 1][j - 1] + mp[i - 1][j - 1];
        }
    }

    int res = 0xcfcfcfcf;

    for (int i = p; i <= n; ++i) {
        for (int j = q; j <= m; ++j) {
            int tmp = post_mp[i][j] - post_mp[i - p][j] - post_mp[i][j - q] + post_mp[i - p][j - q];
            //cout << i << "," << j << " " << i - p << "," << j - q << " " << tmp << endl;
            res = max(res, tmp);
        }
    }
    cout << res << endl;
}