#include "header.h"

bool canJump(int A[], int n) {
    if(n == 1) return true;
    int l=0,r=0;
    while(r<n-1){
        int max = r;
        for(int i=l;i<=r;i++)
            max = std::max(max,A[i]+i);
        if(max == r) return false;
        l = r+1;
        r = max;
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
