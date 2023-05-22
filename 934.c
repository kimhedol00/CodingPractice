#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode
{
  int row;
  int col;
  struct QueuenNode* next;
}Qnode;

void dfs(int** grid, int rowSize, int colSize, int row, int col, int** set, Qnode** head, Qnode** tail, int* length)
{
  if(row < 0 || col < 0 || row == rowSize || col == colSize)
    return;
  if(!grid[row][col])
    return;
  if(set[row][col])
    return;
  set[row][col] = 1;
  Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
  temp->row = row;
  temp->col = col;
  temp->next = NULL;
  if(!(*(length)))
    (*head) = (*tail) = temp;
  else
  {
    (*tail)->next = temp;
    (*tail) = temp;
  }
  (*(length))++;
  dfs(grid, rowSize, colSize, row - 1, col, set, head, tail, length);
  dfs(grid, rowSize, colSize, row + 1, col, set, head, tail, length);
  dfs(grid, rowSize, colSize, row, col - 1, set, head, tail, length);
  dfs(grid, rowSize, colSize, row, col + 1, set, head, tail, length);
  return;
}



int shortestBridge(int** grid, int gridSize, int* gridColSize)
{
  int rowSize = gridSize;
  int colSize = *gridColSize;
  int** set = (int**)malloc(rowSize * sizeof(int*));
  for(int i = 0; i < rowSize; i++)
    set[i] = (int*)calloc(colSize, sizeof(int));
  int curr_step_reach = 0;
  int next_step_reach = 0;
  int* length = &curr_step_reach;
  Qnode* Qhead = NULL;
  Qnode* Qtail = Qhead;
  Qnode** head = &Qhead;
  Qnode** tail = &Qtail;
  bool found = false;
  for(int i = 0;i < rowSize;i++)
  {
    for(int j = 0;j < colSize;j++)
    {
      if(grid[i][j])
      {
        dfs(grid, rowSize, colSize, i, j, set, head, tail, length);
        found = true;
        break;
      }
    }
    if(found)
      break;
  }
  int bridge = 0;
  int directions[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
  while(Qhead && Qtail)
  {
    for(int i = 0; i < curr_step_reach; i++)
    {
      int row = Qhead->row;
      int col = Qhead->col;
      for(int j = 0; j < 4; j++)
      {
        int n_row = row + directions[j][0];
        int n_col = col + directions[j][1];
        if(n_row < 0 || n_col < 0 || n_row == rowSize || n_col == colSize)
          continue;
        if(set[n_row][n_col])
          continue;
        if(grid[n_row][n_col])
          return bridge;
        set[n_row][n_col] = 1;
        Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
        temp->row = n_row;
        temp->col = n_col;
        temp->next = NULL;
        Qtail->next = temp;
        Qtail = temp;
        next_step_reach++;
      }
      Qhead = Qhead->next;
    }
    bridge++;
    curr_step_reach = next_step_reach;
    next_step_reach = 0;
  }
  return bridge;
}

/*
Best Solution
typedef struct QueueNode
{
  int row;
  int col;
  struct QueuenNode* next;
}Qnode;

void dfs(int** grid, int rowSize, int colSize, int row, int col, int** set, Qnode** head, Qnode** tail, int* length)
{
  if(row < 0 || col < 0 || row == rowSize || col == colSize)
    return;
  if(!grid[row][col])
    return;
  if(set[row][col])
    return;
  set[row][col] = 1;
  Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
  temp->row = row;
  temp->col = col;
  temp->next = NULL;
  if(!(*(length)))
    (*head) = (*tail) = temp;
  else
  {
    (*tail)->next = temp;
    (*tail) = temp;
  }
  (*(length))++;
  dfs(grid, rowSize, colSize, row - 1, col, set, head, tail, length);
  dfs(grid, rowSize, colSize, row + 1, col, set, head, tail, length);
  dfs(grid, rowSize, colSize, row, col - 1, set, head, tail, length);
  dfs(grid, rowSize, colSize, row, col + 1, set, head, tail, length);
  return;
}



int shortestBridge(int** grid, int gridSize, int* gridColSize)
{
  int rowSize = gridSize;
  int colSize = *gridColSize;
  int** set = (int**)malloc(rowSize * sizeof(int*));
  for(int i = 0; i < rowSize; i++)
    set[i] = (int*)calloc(colSize, sizeof(int));
  int curr_step_reach = 0;
  int next_step_reach = 0;
  int* length = &curr_step_reach;
  Qnode* Qhead = NULL;
  Qnode* Qtail = Qhead;
  Qnode** head = &Qhead;
  Qnode** tail = &Qtail;
  bool found = false;
  for(int i = 0;i < rowSize;i++)
  {
    for(int j = 0;j < colSize;j++)
    {
      if(grid[i][j])
      {
        dfs(grid, rowSize, colSize, i, j, set, head, tail, length);
        found = true;
        break;
      }
    }
    if(found)
      break;
  }
  int bridge = 0;
  int directions[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
  while(Qhead && Qtail)
  {
    for(int i = 0;i < curr_step_reach;i++)
    {
      int row = Qhead->row;
      int col = Qhead->col;
      for(int j = 0; j < 4;j++)
      {
        int n_row = row + directions[j][0];
        int n_col = col + directions[j][1];
        if(n_row < 0 || n_col < 0 || n_row == rowSize || n_col == colSize)
          continue;
        if(set[n_row][n_col])
          continue;
        if(grid[n_row][n_col])
          return bridge;
        set[n_row][n_col] = 1;
        Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
        temp->row = n_row;
        temp->col = n_col;
        temp->next = NULL;
        Qtail->next = temp;
        Qtail = temp;
        next_step_reach++;
      }
      Qhead = Qhead->next;
    }
    bridge++;
    curr_step_reach = next_step_reach;
    next_step_reach = 0;
  }
  return bridge;
}
*/