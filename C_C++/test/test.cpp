#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double attack;
        int resist[4];
        cin >> attack;
        cin >> resist[0] >> resist[1] >> resist[2] >> resist[3];

        double count = 0;
        for (int i: resist) {
            count += int(attack * (double) (100 - i) / 100);
            attack *= 0.85;
        }
        cout << (int) count << endl;
    }
}