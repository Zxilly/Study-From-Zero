#include <iostream>
#include <ctime>

using namespace std;
const int maxn = 1e5 + 5;

int main() {
    time_t t = 100000000000LL;
    tm time = *gmtime(&t);
    char ch[100];
    strftime(ch, sizeof(ch), "%H:%M:%S", &time);
    cout << ch << endl;
    return 0;
}