#include <stdio.h>

int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    for(int i = 0; i < matSize; i++)
    {
        for(int j = 0; j < matSize; j++)
        {
            if(i == j)
            {
                sum = sum + mat[i][j];
            }
            else if(i + j == matSize - 1){
               sum += mat[i][j]; 
            }
        }
    }
    return sum;
}

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int mat[101][101];
//     for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d",&mat[i][j]);
//     int ans = diagonalSum(mat, n,&n);
//     printf("%d\n", ans);
//     return 0;
// }

/*
Best Solution
int diagonalSum(int** mat, int matSize, int* matColSize){
int sum=0;
for(int i=0;i<matSize;i++)
{
    for(int j=0;j<matSize;j++)
    {
        if(i==j)
        {
            sum=sum+mat[i][j];
        }
        else if(i+j==matSize-1){
           sum+=mat[i][j];
        }
    }
}
return sum;
}
*/