//
// Created by zxilly on 2022/9/8.
//
#include <bits/stdc++.h>

using namespace std;

void mapInit(map<int, int> &m) {
    for (int i = 2; i <= 10; ++i) {
        m[i] = 0;
    }
}

int digitallog(int a) {
    return int(log10(a)) + 1;
}

void solve() {
    int a;
    multiset<int> va;
    multiset<int> vb;
    map<int, int> am;
    map<int, int> bm;
    mapInit(am);
    mapInit(bm);


    cin >> a;
    for (int i = 0; i < a; ++i) {
        int temp;
        cin >> temp;
        if (temp < 10) {
            am[temp]++;
        } else {
            va.emplace(temp);
        }
    }
    for (int i = 0; i < a; ++i) {
        int temp;
        cin >> temp;
        if (temp < 10) {
            bm[temp]++;
        } else {
            vb.emplace(temp);
        }
    }
    vector<int> atodo;
    vector<int> btodo;

    set_difference(va.begin(), va.end(), vb.begin(), vb.end(), back_inserter(atodo));
    set_difference(vb.begin(), vb.end(), va.begin(), va.end(), back_inserter(btodo));

    unsigned long long opCount = 0;
    opCount += atodo.size();
    opCount += btodo.size();
    for (auto ta: va) {
        int ret = digitallog(ta);
        am.at(ret)++;
    }
    for (auto tb: vb) {
        int ret = digitallog(tb);
        bm.at(ret)++;
    }
    if (am[10] != bm[10]) {
        if (am[10] > bm[10]) {
            opCount += am[10] - bm[10];
            am[2] += am[10] - bm[10];
        } else {
            opCount += bm[10] - am[10];
            bm[2] += bm[10] - am[10];
        }
    }
    for (int i = 2; i <= 9; ++i) {
        opCount += abs(am[i] - bm[i]);
    }
    cout << opCount << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}