//
// Created by zxilly on 2021/4/13.
//


#include <bits/stdc++.h>

using namespace std;

int main() {
    char lineBuffer[100001];
    int lineBufferLength = 0;
    char ch;
    int win = 0, lose = 0;

    memset(lineBuffer, 0, 5001);
    while (cin >> ch) {
        if (ch == 'E') {
            break;
        } else {
            lineBuffer[lineBufferLength++] = ch;
        }
    }

    int i = 0;
    while (true) {
        char crCh = lineBuffer[i++];
        if (crCh == 'W') {
            win++;
        } else if (crCh == 'L') {
            lose++;
        } else if (crCh == 0){
            printf("%d:%d\n", win, lose);
            break;
        }
        if (abs(win - lose) >= 2) {
            if (win >= 11 || lose >= 11) {
                printf("%d:%d\n", win, lose);
                win = 0;
                lose = 0;
            }
        }
    }

    win = 0;
    lose = 0;
    i = 0;
    printf("\n");

    while (true) {
        char crCh = lineBuffer[i++];
        if (crCh == 'W') {
            win++;
        } else if (crCh == 'L') {
            lose++;
        } else if (crCh == 0){
            printf("%d:%d\n", win, lose);
            break;
        }
        if (abs(win - lose) >= 2) {
            if (win >= 21 || lose >= 21) {
                printf("%d:%d\n", win, lose);
                win = 0;
                lose = 0;
            }
        }
    }

    return 0;
}