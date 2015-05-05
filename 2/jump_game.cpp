#include "header.h"

bool canJump(int A[], int n) {
    if(A[0] == 0) return n==1;
    bool res = false;
    int start = 0,end=0;
    while(end<n){
        int max = end;
        for(int i=start;i<=end;i++) max = std::max(max,i+A[i]);
        if(max == end) return false;
        if(max>=n-1) return true;
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
