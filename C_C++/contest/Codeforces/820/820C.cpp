//
// Created by zxilly on 2022/9/12.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    map<int, vector<int>> charLoc;
    for (int i = 0; i < 26; ++i) {
        charLoc[i] = vector<int>();
    }
    for (int i = 0; i < s.size(); ++i) {
        charLoc[s[i] - 'a'].push_back(i);
    }

    if (s[0] > s[s.size() - 1]) {
        // sub
        vector<int> result;
        for (char l = s[0]; l >= s[s.size() - 1]; --l) {
            for (int i = 0; i < charLoc[l - 'a'].size(); ++i) {
                result.push_back(charLoc[l - 'a'][i]);
            }
        }
        cout << s[0] - s[s.size() - 1] << " " << result.size() << "\n";
        for (auto i: result) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else if (s[0] < s[s.size() - 1]) {
        vector<int> result;
        for (char l = s[0]; l <= s[s.size() - 1]; ++l) {
            for (int i = 0; i < charLoc[l - 'a'].size(); ++i) {
                result.push_back(charLoc[l - 'a'][i]);
            }
        }
        cout << s[s.size() - 1] - s[0] << " " << result.size() << "\n";
        for (auto i: result) {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return;
    } else {
        vector<int> result;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == s[0]) {
                result.push_back(i + 1);
            }
        }
        cout << 0 << " " << result.size() << '\n';
        for (int i: result) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }


}

int main() {
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}