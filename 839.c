#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numSimilarGroups(char** strs, int strsSize);
int findParent(int* parent, int node);
int merge(int* parent, int node1, int node2);
int isSimilar(char* s1, char* s2);

int main()
{
    int strsSize;
    char* words;
    scanf("%d", &strsSize);
    char** strs = (char**)malloc(sizeof(char*) * strsSize);
    words = (char*)malloc(sizeof(char) * 301);
    for(int i = 0; i < strsSize; ++i) strs[i] = (char*)malloc(sizeof(char) * 301);
    for(int i = 0; i < strsSize; ++i)
    {
        scanf("%s", words);
        strcpy(strs[i], words);
    }
    int ans = numSimilarGroups(strs, strsSize);
    printf("%d\n", ans);
    return 0;
}

int findParent(int* parent, int node)
{
    if (parent[node] == node) return node;
    else return findParent(parent, parent[node]);
}

int merge(int* parent, int node1, int node2)
{
    int parent1 = findParent(parent, node1);
    int parent2 = findParent(parent, node2);
    if (parent1 == parent2) return 0;
    
    parent[parent1] = parent2; //or parent[parent2] = parent1; 
    return 1;
}

int isSimilar(char* s1, char* s2)
{
    int n = strlen(s1);
    int different = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i]) different++;
    }
    return(different == 0 || different == 2);
}

int numSimilarGroups(char** strs, int n) 
{
    int* parent = (int*)malloc(sizeof(int) * n);
    int componentCount = n;
    for (int i = 0; i < n; i++) {parent[i] = i;}
    //==================================================================
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSimilar(strs[i], strs[j]))
            {
                int hasMerged = merge(parent, i, j);
                if (hasMerged) componentCount--;
            }
        }
    }
    //=========================================================================
    free(parent);
    return componentCount;
}



//Best Sol
/*
bool isSimilar (char* s1, char* s2)
{
    int diff = 0;
    
    for(int i=0;s1[i];i++) {
        if( s1[i] != s2[i] ) diff++;
        if( diff > 2 ) return false;
    }
    return true;
}

void dfs(char ** strs, int strsSize, char* src,  bool* visited )
{    
    for(int i=0;i<strsSize;i++) 
    {
        if(!visited[i] && isSimilar(strs[i],src)==true)
        {
            visited[i] = true;
            dfs(strs, strsSize, strs[i], visited);
        }
    }
}

int numSimilarGroups(char ** strs, int strsSize)
{
    int cnt =0;
    bool* visited = calloc(strsSize, sizeof(bool));
    
    for(int i=0;i<strsSize;i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        cnt++;
        dfs(strs, strsSize, strs[i], visited);
    }
    
    return cnt;
}
*/