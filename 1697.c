#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int* root;
int** qcopy;

int find(int x) {
    if(x==root[x])
        return x;
    else
        return root[x] = find(root[x]);
}

int cmp(void const* a, void const* b) {
    return (*(int**)a)[2] - (*(int**)b)[2];
}

int cmp2(void const* a, void const* b) {
    return qcopy[*(int*)a][2] - qcopy[*(int*)b][2];
}

bool* distanceLimitedPathsExist(int n, int** edgeList, int edgeListSize, int* edgeListColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    int i;
    //init union set
    root = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        root[i] = i;
    //init answer array
    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);

    int idx[queriesSize];//index of queries
    for (i = 0; i < queriesSize; ++i)
        idx[i] = i;

    qcopy = queries;
    qsort(idx, queriesSize, sizeof(int), cmp2);//sort the index base on the queries limit length
    qsort(edgeList, edgeListSize, sizeof(int*), cmp); //sort by edge distance
    
    int j=0;
    for (i = 0; i < queriesSize; ++i) {
        int curr = idx[i];//current queries index in sorted queries
        int len = queries[curr][2];//limit length
        
        //update union set when distance less than limit 
        while(j < edgeListSize && edgeList[j][2] < len){
            int a = find(edgeList[j][0]);
            int b = find(edgeList[j][1]);
            root[b] = a;
            j++;
        }

        //check if nodes has same root
        if (find(queries[curr][0]) == find(queries[curr][1]))
            ans[curr] = 1;
        else 
            ans[curr] = 0;
    }

    return ans;
}

