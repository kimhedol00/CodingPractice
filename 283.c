#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int numPos = 0;
    for(int i = 0; i < numsSize ; i++) 
    {
        if(nums[i])
        {
            nums[numPos] = nums[i];
            if(numPos != i)
                nums[i] = 0;
            numPos++; 
        }
    
    }
}