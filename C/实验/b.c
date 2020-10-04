#include <stdio.h>

int main(void)
{
    int x=0,n=0;
    double ans=0,bottom=1,signedSign = 0;
    scanf("%d %d",&x,&n);
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            signedSign = -1;
        }
        else
        {
            signedSign = 1;
        }
        if(i)
        {
            bottom*=x;
        }
        ans+=signedSign*1.0/bottom;
    }
    printf("%lf",ans);
    return 0 ;
}