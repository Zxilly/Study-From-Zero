//
// Created by zxilly on 2022/8/30.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int wordNum;
        map<string, int> wordMap;
        cin >> wordNum;
        string manWords[1005][3];
        for (int man = 0; man < 3; ++man) {
            for (int j = 0; j < wordNum; ++j) {
                cin >> manWords[j][man];
            }
        }
        for (int man = 0; man < 3; ++man) {
            for (int j = 0; j < wordNum; ++j) {
                auto item = wordMap.find(manWords[j][man]);
                if (item != wordMap.end()) {
                    item->second++;
                } else {
                    wordMap.insert(make_pair(manWords[j][man], 1));
                }
            }
        }
        int manscore[3] = {0, 0, 0};
        for (int man = 0; man < 3; ++man) {
            for (int j = 0; j < wordNum; ++j) {
                auto word = manWords[j][man];
                auto count = wordMap[word];
                if (count == 3) {
                    continue;
                } else if (count == 2) {
                    manscore[man] += 1;
                } else if (count == 1) {
                    manscore[man] += 3;
                }
            }
        }
        cout << manscore[0] << " " << manscore[1] << " " << manscore[2] << endl;
    }
}