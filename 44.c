#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isMatch(char * s, char * p){
    int i = 0;
    int j = 0;
    int match = 0;
    int star = -1;
    while(i < strlen(s))
    {
        if(j < strlen(p) && (p[j] == '?' || s[i] == p[j]))
        {
            i++;
            j++;
        }
        else if(j < strlen(p) && p[j] == '*')
        {
            star = j;
            match = i;
            j++;
        }
        else if(star != -1)
        {
            j = star + 1;
            i = ++match;
        }
        else
        {
            return false;
        }
    }
    while(j < strlen(p) && p[j] == '*')
    {
        j++;
    }
    return j == strlen(p);
}

int main()
{
    char s[2001], p[2001];
    scanf("%s", s);
    scanf("%s", p);
    bool ans = isMatch(s, p);
    printf("%d", ans);
    return 0;
}