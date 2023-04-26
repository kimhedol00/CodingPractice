#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)
int maximumCount(int* nums, int numsSize){
    int pos = 0;
    int neg = 0;
    int zero = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] > 0) pos++;
        else if(nums[i] < 0) neg++;
        else zero++;
    }
    return MAX(pos,neg);
}

int main()
{
    int numsSize;
    int nums[2001];
    scanf("%d", &numsSize);
    for(int i = 0; i < numsSize; ++i) scanf("%d", &nums[i]);
    int ans = maximumCount(nums, numsSize);
    printf("%d\n", ans);
    return 0;
}

/*
int maximumCount(int* nums, int numsSize){
    int i,n=0,p=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]<0)
            n++;
        else if(nums[i]>0)
            p++;
    }

    if(n>p)
        return n;
    else
        return p;
}
*/