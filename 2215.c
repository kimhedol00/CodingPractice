#include <stdio.h>
#include <stdlib.h>

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    int* hash = (int*)calloc(2001, sizeof(int));
    int** ans = (int**)malloc(sizeof(int*) * 2);
    ans[0] = (int*)calloc(nums1Size, sizeof(int));
    ans[1] = (int*)calloc(nums2Size, sizeof(int));
    
    for(int i = 0; i < nums2Size; ++i)
        hash[nums2[i]+1000] = 1;
    
    for(int i = 0; i < nums1Size; ++i)
    {
        if(hash[nums1[i] + 1000] > 0)
            hash[nums1[i] + 1000]++;
        else
            hash[nums1[i] + 1000] = -1;
    }
    int* col = (int*)calloc(2, sizeof(int));
    for(int i = -1000; i <= 1000; i++)
    {
        if(hash[i+1000] == -1)
            ans[0][col[0]++] = i;
        else if(hash[i+1000] == 1)
            ans[1][col[1]++] = i;
    }
    
    *returnSize = 2;
    *returnColumnSizes = col;
    return ans;
}

int main()
{
    int nums1[1001];
    int nums2[1001];
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    for(int i = 0; i < n1; ++i) scanf("%d", &nums1[i]);
    for(int i = 0; i < n2; ++i) scanf("%d", &nums2[i]);
    //2차원배열을 returnSize와 returnColumnSizes로 반환하는 것을 이해 못함
    return 0;
}