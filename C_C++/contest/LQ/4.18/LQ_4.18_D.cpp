//
// Created by 12009 on 2020/4/18.
//
#include <bits/stdc++.h>

using namespace std;

int maritx[1001][1001]={0};

int main() {
    int m = 0,n = 0;
    int r = 0,c= 0;
    scanf("%d%d",&m,&n);
    scanf("%d%d",&r,&c);

    int now = 1;
    int U = 1, D = m, L = 1, R = n;
    int i = 1, j = 1;
    while (now <= m * n) {
        while (now <= m * n && j < R) {
            maritx[i][j] = now++;
            j++;
        }
        while (now <= m * n && i < D) {
            maritx[i][j] = now++;
            i++;
        }
        while (now <= m * n && j > L) {
            maritx[i][j] = now++;
            j--;
        }
        while (now <= m * n && i > U) {
            maritx[i][j] = now++;
            i--;
        }
        U++, D--, L++, R--;
        i++, j++;
        if (now == m * n) {
            maritx[i][j] = now++;
        }
    }
    printf("%d",maritx[r][c]);
    return 0;
}
/*
int n, m, numall; //y,x
int lp_m;
int map[1001][1001];

int lineplus(int x, int y, int num);
int lineminus(int x, int y, int num);
int rowplus(int x, int y, int num);
int rowminus(int x, int y, int num);

int lineplus(int x, int y, int num) {
    for(int i=x;i<=m-1;i++){
        map[i][y]=num;
        num++;
    }
    lp_m--;
    rowplus(x+1,y,num+1);
}

int lineminus(int x, int y, int num) {

}

int rowplus(int x, int y, int num) {
    for(int i=y;i<=n-1)
}

int rowminus(int x, int y, int num) {

}

using namespace std;

int main() {
    scanf("%d%d", &n, &m);
    lp_m=m;
    numall = n * m;
    lineplus(1,1,1);
    return 0;
}
*/