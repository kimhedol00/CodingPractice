#include <stdio.h>

//요세푸스 점화식
//원탁의 기사들

int f(int n, int k)
{
    if(n == 1) return 0;
    return (k + f(n - 1, k)) % n;
}

int findTheWinner(int n, int k){
    return f(n, k) + 1;
}


int main()
{
    int n, i;
    scanf("%d %d", &n, &i);
    int ans = findTheWinner(n, i);
    printf("%d\n", ans);

    return 0;   
}