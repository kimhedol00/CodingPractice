#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;
    int* res = malloc(*returnSize * sizeof(int)), k = 0;
    --matrixSize;
    --*matrixColSize;
        
    for(short direction = 0, i = 0, j = -1, up = 0, left = 0; up <= matrixSize && left <= *matrixColSize; direction = (direction + 1) % 4)
        switch (direction) {
            case 0: // left to right
                for(++j; j <= *matrixColSize; ++j) res[k++] = matrix[i][j];
                --j;
                ++up;
                break;
            
            case 1: // top to bottom
                for(++i; i <= matrixSize; ++i) res[k++] = matrix[i][j];
                --i;
                --*matrixColSize;
                break;
                
            case 2: // right to left
                for(--j; j >= left; --j) res[k++] = matrix[i][j];
                ++j;
                --matrixSize;
                break;
                
            case 3: // bottom to top
                for(--i; i >= up; --i) res[k++] = matrix[i][j];
                ++i;
                ++left;
        }
    
    return res;
}








/*
Best Solution

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,int* returnSize){

if(matrixSize==0) {
*returnSize=0;
return NULL;
}

int count=0;
int* a;
int up=0,down=matrixSize-1;
int left=0,right=*matrixColSize-1;


a=(int *)malloc(sizeof(int)*matrixSize*(*matrixColSize));

while((up<=down)||(left<=right)){
if(up<=down){
    for(int i=left;i<=right;i++){
        a[count++]=matrix[up][i];
}
up++;
}

if(left<=right){
    for(int i=up;i<=down;i++){
        a[count++]=matrix[i][right];
    }
    right--;
}

if(up<=down){
    for(int i=right;i>=left;i--){
        a[count++]=matrix[down][i];
    }
    down--;
}

if(left<=right){
     for(int i=down;i>=up;i--){
         a[count++]=matrix[i][left];
     }

    left++;
}
}
*returnSize=count;
return a;


}
*/