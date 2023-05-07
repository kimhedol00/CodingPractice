#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int temp[nums1Size + nums2Size];
    int x =0;
        for (int i = 0 ; i < nums1Size + nums2Size; i++){
            if (i < nums1Size)
               temp[i] = nums1[i];
            else
                temp[i] = nums2[x++];

        }
        for(int i = 0; i < nums1Size + nums2Size; i++){
            for(int j = i + 1; j < nums1Size + nums2Size; j++){
                if(temp[i] > temp[j]){
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }
        if ((nums1Size + nums2Size) % 2 == 0){
            int l = (nums1Size + nums2Size) / 2;
            return (temp[l] + temp[l - 1]) / 2.00;
        }
        else {
            return temp[(nums1Size + nums2Size) / 2];
        }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int n1[10001], n2[10001];
    for(int i = 0; i < n; ++i) scanf("%d", &n1[i]);
    for(int i = 0; i < m; ++i) scanf("%d", &n2[i]);
    double ans = findMedianSortedArrays(n1, n, n2, m);
    printf("%f\n", ans);
    return 0;
}

/*
Best Solution
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int newArray[nums1Size+nums2Size];
    int x=0,i=0,j=0;

    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            newArray[x]=nums1[i];
            i++;
        }else{
            newArray[x]=nums2[j];
            j++;
        }
        x++;
    }

    while(i<nums1Size){
        newArray[x]=nums1[i];
        i++;
        x++;
    }

    while(j<nums2Size){
        newArray[x]=nums2[j];
        j++;
        x++;
    }

    int l=(nums1Size+ nums2Size)/2;
    if((nums1Size+nums2Size)%2==0){
        return (newArray[l]+newArray[l-1])/2.00;
    }else{
        return newArray[l];
    }
}
*/