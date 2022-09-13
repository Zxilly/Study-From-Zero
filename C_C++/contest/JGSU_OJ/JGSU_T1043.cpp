//
// Created by zxilly on 2022/9/13.
//


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const int maxn = 1e6 + 5;

vector<ll> ns;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n, k;
    cin >> n >> k;
    int tn = n;
    while (tn--) {
        int temp;
        cin >> temp;
        ns.emplace_back(temp);
    }

    long long ans = 0;
    long long current = 0;
    int lp = 0;

    for (int rp = 0; rp < n; ++rp) {
        current += ns[rp];
        while (current > k && lp < rp) {
            current -= ns[lp];
            lp++;
        }
        ans += rp - lp + 1;
    }

    cout << ans << endl;
}