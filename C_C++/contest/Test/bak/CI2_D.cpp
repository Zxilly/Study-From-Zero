//
// Created by zxilly on 2021/12/26.
//

#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

map<string, pair<string, pair<int, int>>> server;
map<string, pair<string, pair<int, int>>> client;
map<pair<string, string>, double> ans;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int n2 = 2 * n;
    while (n2--) {
        string hash, id;
        char type;
        int x, y;
        cin >> hash >> type >> id >> x >> y;
        if (type == 'S') {
            server[hash] = {id, {x, y}};
        } else {
            client[hash] = {id, {x, y}};
        }
    }
    for (auto &s: server) {
        auto &c = client[s.first];
        auto p = make_pair(c.first, s.second.first);
        ans[p] = sqrt(
                pow(c.second.first - s.second.second.first, 2) + pow(c.second.second - s.second.second.second, 2));
    }
    vector<pair<pair<string, string>, double>> arr;
    arr.reserve(ans.size());
    for (const auto &item: ans) {
        arr.emplace_back(item);
    }
    sort(arr.begin(), arr.end(),
         [](const pair<pair<string, string>, double> &a, const pair<pair<string, string>, double> &b) {
             return a.first.first < b.first.first;
         });
    for (const auto &item: arr) {
        printf("%s %s %.2lf\n", item.first.first.c_str(), item.first.second.c_str(), item.second);
    }
    return 0;
}