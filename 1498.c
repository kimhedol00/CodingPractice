#include <stdio.h>

int cmp(const void *p1, const void *p2) {
    return (*(int *)p1 - *(int *)p2);
}

int numSubseq(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);

    int i1 = 0, i2 = numsSize - 1, all = numsSize - 1, cur = 1, ans = 0;
    // every loop: nums[i1] will be a part of each answer
    while (all) {
        cur = (cur * 2) % 1000000007;
        all --;
    }
    while (i2 >= i1) {
        if (nums[i1] + nums[i2] <= target) {
            all = i2 - i1;
            ans = (ans + cur) % 1000000007;
            i1 ++;
            cur = (cur & 1)? (cur + 1000000007) / 2 : cur / 2;
        }
        else {
            i2 --;
            cur = (cur & 1)? (cur + 1000000007) / 2 : cur / 2;
        }
    }

    return ans;
}

int main()
{
    int num[10001];
    int n;
    int t;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scnaf("%d", &num[i]);
    scanf("%d", &t);
    int ans = numSubseq(num, n, t);
    printf("%d\n", ans);
    return 0;
}

/*
Best Solution
#define MODULUS 1000000007

int twoPowers(int p) {
    // printf("... %d\n", p);
    int ret = 1;
    long long x = 2;
    while (p) {
        if (p & 1) ret = (ret * x) % MODULUS;
        p >>= 1;
        x = (x * x) % MODULUS;
    }
    return ret;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int numSubseq(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int left = 0, right = numsSize - 1, ret = 0;
    while (left <= right) {
        if (nums[left] + nums[right] > target) right--;
        else ret = (ret + twoPowers(right - left++)) % MODULUS;
    }
    //printf("%d\n", twoPowers(5));
    return ret;
}
*/