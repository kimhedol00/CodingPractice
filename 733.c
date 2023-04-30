#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void f(int x, int y, int n, int m, int**image, int color, int newColor)
{
    image[x][y] = newColor;
    if(y + 1 < m && image[x][y + 1] == color) f(x, y + 1, n, m, image, color, newColor);
    if(x + 1 < n && image[x + 1][y] == color) f(x + 1, y, n, m, image, color, newColor);
    if(y - 1 >= 0 && image[x][y - 1] == color) f(x, y - 1, n, m, image, color, newColor);
    if(x - 1 >= 0 && image[x - 1][y] == color) f(x - 1, y, n, m, image, color, newColor);
}

void _f(int x, int y, int n, int m, int**image, int color, int newColor)
{
    if(image[x][y] == color)
    {
        image[x][y] = newColor;
        if(y + 1 < m) f(x, y + 1, n, m, image, color, newColor);
        if(x + 1 < n) f(x + 1, y, n, m, image, color, newColor);
        if(y - 1 >= 0) f(x, y - 1, n, m, image, color, newColor);
        if(x - 1 >= 0) f(x - 1, y, n, m, image, color, newColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int n = imageSize;
    int m = imageColSize[0];

    if(image[sr][sc] != newColor) f(sr, sc, n, m, image, image[sr][sc], newColor);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}


/*
Best Solution

void fill_recursive(int **og_img, int **new_img, int img_size, int col_size, int y, int x, int og_color, int new_color);

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    int col_size = *imageColSize;
    int **new_img = (int**)malloc(imageSize * sizeof(int*));
    int *col_sizes = (int*)malloc(imageSize * sizeof(int));

    for (int ii = 0; ii < imageSize; ii++)
    {
        new_img[ii] = (int*)malloc(col_size * sizeof(int));
        for (int jj = 0; jj < col_size; jj++)
        {
            new_img[ii][jj] = -1;
        }
        col_sizes[ii] = col_size;
    }

    fill_recursive(image, new_img, imageSize, col_size, sr, sc, image[sr][sc], color);

    for (int ii = 0; ii < imageSize; ii++)
    {
        for (int jj = 0; jj < col_size; jj++)
        {
            if (new_img[ii][jj] == -1)
            {
                new_img[ii][jj] = image[ii][jj];
            }
        }
    }

    *returnColumnSizes = col_sizes;
    *returnSize = imageSize;

    return new_img;
}

void fill_recursive(int **og_img, int **new_img, int img_size, int col_size, int y, int x, int og_color, int new_color)
{
    if (og_img[y][x] != og_color)
    {
        return;
    }

    new_img[y][x] = new_color;

    y--;
    if  ( (y >= 0) && (new_img[y][x] == -1) )
    {
        fill_recursive(og_img, new_img, img_size, col_size, y, x, og_color, new_color);
    }

    y += 2;
    if  ( (y < img_size) && (new_img[y][x] == -1) )
    {
        fill_recursive(og_img, new_img, img_size, col_size, y, x, og_color, new_color);
    }

    y--;
    x--;
    if  ( (x >= 0) && (new_img[y][x] == -1) )
    {
        fill_recursive(og_img, new_img, img_size, col_size, y, x, og_color, new_color);
    }

    x += 2;
    if  ( (x < col_size) && (new_img[y][x] == -1) )
    {
        fill_recursive(og_img, new_img, img_size, col_size, y, x, og_color, new_color);
    }
}


*/