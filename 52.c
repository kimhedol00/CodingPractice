#include <stdio.h>

int c[10], d1[20], d2[20];
int count;

void f(int i, int n)
{
    if(i == n + 1) {count++; return;}
    for(int j = 1; j <= n; j++)
        if(!c[j] && !d1[i + j] && !d2[i - j + n])
        {
            c[j] = d1[i + j] = d2[i - j + n] = 1;
            f(i + 1, n);
            c[j] = d1[i + j] = d2[i - j + n] = 0;
        }
}

int totalNQueens(int n){
    count = 0;
    f(1, n);
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = totalNQueens(n);
    printf("%d\n", ans);
    return 0;
}