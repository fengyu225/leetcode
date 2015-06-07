/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include "header.h"

/* recursive */
//int search(int l, int r){
//    if(l == r) return 1;
//    int res = 0;
//    for(int i=l; i<=r; i++){
//        int l_res = i==l?1:search(l,i-1);
//        int r_res = i==r?1:search(i+1, r);
//        res += l_res*r_res;
//    } 
//    return res;
//}
//
//int numTrees(int n){
//    return search(1,n);
//}

int numTrees(int n){
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    for(int len=1; len<=n; len++){
        for(int j=1; j<=n-len+1; j++){
            if(len == 1) arr[len][j] = 1;
            else{
                arr[len][j] += arr[len-1][j+1];
                arr[len][j] += arr[len-1][j];
                for(int k=1;k<len;k++) arr[len][j] += (arr[k][j]*arr[len-k-1][j+k+1]); 
            }
        }
    }
    return arr[n][1];
}

int main(){
    cout<<numTrees(3)<<endl;
    return 0;
}