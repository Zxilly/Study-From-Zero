#include <iostream>

using namespace std;

int yyyy = 0;
int mm = 0;
int dd = 0;

bool isLeapYear() {
    if (yyyy % 4 == 0) {
        if (yyyy % 100 == 0) {
            if (yyyy % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void addYear() {
    yyyy++;
}

void addMonth() {
    if (mm == 12) {
        mm = 1;
        addYear();
    } else {
        mm++;
    }
}

void addDay() {
    int up = 0;
    switch (mm) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            up = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            up = 30;
            break;
        case 2:
            if (isLeapYear()) {
                up = 29;
            } else {
                up = 28;
            }
    }
    if (dd == up) {
        dd = 1;
        addMonth();
    } else {
        dd++;
    }
}

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int whole;
    int ans1 = 0;
    int ans2 = 0;

    cin >> whole;
    yyyy = whole / 10000;
    mm = (whole % 10000) / 100;
    dd = (whole % 10000) % 100;

    while (true) {
        addDay();
        int target = mm * 100 + dd;
        if (yyyy == reverse(target)) {
            if (ans1 == 0) {
                ans1 = yyyy * 10000 + mm * 100 + dd;
            }
            int a, b, c, d;
            a = yyyy / 1000;
            b = (yyyy % 1000) / 100;
            c = (yyyy % 1000) % 100 / 10;
            d = (yyyy % 1000) % 100 % 10;
            if (a == c && b == d) {
                ans2 = yyyy * 10000 + mm * 100 + dd;
            }
        }
        if (ans1 != 0 && ans2 != 0) {
            break;
        }
    }
    cout << ans1 << endl << ans2 << endl;

}