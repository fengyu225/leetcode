#include "header.h"

int firstMissingPositive(int A[], int n) {
    int min_negative = -1;
    for(int i=0; i<n; i++)
        min_negative = A[i]<min_negative?A[i]:min_negative;
    for(int i=0; i<n;i++){
        if(A[i]>=n) continue;
        int x;
        if(A[i]<min_negative)
            x = min_negative-A[i];
        if(A[i]>0)
            x = A[i];
        if(x<n && A[x]>=0)
            A[x] = min_negative-A[x];
    }
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    for(int i=1; i<n; i++)
        if(A[i]>min_negative && A[i]<n)
            return i;
    return n;
}

int main(){
    int arr0[] = {1, 2, 0}; //3
    int arr1[] = {3, 4, -1, 1}; //2 
    printf("%d\n", firstMissingPositive(arr0,sizeof(arr0)/sizeof(arr0[0])));
    printf("%d\n", firstMissingPositive(arr1,sizeof(arr1)/sizeof(arr1[0])));
    return 0;
}
