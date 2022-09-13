//
// Created by zxilly on 2022/9/3.
//
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <functional>

using namespace std;
//==========================================


typedef long long ll;

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

signed main(signed argc, char const *argv[]) {
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int l1, l2;
        cin >> l1 >> l2;
        StringHash hs1(s1);
        StringHash hs2(s2);
        int n = s1.length();
        for (int i = l1; i <= l2; ++i) {
            int unit = __gcd(n, abs(l1 - l2));
            for (int j = 1; j <= n / unit; ++j) {
                if (hs.get(1, n) == hs2.get(1, n)) {
                    cout << "yes" << endl;
                    goto nextrun;
                }
            }
            for (int j = 1; j <= n / unit; ++j) {
                if (hs.get(1, n) == hs2.get(1, n)) {
                    cout << "yes" << endl;
                    goto nextrun;
                }
            }
        }

        cout << "no" << endl;
        nextrun:
        continue;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}