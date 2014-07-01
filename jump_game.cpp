#include "header.h"

int jump(int A[], int n){
    if(n==1) return 0;
    return 0;
}

int main(){
    int A[] = {2, 3, 1, 1, 4};
    int res = jump(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
