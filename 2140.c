#include <stdio.h>

long long max(long long a, long long b) {return (long long)a > b ? a : b;}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize){
    long long dp[200001] = {};
    for (int i = questionsSize - 1; i >= 0; --i)
        dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
    return dp[0];
}

/*
Best Solution
#include <stdlib.h>

long long mostPoints(int** questions, int questionsSize, int* questionsColSize){
    long long *dp = (long long*)malloc((questionsSize+1)*sizeof(long long));
    for (int i = questionsSize-1; i >= 0; --i) {
        dp[i] = (dp[i+1] > (questions[i][0] + ((i+1+questions[i][1] < questionsSize) ? dp[i+1+questions[i][1]] : 0))) ? dp[i+1] : (questions[i][0] + ((i+1+questions[i][1] < questionsSize) ? dp[i+1+questions[i][1]] : 0));
    }
    long long res = dp[0];
    free(dp);
    return res;
}
*/