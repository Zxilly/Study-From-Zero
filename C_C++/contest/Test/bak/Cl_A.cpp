#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        char op1, op2;
        int a, b, c;
        cin >> a >> op1 >> b >> op2 >> c;
        if (op1 == '+' && op2 == '*') {
            cout << a + b * c << endl;
        } else if (op1 == '+' && op2 == '+') {
            cout << a + b + c << endl;
        } else if (op1 == '+' && op2 == '%') {
            cout << a + b % c << endl;
        } else if (op1 == '*' && op2 == '+') {
            cout << a * b + c << endl;
        } else if (op1 == '*' && op2 == '*') {
            cout << a * b * c << endl;
        } else if (op1 == '*' && op2 == '%') {
            cout << a * b % c << endl;
        } else if (op1 == '%' && op2 == '+') {
            cout << a % b + c << endl;
        } else if (op1 == '%' && op2 == '*') {
            cout << a % b * c << endl;
        } else if (op1 == '%' && op2 == '%') {
            cout << a % b % c << endl;
        }
    }
    return 0;
}