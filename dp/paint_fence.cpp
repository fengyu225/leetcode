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
    vector<int> arr_same(n, 0);
    vector<int> arr_diff(n, 0);
    arr_diff[0] = k;
    for(int i=1; i<n ;i++){
        arr_same[i] = arr_diff[i-1];
        arr_diff[i] = (k-1)*(arr_same[i-1]+arr_diff[i-1]);
    }
    cout<<arr_same[n-1]<<" "<<arr_diff[n-1]<<endl;
    return arr_same[n-1]+arr_diff[n-1];
}

int main(){
    //cout<<numWays(5, 2)<<endl;
    cout<<numWays(1, 7)<<endl;
    return 0;
}