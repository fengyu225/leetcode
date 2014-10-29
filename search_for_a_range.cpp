#include "header.h"

int find_small(int A[], int n, int target){
    int l=0, r=n-1;
    while(l<r){
        int m = (l+r)/2;
        if(target<A[m])
            r = m-1;
        else if(target==A[m])
            r = m;
        else
            l = m+1;
    }
    if(l>r || A[l]!=target) return -1;
    return l;
}

int find_large(int A[], int n, int target){
    int l=0,r=n-1;
    while(l<r){
        int m = (l+r+1)/2;
        if(target>A[m])
            l = m+1;
        else if(target==A[m])
            l = m;
        else
            r = m-1;
    }
    if(l>r || A[l]!=target) return -1;
    return l;
}

vector<int> searchRange(int A[], int n, int target) {
    vector<int> res(2,-1);
    res[0] = find_small(A,n,target);
    res[1] = find_large(A,n,target);
    return res;
}

int main(){
//    int A[] = {5, 7, 7, 8, 8, 10};
//    vector<int> res = searchRange(A,sizeof(A)/sizeof(A[0]),10);
    int A[] = {1, 2, 3};
    vector<int> res = searchRange(A,sizeof(A)/sizeof(A[0]),2);
    printf("%d, %d\n", res[0], res[1]);
    return 0;
}
