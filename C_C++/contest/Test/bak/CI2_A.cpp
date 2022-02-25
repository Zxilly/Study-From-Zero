//
// Created by zxilly on 2021/12/26.
//

#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x != 0 && x % 10 == 0) return false;
    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
}

int main() {
    int L, R, k;
    cin >> L >> R >> k;
    int min;
    if (L % 3 == 2) {
        min = L;
    } else {
        min = (L / 3 + 1) * 3 - 1;
    }
    int ans = 0;
    for (int i = min; i <= R; i += 3) {
        if (isPalindrome(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}