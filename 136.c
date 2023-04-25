#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int n = nums[0];
    for(int i = 1; i < numsSize; ++i) 
    {
        n ^= nums[i];
    }
    return n;
}