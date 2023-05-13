#include <stdio.h>

int countGoodStrings(int low, int high, int zero, int one) {
    const int MOD = 1000000007;
    int DP[high + 1];
    int 
    ans = 0;
    DP[0] = 1;
    for(int i = 1; i <= high; i++) {
        DP[i] = ((i >= zero ? DP[i - zero] : 0) + (i >= one ? DP[i - one] : 0)) % MOD;
        if(i >= low && i <= high)
            ans = (ans + DP[i]) % MOD;
    }
    return ans;
}

/*
Best Solution
int countGoodStrings(int low, int high, int zero, int one){
    long long ans[high + 1];
    ans[0] = 1;
    int append0, append1, mod = 1000000007;
    for(int i = 1;i <= high;i++){
        append0 = i >= zero ? ans[i - zero] : 0;
        append1 = i >= one ? ans[i - one] : 0;
        ans[i] = append0 + append1;
        ans[i] %= mod;
    }long long ret = 0;
    for(int i = low;i <= high;i++){
        ret += ans[i];
        ret %= mod;
    }return ret;

}
*/