//
// Created by zxilly on 2021/12/12.
//

#include <iostream>

using namespace std;

const int keyboard = 8;
const int mouse = 4;
const int display = 2;
const int sound = 1;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        int err = 0;
        if (a & keyboard) err++;
        if (a & mouse) err++;
        if (a & display) err++;
        if (a & sound) err++;
        if (err >= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}