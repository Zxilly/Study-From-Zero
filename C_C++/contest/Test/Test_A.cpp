//
// Created by zxilly on 2021/11/6.
//
#include <iostream>

using namespace std;

const int maxn = 2e6;

int prime[maxn + 5];
int visit[maxn + 5];

void init() {
    for (int i = 2; i <= maxn; i++) {
        if (!visit[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    init();
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;

    }
}