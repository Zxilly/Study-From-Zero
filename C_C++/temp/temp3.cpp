#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {

        double a, b, c, p;
        cin >> a >> b >> c;
        p = (a + b + c) / 2;
        double sum = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << fixed << setprecision(2) << sum << endl;
    }

    return 0;
}