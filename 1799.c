#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int dp[(1<<14)+10];
int* nums;

int max(int a, int b)
{
    return a > b ? a : b;
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

//funtion to return ans
int solve(int mask,int len,int op){
    if(mask == 0) return 0;
    
    if(dp[mask] != -1) return dp[mask];
    int ans = INT_MIN;
    for(int i = 0; i < len - 1; i++){//We dont know which pair to select so for each pair, run a nested loop
	
        if(mask & (1 << i)){//to make sure number at ith pos is available and not used previously
		
            int maskval = mask^(1 << i);
            for(int j = i + 1; j < len; j++){
			
                if(mask & (1 << j)){//Same logic
				
                    int maskval1=maskval^(1<<j);
                    ans = max(ans, (gcd(nums[i], nums[j]) * (op)) + (solve(maskval1, len, op + 1)));
                }
            }
        }
    }
    return dp[mask]=ans;
    
}

int maxScore(int* num, int numsSize) {
    nums = num;
    memset(dp, -1, sizeof(dp));
    int len = numsSize;
    int mask= ((1 << len) - 1);
    return solve(mask, len, 1);
}