//
// Created by zxilly on 2021/12/12.
//

#include <string>
#include <iostream>

using namespace std;

char move(char a) {
    if (a == 'z') {
        return 'a';
    }
    if (a == 'Z') {
        return 'A';
    }
    return a + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    string child, empty, parent;
    cin >> k >> child;
    getline(cin, empty);
    getline(cin, parent);
    int last = 0, cnt = 0;
    while (true) {
        int p = parent.find(child, last);
        if (p == string::npos) break;
        last = p + child.length();
        if (++cnt == k) {
            for (int i = 0; i < child.length(); ++i) {
                parent[p + i] = move(parent[p + i]);
            }
            break;
        }
    }
    if (cnt < k) {
        cout << "F" << endl;
    } else {
        cout << parent << endl;
    }

    return 0;
}