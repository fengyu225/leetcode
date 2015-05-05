#include "header.h"

int trap(int A[], int n) {
    if(n<=2) return 0;
    int left[n];
    int right[n];
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    for(int i=1;i<n;i++)
        left[i] = A[i-1]>left[i-1]?A[i-1]:left[i-1];
    for(int i=n-2;i>=0;i--)
        right[i] = A[i+1]>right[i+1]?A[i+1]:right[i+1];
    int res = 0;
    for(int i=1;i<n-1;i++){
        if(A[i]<left[i] && A[i]<right[i])
            res += std::min(left[i],right[i])-A[i];
    }
    return res;
}

int main(){
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(A,sizeof(A)/sizeof(A[0])));
    return 0;
}
