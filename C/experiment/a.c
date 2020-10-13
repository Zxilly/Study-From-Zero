#include <stdio.h>

double getPrime(int x, int n)
{
    double resp = 1;
    for (int I = 0; i < n; i++)
    {
        resp *= x;
    }
    //printf("Prime is %d\n",resp);
    return resp;
}

double getXn(int x, int n)
{
    double signedSign = 0;
    if (n % 2)
    {
        signedSign = -1;
    }
    else
    {
        signedSign = 1;
    }
    printf("Xn=%lf\n", signedSign * (1.0 / getPrime(x, n)));
    return signedSign * (1 / getPrime(x, n));
}

int main(void)
{
    int x = 0, n = 0;
    double ans = 0;
    printf("Wait for input:");
    scanf("%d %d", &x, &n);
    for (int I = 0; i < n; i++)
    {
        printf("%d %d\n", x, i);
        ans += getXn(x, i);
    }
    printf("%lf", ans);
    return 0;
}