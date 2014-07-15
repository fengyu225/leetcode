#include "header.h"

int removeDuplicates(int A[], int n) {
    if(n==0 || n==1) return n;
    int p=0,q=0;
    while(q<n){
        if(A[p] == A[q]){
            q++;
            continue;
        }
        A[p+1] = A[q];
        p+=1;
    }
    return p+1;
}

int main(){
    int A[] = {1, 1, 2};
    int res = removeDuplicates(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    for(int i=0; i<res; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
