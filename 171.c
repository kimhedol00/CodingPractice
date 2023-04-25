#include <stdio.h>

int titleToNumber(char * columnTitle){
    int sum = 0;
    for(int i = 0; i < strlen(columnTitle); ++i)
    {
        sum = ((sum * 26) + ((int)columnTitle[i] - 64 ));
    }
    return sum;
}