#include "header.h"

int removeDuplicates(int A[], int n) {
    if(n==0 || n==1 || n==2) return n;
    int pre=0,curr=1;
    int count=1;
    while(curr<n){
        if(A[curr] == A[pre] && count<2){
            pre++;
            A[pre] = A[curr];
            curr++;
            count++;
            continue;
        }
        if(A[curr] != A[pre]){
            A[++pre] = A[curr++];
            count=1;
            continue;
        }
        curr++;
    }
    return pre+1;
}

int main(){
    //int A[] = {1, 1, 1, 2, 2, 3};
    int A[] = {1, 1, 1, 1, 3, 3};
    int res = removeDuplicates(A,sizeof(A)/sizeof(A[0]));
    for(int i=0; i<res; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
