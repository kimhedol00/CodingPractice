#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int f = 0, element;
    for (int i = 0; i < numsSize; ++i)
    {
        if(!f)
        {
            element = nums[i];
        }
        if(element == nums[i])
        {
            f++;
        }
        else
        {
            f--;
        }
    }
    return element;
}