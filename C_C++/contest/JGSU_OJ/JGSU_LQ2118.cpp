//
// Created by zxilly on 2022/3/12.
//


#include <iostream>

using namespace std;


long long factorial(long long n) {
    long long ans = 1;
    for (long long i = 1; i <= n; ++i) {
        ans *= i;
    }
    cout<<ans<<endl;
    return ans;
}

int main() {
    long long ans = factorial(2021) / (factorial(4) * factorial(2021 - 4));
    cout << ans << endl;
}