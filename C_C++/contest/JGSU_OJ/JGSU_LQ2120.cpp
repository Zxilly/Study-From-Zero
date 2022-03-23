//
// Created by zxilly on 2022/3/12.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>

typedef long long ll;

using namespace std;

ll dp[20210509 + 10];


map<ll, vector<ll>> cache;

vector<ll> divisors(ll N) {
    if (cache.count(N)) return cache[N];
    vector<ll> res{1};
    if (N == 1) return res;
    res.push_back(N);
    const ll sq = ll(sqrt(N));
    for (ll i = 2; i <= sq; i++) {
        if (N % i == 0) {
            res.push_back(i);
            res.push_back(N / i);
        }
    }
    if (sq * sq == N) res.pop_back();
    sort(res.begin(), res.end());
    cache[N] = res;
    return res;
}

int main() {
    dp[1] = 1;
}