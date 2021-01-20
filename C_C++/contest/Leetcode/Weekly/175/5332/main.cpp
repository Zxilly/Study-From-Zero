bool checkIfExist(int* arr, int arrSize)
{
    int prefix[501];
    for(int i=0;i<arrSize;i++)
    {
        prefix[i]=2*arr[i];
    }
    for(int i=0;i<arrSize;i++)
    {
        for(int j=0;j<arrSize;j++)
        {
            if(prefix[j]==arr[i]&&i!=j)
            {
                return true;
            }
        }
    }
    return false;
}