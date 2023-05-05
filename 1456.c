#include <stdio.h>
#include <string.h>

int maxVowels(char * s, int k);

int main()
{
    char s[10001];
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    int ans = maxVowels(s, k);
    printf("%d\n", ans);
    return 0;
}

int maxVowels(char * s, int k){
    int left = 0, right = k - 1;
    int len = strlen(s);
    int cur = 0, max = 0;
    for(int j = left; j <= right; ++j)
    {
        if(s[j] == 'a'|| s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i')
        {
            cur++;
        }
    }
    max = cur;
    while (right < len - 1)
    {
        right++;
        if(s[right] == 'a' || s[right] == 'e' || s[right] == 'o' || s[right] == 'u' || s[right] == 'i') cur++;
        if(s[left] == 'a' || s[left] == 'e' || s[left] == 'o' || s[left] == 'u' || s[left] == 'i') cur--;
        left++;
        max = max > cur ? max : cur;
    }
    return max;
}

/*
Best Solution
//                        a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
const int is_vowel[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};

int maxVowels(char * s, int k)
{
    int vowel_count = 0;
    int ii;
    for (ii = 0; ii < k; ii++)
    {
        vowel_count += is_vowel[s[ii] - 'a'];
    }
    int max_vowel_count = vowel_count;

    for (; s[ii]; ii++)
    {
        vowel_count -= is_vowel[s[ii - k] - 'a'];
        vowel_count += is_vowel[s[ii] - 'a'];
        if (vowel_count > max_vowel_count)
        {
            max_vowel_count = vowel_count;
        }
    }

    return max_vowel_count;
}
*/