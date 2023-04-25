#include <stdio.h>

int lengthOfLongestSubstring(char * s){
    int check[128];
    int ans = 0;
    int left = 0;
    int len = strlen(s);
    for(int i = 0; i < 128; ++i) check[i] = 0;
    for(int right = 0; right < len; ++right)
    {
        while(check[s[right]] && left < right) check[s[left++]]--;
        check[s[right]]++;
        if(right - left + 1 > ans) ans = right - left + 1;
    }
    return ans;

    /*
    int check[128];
    int left = 0;
    int ans = 0;

    for(int i = 0; i < 128; ++i)
    {
        check[i] = 0;
    }

    for(int right = 0; right < strlen(s); ++right)
    {
        while(check[s[right]] && left < right) 
        {
            check[s[left++]]--;
        }
        check[s[right]]++;
        if(right - left + 1 > ans) ans = right - left + 1;
    }
    return ans;
    */
}