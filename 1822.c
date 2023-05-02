#include <stdio.h>

int arraySign(int* nums, int numsSize);

int main()
{
    int n;
    scanf("%d", &n);
    int nums[1001];
    for(int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    int ans = arraySign(nums, n);
    printf("%d\n", ans);
    return 0;
}

int arraySign(int* nums, int numsSize){
    int pos = 1;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == 0) return 0;
        if(nums[i] < 0) pos *= -1;
    }
    return pos;
}
/*
Best Solution
int arraySign(int* nums, int numsSize)
{
    int countNegatives = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0) return 0; // Product is 0

        if (nums[i] < 0) countNegatives++; // Increment count of negatives
    }

    return (countNegatives % 2) == 0 ? 1 : -1; // True: Positive, False: Negative
}
*/