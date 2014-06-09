#include "header.h"

int findKSmallest(int A[], int m, int B[], int n, int k){
    if(m==0)
        return B[k-1];
    if(n==0)
        return A[k-1];
    if(k==1)
        return A[0]<B[0]?A[0]:B[0];
    int a_m = (int)((double)m/((double)(m+n))*(k-1));
    int b_m = k-1-a_m;
    if(A[a_m]>B[b_m] && (a_m==0 || A[a_m-1]<B[b_m]))
        return B[b_m];
    if(B[b_m]>A[a_m] && (b_m==0 || B[b_m-1]<A[a_m]))
        return A[a_m];
    else if(A[a_m]<B[b_m])
        return findKSmallest(A+a_m+1, m-a_m-1, B, b_m, k-a_m-1);
    else
        return findKSmallest(A, a_m, B+b_m+1, n-b_m-1, k-b_m-1);
}

double findKSmallest(int a[], int m, int b[], int n, int k)  
{  
    //always assume that m is equal or smaller than n  
    if (m > n)  
        return findKSmallest(b, n, a, m, k);  
    if (m == 0)  
        return b[k - 1];  
    if (k == 1)  
        return min(a[0], b[0]);  
    //divide k into two parts  
    int pa = min(k / 2, m), pb = k - pa;  
    if (a[pa - 1] < b[pb - 1])  
        return findKSmallest(a + pa, m - pa, b, n, k - pa);  
    else if (a[pa - 1] > b[pb - 1])  
        return findKSmallest(a, m, b + pb, n - pb, k - pb);  
    else  
        return a[pa - 1];  
}  

double findMedianSortedArrays(int A[], int m, int B[], int n){
    int total = m+n;
    if(total%2==1)
        return findKSmallest(A, m, B, n, total/2+1);
    else
        return (findKSmallest(A, m, B, n, total/2)+findKSmallest(A,m,B,n,total/2+1))/2;
}

int main(){
    int A[] = {2, 3, 4, 5, 6, 7};
    int B[] = {1};
    printf("%f\n", findMedianSortedArrays(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0])));
//    for(int i=1; i<=11; i++)
//        printf("i=%d, ith small:%d\n", i, findKSmallest(A, 5, B, 6, i));
    return 0;
}
