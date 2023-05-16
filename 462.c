#include <stdio.h>


/*
int minMoves2(int* nums, int numsSize){
    int sum = 0;
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    sum /= numsSize;
    for(int i = 0; i < numsSize; ++i)
    {
        temp = sum - nums[i];
        temp = temp >= 0 ? temp : -temp;
        ans += temp;
    }
    return ans;
}
*/
// 평균을 사용하면 안됨
// 중앙값을 사용해야 해결 가능
#define Abs(x) ((x) < 0) ? (-(x)) : (x)

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int medium = nums[numsSize / 2], sum = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        sum += Abs(nums[i] - medium);
    }
    return sum;
}