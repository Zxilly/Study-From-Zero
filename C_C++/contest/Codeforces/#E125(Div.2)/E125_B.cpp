//
// Created by zxilly on 2022/3/23.
//

#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, B, x, y;
        ll result = 0;
        ll cur = 0;
        cin >> n >> B >> x >> y;
        while (n--) {
            if (cur + x > B) {
                cur -= y;
            } else {
                cur += x;
            }
            result += cur;
        }
        cout << result << "\n";
    }
    cout << flush;
    return 0;
}