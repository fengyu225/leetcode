#include "header.h"

int removeDuplicates(int A[], int n) {

}

int main(){
    int A[] = {1, 1, 1, 2, 2, 3};
    int res = removeDuplicates(A,sizeof(A)/sizeof(A[0]));
    for(int i=0; i<res; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
