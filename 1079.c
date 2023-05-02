#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numTilePossibilities(char* tiles);

int dfs(int* cnt);


int numTilePossibilities(char* tiles) {
        int cnt[26] = {0, };
        for(int i = 0; i < strlen(tiles); ++i) ++cnt[tiles[i] - 'A'];
        return dfs(cnt);
    }

int dfs(int* cnt) {
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            res += dfs(cnt) + 1;
            cnt[i]++;
        }
    }
    return res;
}

int main()
{
    char line[10000];
    scanf("%s", line);
    int ans = numTilePossibilities(line);
    printf("%d\n", ans);

    return 0;
}

/*
Best Solution
int count;
int check[26];

void f(int i,int n){
    if(i==n){
        count++;
        return;
    }
    for(int j=0;j<26;j++){
        if(check[j]>0){
            count++;
            check[j]--;
            f(i+1,n);
            check[j]++;
        }
    }

}
int numTilePossibilities(char * tiles){
    count=0;
    for(int i=0;i<26;i++){
        check[i]=0;
    }
    for(int i=0;i<strlen(tiles);i++){
        int a = tiles[i]-'A';
        check[a]++;
    }
    f(1,strlen(tiles));
    return count;
}
*/