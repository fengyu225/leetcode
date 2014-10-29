#include "header.h"

//int searchInsert(int A[], int n, int target) {
//    int l=0,r=n-1;
//    while(l<r){
//        int m = (l+r)/2;
//        if(A[m] == target) return m;
//        else if(target<A[m]) r=m-1;
//        else l=m+1;
//    }
//    if(l==0) return target>A[0]?1:0;
//    if(l==n-1) return target>A[n-1]?n:n-1;
//    if(A[l] >= target) return l;
//    else return l+1;
//}

int searchInsert(int A[], int n, int target) {
    int l=0,r=n-1;
    while(l<r){
        int m = (l+r+1)/2;
        if(target<A[m]) r=m-1;
        else l=m;
    }
    if(A[l]>=target) return l;
    else return l+1;
}

int main(){
//   int A[] = {1, 2, 3, 4,5 , 10};
//   int size = sizeof(A)/sizeof(A[0]);
//   cout<<searchInsert(A,size,2)<<endl;
   int A[] = {1, 3, 5, 6};
   int size = sizeof(A)/sizeof(A[0]);
   cout<<searchInsert(A,size,5)<<endl;
    cout<<searchInsert(A,size,2)<<endl;
    cout<<searchInsert(A,size,7)<<endl;
    cout<<searchInsert(A,size,0)<<endl;
    return 0;
}
