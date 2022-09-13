//
// Created by zxilly on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
//    map<int, set<vector<int>>> mp;
//    mp[1] = {{1}};
//    for (int i = 2; i <= 20; ++i) {
//        set<vector<int>> arrays;
//        for (const auto &m: mp.at(i - 1)) {
//            auto frontv = m;
//            auto backv = m;
//            frontv.insert(frontv.begin(), 1);
//            backv.push_back(1);
//            arrays.insert(frontv);
//            arrays.insert(backv);
//        }
//        for (const auto &m: mp.at(i - 1)) {
//            auto todov = m;
//            for(int j = 0; j < todov.size(); ++j){
//                auto increasev = todov;
//                increasev[j]++;
//                arrays.insert(increasev);
//            }
//        }
//        mp[i] = arrays;
//        cout << "i: " << i << " " << "cnt: " << arrays.size() << endl;
//    }
    int k;
    cin >> k;
    cout << (int(pow(2, k - 1))) << endl;
}