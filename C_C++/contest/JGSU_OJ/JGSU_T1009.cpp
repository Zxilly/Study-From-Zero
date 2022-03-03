//
// Created by zxilly on 2022/3/3.
//

#include <iostream>
#include <algorithm>

int ns[105];

using namespace std;

struct Item {
    int weight, value;
} items[105];

int dp[10005];

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

int main() {
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        int w, v;
        cin >> w >> v;
        items[i] = Item{w, v};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= items[i].weight; --j) {
            dp[j] = max(dp[j], dp[j - items[i].weight] + items[i].value);
        }
    }
    int ans = 0xcfcfcfcf;

    for (int i = 0; i <= W; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

}

#pragma clang diagnostic pop