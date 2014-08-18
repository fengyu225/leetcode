#include "header.h"

int searchInsert(int A[], int n, int target) {
    return -1;
}

int main(){
    int A[] = {1, 3, 5, 6};
    int size = sizeof(A)/sizeof(A[0]);
    cout<<searchInsert(A,size,5)<<endl;
    cout<<searchInsert(A,size,2)<<endl;
    cout<<searchInsert(A,size,7)<<endl;
    cout<<searchInsert(A,size,4)<<endl;
    return 0;
}
