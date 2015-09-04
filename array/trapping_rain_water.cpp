/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include "header.h"

int trap(vector<int>& height) {
    int sz = height.size();
    if(sz < 2) return 0;
    vector<int> left(sz, 0);
    vector<int> right(sz, 0);
    for(int i=1; i<sz; i++){
        left[i] = max(left[i-1], height[i-1]);
        right[sz-i-1] = max(right[sz-i], height[sz-i]);
    }
    int res = 0;
    for(int i=0; i<sz; i++){
        int x = min(left[i], right[i]);
        if(x>height[i]) res+=x-height[i];
    }
    return res;
}

int main(){
    //int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int A[] = {2,0,2};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    cout<<trap(arr)<<endl;
    return 0;
}
