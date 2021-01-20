int get(int a,int b)
{
    if(a>b)
    {
        return a-b;
    }
    else
    {
        return b-a;
    }
}

int minSteps(char * s, char * t)
{
    int s_count[26]={0};
    int t_count[26]={0};
    int count=0;
    int need=0;
    int unneed=0;
    int length=strlen(s);
    for(int i=0;i<length;i++)
    {
        s_count[s[i]-'a']++;
        t_count[t[i]-'a']++;
        //printf("s_count is %d\n",s_count[s[i]-'0'-50]);
    }
    for(int i=0;i<26;i++)
    {
        count+=get(s_count[i],t_count[i]);
    }
    return count/2;
}

