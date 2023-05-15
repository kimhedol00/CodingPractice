#include <stdio.h>
#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int i = 0,j = 0;
    int top = 0;
    int k = 0;
    int *arr=(int*)malloc(pushedSize * (sizeof(int)));
    for(i = 0; i < pushedSize; i++)
    {
        arr[top]=pushed[i];
        while(top >= 0 && j < pushedSize && popped[j] == arr[top])
        {
            top--;
            j++;
        }
        top++;
    }
    if(top == 0) return 1;
    return 0;
}

/*
Best Solution
Using Stack

typedef struct
{
    int index;
    int *arr;    
}STACK;

STACK* init_stack(int n)
{
    STACK *s = malloc(sizeof(STACK));
    s->index = 0;
    s->arr = calloc(n, sizeof(int));
    return s;
}

void push_stack(int val, STACK* s)
{
    s->arr[s->index++] = val;
}

void pop_stack(STACK* s)
{
    s->index--;
}

bool is_empty_stack(STACK* s)
{
    return s->index == 0;
}

void free_stack(STACK* s)
{
    free(s->arr);
    free(s);
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if(!memcmp(pushed, popped, pushedSize*sizeof(int)))
        return true;
    STACK *s = init_stack(pushedSize);
    
    int popped_index = 0;
    for(int i = 0; i< pushedSize; i++)
    {
        while(s->index > 0 && s->arr[s->index-1] == popped[popped_index])
        { 
            pop_stack(s);
            popped_index++;
        }
        if(pushed[i] != popped[popped_index])
            push_stack(pushed[i], s);
        else
            popped_index++;
    }

    for(int i = popped_index; i< poppedSize; i++)
    {
        if(popped[i] == s->arr[s->index-1])
            pop_stack(s);
    }

    bool b = is_empty_stack(s);
    free_stack(s);
    return b;
}
*/