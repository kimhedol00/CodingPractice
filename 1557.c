#include <stdio.h>
#include <stdlib.h>

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int *ind = calloc(n, sizeof(int));
    int count = 0, i;
    for(i = 0; i < edgesSize; i++) {
        ind[edges[i][1]]++;
    }
    for(i = 0; i < n; i++) {
        if(ind[i] == 0){
            ind[count++] = i;
        } /*else {
            ind[i]=0;
        }*/
    }   
    *returnSize = count;
    return ind;
}

/*
Best Solution
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* indegree = calloc(n, sizeof(int));
    int i, j, count = 0;
    for (i = 0; i < edgesSize; i++) {
        indegree[edges[i][1]]++;
    }
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) count++;
    }
    int* res = malloc(count * sizeof(int));
    j = 0;
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            res[j++] = i;
        }
    }
    *returnSize = count;
    free(indegree);
    return res;
}
*/