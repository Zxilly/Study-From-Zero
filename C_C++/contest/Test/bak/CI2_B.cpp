//
// Created by zxilly on 2021/12/26.
//

#include <iostream>
#include <set>

using namespace std;

set<long long> ans;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    ans.insert(b + c + d);
    ans.insert(b + c - d);
    ans.insert(b + c * d);
    ans.insert(b + c / d);
    ans.insert(b - c + d);
    ans.insert(b - c - d);
    ans.insert(b - c * d);
    ans.insert(b - c / d);
    ans.insert(b * c + d);
    ans.insert(b * c - d);
    ans.insert(b * c * d);
    ans.insert(b * c / d);
    ans.insert(b / c + d);
    ans.insert(b / c - d);
    ans.insert(b / c * d);
    ans.insert(b / c / d);
    cout << ans.size() << endl;
    return 0;
}