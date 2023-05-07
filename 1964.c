#include <stdio.h>
#include <stdlib.h>


//LIS문제 + BST

int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize) {
    int* dp = (int*)malloc(obstaclesSize * sizeof(int));
    int* res = (int*)malloc(obstaclesSize * sizeof(int));
    int len = 0;
    
    for (int i = 0; i < obstaclesSize; i++) {
        int num = obstacles[i];
        int left = 0, right = len;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (dp[mid] <= num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        dp[left] = num;
        res[i] = left + 1;
        
        if (left == len) {
            len++;
        }
    }
    
    *returnSize = obstaclesSize;
    free(dp);
    return res;
}

int main() 
{
    // Example usage
    int obstacles[] = {3, 1, 5, 6, 4, 2};
    int obstaclesSize = sizeof(obstacles) / sizeof(obstacles[0]);
    int returnSize;
    int* result = longestObstacleCourseAtEachPosition(obstacles, obstaclesSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}