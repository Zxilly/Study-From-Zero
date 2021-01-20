#include <bits/stdc++.h>

int runtask()
{
    int get;
    int sum=0;
    int get_10;
    scanf("%d",&get);
    while(1)
    {
        if(get<10)
        {
            sum+=get;
            break;
        }
        else
        {
            get_10=(int)(get/10);
            sum+=10*get_10;
            get-=get_10*9;
        }
    }
    printf("%d\n",sum);
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        runtask();
    }
    return 0;
}