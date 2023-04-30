#include <stdio.h>

//Union Find

// The idea is to connect type 3 vertices first, without forming any cycle. Then again do the same for type 1, and type 2. 
	
int par[100001];
    
int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
    
void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    par[a]=b;
}
    
int isValid(int type, int** edges, int edgesSize, int* edgesColSize){
    int c = 0;
    int m = edgesSize;
    for(int i = 0;i < m; i++){
        if(edges[i][0]==type && find(edges[i][1]) != find(edges[i][2])){
            c++;
            merge(edges[i][1], edges[i][2]);
        }
    }
    return c;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    int m = edgesSize;
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    int p[100001];
    int t3 = isValid(3, edges, m, edgesColSize);
    for(int i = 0; i <= n; ++i) p[i] = par[i];
    int t1 = isValid(1, edges, m, edgesColSize);
    for(int i = 0; i <= n; ++i) par[i] = p[i];
    int t2 = isValid(2, edges, m, edgesColSize);
    if(t1 + t3 != n - 1 || t2 + t3 != n - 1)
        return -1;
    return m - t1 - t2 - t3;
}