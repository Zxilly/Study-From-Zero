//
// Created by zxilly on 2021/11/6.
//

#include <iostream>
#include <deque>

using namespace std;

// Calculate how many element can be dropped from a deque in order.
int solve() {
    int n;
    cin >> n;
    deque<int> a;
    int ans = 0;
    int current = 0;
    while (n--) {
        int val;
        cin >> val;
        a.push_back(val);
    }
    while (!a.empty()) {
        int front = a.front();
        int back = a.back();
        if (front < current && back < current) {
            break;
        } else {
            ans++;
            if (front<current){
                a.pop_back();
                current = back;
                continue;
            }
            if (back<current) {
                a.pop_front();
                current = front;
                continue;
            }
            if (front<back) {
                a.pop_front();
                current = front;
            } else {
                a.pop_back();
                current = back;
            }
        }
    }
    return ans;
}

int main() {
    cout << solve() << endl;
}