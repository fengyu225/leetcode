#include "header.h"

void merge(int A[], int m, int B[], int n) {
    int curr=m+n-1,curr_a=m-1,curr_b=n-1;
    while(curr_a>-1 || curr_b>-1){
        if(curr_a==-1 || curr_a>=0 && curr_b>=0 && A[curr_a]<=B[curr_b]){
            A[curr--]=B[curr_b--];
            continue;
        }
        if(curr_b==-1 || curr_a>=0 && curr_b>=0 && A[curr_a]>B[curr_b]){
            A[curr--]=A[curr_a--];
            continue;
        }
    }

}

int main(){
//    int A[] = {0, 2, 4, 6, 8, -1, -1, -1, -1};
//    int B[] = {1, 3, 5, 7};
//    merge(A,5,B,4);
    int A[] = {1, 2, 3, -1, -1, -1};
    int B[] = {2, 5, 6};
    merge(A,3,B,3);
    for(int i=0; i<sizeof(A)/sizeof(A[0]);i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
