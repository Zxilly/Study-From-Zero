//
// Created by zxilly on 2021/12/12.
//

#include <string>
#include <iostream>

using namespace std;

const int maxn = 1005;
int a[maxn][maxn];
long long pre[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    long long mx = 0;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            mx = max(mx, pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k]);
    cout << mx << endl;
    return 0;
}