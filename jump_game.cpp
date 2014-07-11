#include "header.h"

bool canJump(int A[], int n) {
    if(n<=1) return true;
    int start = 0, end=0, max=0;
    while(end<n){
        if(start>end || start==end && A[start]==0)
            return false;
        for(int i=start;i<=end;i++){
            if(A[i]+i>=n-1)
                return true;
            if(A[i]+i>max)
                max=A[i]+i;
        }
        start = end+1;
        end = max;
    }
    return true;
}

int main(){
    //int A[] = {2, 3, 1, 1, 4};
    int A[] = {2, 1, 0, 0};
    bool res = canJump(A, sizeof(A)/sizeof(A[0]));
    printf("%s\n", res?"true":"false");
    return 0;
}
