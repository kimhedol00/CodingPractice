#include <stdio.h>

//거듭제곱을 log n만에 구하는 방법을 사용

#define MOD 1000000007

int fastpow(long long base, long long exp)
{
    int result = 1;
    for( ; ; )
    {
        if(exp & 1) result = result * base % MOD;
        exp >>= 1;
        if(!exp) break;
        base = base * base % MOD;
    }
    return result;
}
int countGoodNumbers(long long n)
{
    return (long long)fastpow(5, (n + 1) / 2) * fastpow(4, n - (n + 1) / 2) % MOD;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = countGoodNumbers(n);
    printf("%d\n", ans);
    return 0;   
}