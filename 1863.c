#include <stdio.h>

//재귀호출 없이도 풀어보기

int mask[14];

int generate_subset(int* nums, int numsSize, int i)
{
    if(i == numsSize)
    {
        int xor = 0;
        for(int j = 0; j < numsSize; ++j) xor ^= mask[j] ? nums[j] : 0;
        return xor;
    }

    mask[i] = 0;
    int total1 = generate_subset(nums, numsSize, i + 1);
    mask[i] = 1;
    int total2 = generate_subset(nums, numsSize, i + 1);

    return total1 + total2;
}

int subsetXORSum(int* nums, int numsSize){
    return generate_subset(nums, numsSize, 0);
}

int main()
{
    int numsSize;
    int nums[14];

    scanf("%d", &numsSize);
    for(int i = 0; i < numsSize; ++i) scanf("%d", &nums[i]);
    int ans = subsetXORSum(nums, numsSize);
    printf("%d\n", ans);
    return 0;   
}

/*
int subsetXORSum(int* nums, int numsSize)
{
    int ans = 0;
    for(int i = 0; i < numsSizel ++i)
    {
        ans |= nums[i];
    }
    return ans << (numsSize - 1);
}
*/