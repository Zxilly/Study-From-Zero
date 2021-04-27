//
// Created by 12009 on 2021/4/15.
//

#include <bits/stdc++.h>

#define maxn 5000001

bool isPrimeArray[maxn];
int target[21];
int primes[maxn];
int n, k;

int ans = 0;

void initPri() {
    int temp;
    int cnt = 0;

    memset(isPrimeArray, 1, sizeof isPrimeArray);

    isPrimeArray[1] = false;
    for (int i = 2; i < maxn; i++) {
        if (isPrimeArray[i] == 1)
            primes[cnt++] = i;
        for (int j = 0; j < cnt && (temp = i * primes[j]) < maxn; j++) {
            isPrimeArray[temp] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

bool isPrime(int a) {
    return isPrimeArray[a];
}

void dfs(int layer, int start, int end, int currentValue) { // layer 从1开始，
    if (layer <= k) {
        for (int i = start; i <= end; ++i) {
            dfs(layer + 1, i+1, end+1, currentValue + target[start]);
        }
    } else {
        printf("%d\n",currentValue);
        if (isPrime(currentValue)){
            ans++;
        }
    }
}

int main() {
    initPri();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &target[i]);
    }
    dfs(0, 0, n - k + 1, 0);
    printf("%d", ans);
    return 0;
}