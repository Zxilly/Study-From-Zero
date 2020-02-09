#include <cstdio>

struct model
{
    int s=0;
    int h=0;
    int ssum=0;
    int hsum=0;
}pointsum[200001];

int 
int judgechar(char temp,int i)
{
    if(temp=='L')
        pointsum[i].h--;
    else if(temp=='R')
        pointsum[i].h++;
    else if(temp=='U')
        pointsum[i].s--;
    else
        pointsum[i].s++;
}

int runtask()
{
    int count;
    char temp;
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
        scanf("%c",&temp);
        judgechar(temp,i);
    }
    for(int i=0;i<count;i++)
    {

    }
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