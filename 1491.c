#include <stdio.h>

double average(int* salary, int salarySize){
    int max  = 1000;
    int min = 1000000;
    double ans = 0;
    for(int i = 0; i < salarySize; ++i)
    {
        max = max > salary[i] ? max : salary[i];
        min = min < salary[i] ? min : salary[i];
        ans += salary[i];
    }
    ans = (ans - max - min) / (double)(salarySize - 2);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int salary[101];
    for(int i = 0; i < n; ++i) scanf("%d", &salary[i]);
    double ans = average(salary, n);
    printf("%f", ans);
    return 0;
}