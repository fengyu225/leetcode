/*
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

#include "header.h"

int numWays(int n, int k) {
    if(n == 0 || k == 0) return 0;
    vector<int> arr0(n, 0); //same
    vector<int> arr1(n, 0); //different
    arr1[0] = k;
    for(int i=1; i<n; i++){
        arr0[i] = arr0[i-1];
        arr1[i] = (k-1)*(arr0[i-1]+arr1[i-1]);
    }
    return arr0[n-1]+arr1[n-1];
}

int main(){
    cout<<numWays(5, 2)<<endl;
    return 0;
}