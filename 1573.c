#include <stdio.h>
#include <string.h>

char s[10001];
int d[10001];
int main()
{
    int num;
    scanf("%s", s);
    num = strlen(s);
    int iszero = 0;
    if(s[0] == '1') d[0] = 1;
    else d[0] = 0;
    for(int i = 1; i < num; ++i)
    {
        if(s[i] == '0') d[i] = d[i - 1];
        else {d[i] = d[i - 1] + 1; iszero++;}
    }
    if(d[num - 1] % 3 != 0) { printf("0"); return 0;}

    int left = 0;
    int right = 0;
    int onenum = d[num - 1] / 3;
    if(!iszero) {printf("%ld", ((long)(num - 1) * (num - 2) / 2) % 1000000007); return 0;}
    for(int i = 0; i < num; ++i)
    {
        if(d[i] == onenum) left++;
        else if(d[i] == onenum * 2) right++;
    }
    printf("%ld", (long)right * left % 1000000007);



    return 0;
}
/*
    int num = strlen(s);
    int* d = (int*)malloc(sizeof(int) * num);
    int right = 0;
    int left = 0;
    int iszero = 0;
    int onenum = 0;

    if(s[0] == '1') d[0] = 1;
    else d[0] = 0;

    for(int i = 1; i < num; ++i)
    {
        if(s[i] == '0') d[i] = d[i - 1];
        else
        {
            d[i] = d[i - 1] + 1;
            iszero++;
        }
    }
    onenum = d[num - 1];
    if(!iszero) return ((long)(num - 1) * (num - 2) / 2 % 1000000007);
    if(onenum % 3 != 0) return 0;
    onenum /= 3;

    for(int i = 0; i < num; ++i)
    {
        if(d[i] == onenum) left++;
        else if(d[i] == onenum * 2) right++;
    }

    free(d);

    return ((long)(left) * right) % 1000000007;
*/