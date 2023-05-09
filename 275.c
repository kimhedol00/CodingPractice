#include <stdio.h>

/*
int hIndex(int* citations, int citationsSize){
    for(int i = 0; i < citationsSize; ++i) if(citations[i] >= citationsSize - i) return citationsSize - 1;
    return 0;
}
*/

//위의 코드는 O(n)의 시간복잡도
//Binary Seacrh를 쓰면 O(log n)으로 해결 가능
int binary_search(int arr[], int l, int r, int n)
{
    int ans = 0;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= n - mid)
        {
            ans = n - mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
int hIndex(int* citations, int citationsSize)
{
    return binary_search(citations, 0, citationsSize - 1, citationsSize);
}


/*
Best Solution
int hIndex(int* citations, int citationsSize){
    for (int i = citationsSize ; i > 0 ; i--){
        if (citations[i-1] < citationsSize-i+1) return citationsSize-i;
    }
    return citationsSize;
}
*/