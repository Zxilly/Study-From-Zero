int numOfSubarrays(int* arr, int arrSize, int k, int threshold)
{
    int prefix[100001];
    int count=0;
    prefix[0]=0;
    prefix[1]=arr[0];
    for (int i=1;i<arrSize;i++)
    {
        prefix[i+1]=arr[i];
        prefix[i+1]+=prefix[i];
    }
    int pointer=0;
    while(pointer!=arrSize-k+1)
    {
        if(((prefix[pointer+k]-prefix[pointer])/k)>=threshold)
            {
                count++;
                //printf("count is %d\n",prefix[pointer+k]-prefix[pointer]);
                pointer++;
            }
        else
            {
                //printf("uncount is %d\n",prefix[pointer+k]-prefix[pointer]);
                pointer++;
            }
    };
    return count;
}


