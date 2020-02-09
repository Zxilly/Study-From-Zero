#include <bits/stdc++.h>

int judgeodd(int input)
{
    if(input%2==0)
        return 0;
    else
        return 1;
}

int runtask()
{
    int n=0,temp,oddnum=0,noddnum=0;
    int stop=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(judgeodd(temp))
        {
            oddnum++;
        }
        else
        {
            noddnum++;
        }
    }

    if(noddnum==n)
    {
        printf("NO\n");
        return 0;
    }
    else if(judgeodd(n))
    {
        printf("YES\n");
        return 0;
    }
    else if(oddnum==n)
    {
        printf("NO\n");
        return 0;
    }
    else
    {
        printf("YES\n");
        return 0;
    }

}

int main()
{
    int count;
    scanf("%d",&count);
    for (int i=1;i<=count;i++)
    {
        runtask();
    }
}