//
// Created by zxilly on 2022/9/12.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int count;
    string s;
    cin >> count >> s;
    string ans;
    // try get 3
    for (int i = count - 1; i >= 0;) {
        if (s[i] == '0') {
            string num;
            num.push_back(s[i - 2]);
            num.push_back(s[i - 1]);
            int numInt = stoi(num);
            ans += (char) (numInt + 'a' - 1);
            i -= 3;
        } else {
            int numInt = s[i] - '0';
            ans += (char) (numInt + 'a' - 1);
            i -= 1;
        }
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}