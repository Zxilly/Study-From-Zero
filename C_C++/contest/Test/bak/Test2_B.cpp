//
// Created by zxilly on 2021/11/7.
//

#include <iostream>

using namespace std;

int visit[30000];
int input[200];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int index = input[i] + input[j];
            visit[index] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (visit[input[i]]) {
            ans++;
        }
    }
    cout << ans << endl;
}