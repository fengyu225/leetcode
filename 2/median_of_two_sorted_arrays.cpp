#include "header.h"

int find_k(int A[], int m, int B[], int n, int k){
    if(m+n<k) return INT_MAX;
    if(m>n) return find_k(B,n,A,m,k);
    if(m == 0) return B[k-1];
    if(k==1) return std::min(A[0],B[0]);
    int a_idx = std::min(k/2,m);
    int b_idx = k-a_idx;
    if(A[a_idx-1] == B[b_idx-1])
        return A[a_idx-1];
    else if(A[a_idx-1]<B[b_idx-1])
        return find_k(A+a_idx,m-a_idx,B,n,k-a_idx);
    else
        return find_k(A,m,B+b_idx,n-b_idx,k-b_idx);
}

double findMedianSortedArrays(int A[], int m, int B[], int n){
    int total = m+n;
    if(total&1U)
        return find_k(A,m,B,n,(m+n)/2+1);
    return 0.5*(double)(find_k(A,m,B,n,(m+n)/2)+find_k(A,m,B,n,(m+n)/2+1));
}

int main(){
//    int A[] = {2, 3, 4, 5, 6, 7};
//    int B[] = {1};
    int A[] = {1,2};
    int B[] = {1,2,3};
    printf("%f\n", findMedianSortedArrays(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0])));
    return 0;
}
