//
// Created by zxilly on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;

int n, backport[maxn];
string s;

void out(int a){
    cout << a+1 << " ";
}

void dfs(int l, int r) {
    if (l > r) {
        return;
    }
    if (s[l] != '(') {
        out(l);
        dfs(l + 1, r);
    } else {
        dfs(l + 1, backport[l] - 1);
        out(backport[l]);
        out(l);
        dfs(backport[l] + 1, r);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    cin >> s;

    stack<int> STK;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            STK.push(i);
        } else if (s[i] == '-') {
            backport[i] = i;
        } else if (s[i] == ')') {
            backport[STK.top()] = i;
            backport[i] = i;
            STK.pop();
        }
    }
    dfs(0, n - 1);
    cout.flush();
}