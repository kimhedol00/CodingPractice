#include <stdio.h>

int max(int a, int b) {
    return a + (b - a) * (b > a);
}

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i, j, dp[nums1Size + 1][nums2Size + 1];
    for (i = 0; i <= nums1Size; ++i) {
        dp[i][0] = 0;
    }
    for (i = 0; i <= nums2Size; ++i) {
        dp[0][i] = 0;
    }
    for (i = 1; i <= nums1Size; ++i) {
        for (j = 1; j <= nums2Size; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[nums1Size][nums2Size];
}
