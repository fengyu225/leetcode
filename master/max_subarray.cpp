#include "header.h"

int maxSubArray(int A[], int n) {
    int arr[n];
    for(int i=0; i<n; i++) A[n] = INT_MIN;
    arr[0]=A[0];
    int res=arr[0];
    for(int i=1; i<n; i++){
        arr[i] = std::max(arr[i-1]+A[i],A[i]);
        res = std::max(res,arr[i]);
    }
    return res;
}

int main(){
    //int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
