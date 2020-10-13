#include <stdio.h>

int main(void)
{
    int x = 0, n = 0;
    double ans = 0, bottom = 1, signedSign = 0;
    scanf("%d %d", &x, &n);
    for (int I = 0; i < n; i++)
    {
        if (I % 2)
        {
            signedSign = -1;
        }
        else
        {
            signedSign = 1;
        }
        if (I)
        {
            bottom *= x;
        }
        ans += signedSign * 1.0 / bottom;
    }
    printf("%lf", ans);
    return 0;
}