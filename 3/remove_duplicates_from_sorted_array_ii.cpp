#include "header.h"

int removeDuplicates(int A[], int n) {
    if(n == 0 || n==1) return n;
    int tail = 0, curr = 1, seen_times = 1;
    for(;curr<n;curr++){
        if(A[curr] == A[tail] && seen_times >=2)
            continue;
        if(A[curr] == A[tail])
            seen_times++;
        else
            seen_times = 1;
        A[++tail] = A[curr];
    }
    return tail+1;
}

int main(){
    //int A[] = {1, 1, 1, 2, 2, 3};
    //int A[] = {1, 1, 1, 1, 3, 3};
    int A[] = {0, 0, 0, 1, 2, 2, 4, 4};
    int res = removeDuplicates(A,sizeof(A)/sizeof(A[0]));
    for(int i=0; i<res; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
