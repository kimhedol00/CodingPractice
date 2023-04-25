#include <stdio.h>

//n개 다 만들어서 해보는 방법 있고 나머지 이용하는 방법 있음

int count = 0;
int used[10];
char str[10];

int perm(int n, int k, int i)
{
    if(i == n)
    {
        count++;
        if(count == k) return 1;
        return 0;
    }

    for(int j = 1; j <= n; ++j)
    {
        if(!used[j])
        {
            used[j] = 1;
            str[i] = j + '0';

            int ret = perm(n, k, i + 1);
            if(ret) return 1;
            used[j] = 0;
        }
    }
    return 0;
}

char * getPermutation(int n, int k){
    for(int i = 1; i <= n; ++i) used[i] = 0;
    count = 0;
    perm(n, k, 0);
    str[n] = 0;
    return str;
}


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char* ans;
    ans = getPermutation(n, k);

    printf("%s\n", ans);

    return 0;   
}