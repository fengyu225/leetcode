#include "header.h"

int jump(int A[], int n) {
    if(n == 1) return 0;
    int num = 0;
    int l = 0,r=0;
    while(r<n-1){
        int max = r;
        for(int i=l;i<=r;i++)
            max = std::max(max,A[i]+i);
        l = r+1;
        r = max;
        num++;
    }
    return num;
}

int main(){
    int A[] = {2, 3, 1, 1, 4};
    int res = jump(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
