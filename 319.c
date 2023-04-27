#include <stdio.h>


int bulbSwitch(int n){
    int ans = 1;
    while(ans * ans <= n) ans++;
    return ans - 1;
}

/*
int bulbSwitch(int n){
    return sqrt(n);
}
*/


int main()
{
    int n;
    scanf("%d", &n);
    int ans = bulbSwitch(n);
    printf("%d\n", ans);
    return 0;
}