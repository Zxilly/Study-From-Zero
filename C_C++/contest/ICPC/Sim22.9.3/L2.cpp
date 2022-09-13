//
// Created by zxilly on 2022/9/3.
//
#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int maxn = 5e5 + 5;
string s1, s2, s3;
int l1, l2;
int unit, length;

class StringHash {
private:
    int mod;
    vector<ll> ppow, hpre;
public:
    explicit StringHash(const string &s, int p = 114514, int mod = 998244353) {
        this->mod = mod;
        this->ppow.push_back(1);
        this->hpre.push_back(0);
        for (int i = 1; i <= s.length(); i++) {
            this->ppow.push_back(this->ppow[i - 1] * p % mod);
            this->hpre.push_back(hpre[i - 1] * p % mod + s[i - 1] % mod);
        }
    }

    long long get(unsigned long long l, unsigned long long r) {
        if (l > r) return -1;
        return (hpre[r] - hpre[l - 1] * this->ppow[r - l + 1] % mod + mod) % mod;
    }

};

bool check(string &s) {
    StringHash hs2(s2);
    StringHash hst(s);
    auto hs2hash = hs2.get(1, length);
    for (int i = 1; i <= length; i += unit) {
        if (hst == hs2hash) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> s1 >> s2;
    cin >> l1 >> l2;
    length = s1.length();
    unit = __gcd(abs(l1 - l2), length);
    if (check(s1)) {
        cout << "yes" << endl;
        return;
    }

    reverse_copy(s1.begin(), s1.begin() + l1, back_inserter(s3));
    reverse_copy(s1.begin() + l1, s1.end(), back_inserter(s3));

    if (check(s3))
        cout << "yes" << endl;
    else cout << "no" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}