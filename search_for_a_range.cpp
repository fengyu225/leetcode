#include "header.h"

int find_small(int A[], int n, int target){
    int l=0, r=n-1;
    while(l<n){
        int m = (l+r)/2;
        if(target<=A[m])
            r = m-1;
        else
            l = m+1;
    }
    printf("%d,%d\n", l, r);
    return 0;
}

vector<int> searchRange(int A[], int n, int target) {
    vector<int> res(2,-1);
    find_small(A,n,target);
    return res;
}

int main(){
    int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(A,sizeof(A)/sizeof(A[0]),8);
    printf("%d, %d\n", res[0], res[1]);
    return 0;
}
