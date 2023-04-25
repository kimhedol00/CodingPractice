#include <stdio.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize){
    int max_sum = INT_MIN, sum = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        if(sum > 0) sum += nums[i];
        else sum = nums[i];
        max_sum = sum > max_sum ? sum : max_sum;
    }
    return max_sum;
}