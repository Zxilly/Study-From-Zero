#include <iostream>
#include <set>

const int maxn = 1e6 + 5;

int euler[maxn];
int primes[maxn];
int vis[maxn];
int asmap[maxn];

using namespace std;

int as[maxn];

int main() {
    int n;
    cin >> n;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        if (maxx < as[i]) maxx = as[i];
        asmap[as[i]] = 1;
    }

    int cnt = 0;
    euler[1] = 1;
    for (int i = 2; i <= maxx; ++i) {
        if (!vis[i]) {
            cnt++;
            primes[cnt] = i;
            euler[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= maxx; ++j) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                euler[primes[j] * i] = euler[i] * primes[j];
                break;
            } else {
                euler[primes[j] * i] = euler[i] * (primes[j] - 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (as[i] == 1) {
            continue;
        }
        ans += euler[as[i]];
    }
    cout << ans << endl;
}