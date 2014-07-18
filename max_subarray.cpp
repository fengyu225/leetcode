#include "header.h"

int maxSubArray(int A[], int n) {

}

int main(){
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = maxSubArray(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
