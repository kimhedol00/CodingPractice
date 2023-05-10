#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int left = 0, right = n - 1, up = 0, down = n - 1, count = 1;
    while(left <= right && up <= down)
    {
        for(int i = left; i <= right; i++) //left to right
            result[up][i] = count++;
        for(int i = up + 1; i <= down; i++) //up to down
            result[i][right] = count++; 
        for(int i = right - 1; i > left && up != down; i--) //right to left
            result[down][i] = count++;
        for(int i = down; i > up && left != right; i--) //down to up
            result[i][left] = count++;
        up++; down--; left++; right--;
    }
    return result;
}

/*
Best Solution
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    
    
    
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    
    // Initialize variables
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;
    int num = 1;
    
    
    // Generate the matrix in spiral order
    while (row_start <= row_end && col_start <= col_end) {
        
        // Traverse right
        for (int j = col_start; j <= col_end; j++) {
            matrix[row_start][j] = num++;
        }
        row_start++;
        
        // Traverse down
        for (int i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = num++;
        }
        col_end--;
        
        // Traverse left
        if (row_start <= row_end) {
            for (int j = col_end; j >= col_start; j--) {
                matrix[row_end][j] = num++;
            }
            row_end--;
        }
        
        // Traverse up
        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = num++;
            }
            col_start++;
        }
    }
    
    // Set return values
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    return matrix;
}
*/