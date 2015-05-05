#include<stdlib.h>
#include<stdio.h>

int singleNumber(int A[], int n){
    int r = 0;
    for(int i=0; i<n; i++)
        r = r^A[i];
    return r;
}

int main(){
    int A[5] = {2, 2, 3, 3, 10};
    int r = singleNumber(A, sizeof(A)/sizeof(A[0]));
    printf("%d\n", r);
    return 0;
}
