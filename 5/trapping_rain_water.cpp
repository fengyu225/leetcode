/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include "header.h"

int trap(vector<int>& height){
    int sz = height.size();
    if(sz < 2) return 0;
    int left[sz];
    int right[sz];
    int res = 0;
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    for(int i=1; i<sz; i++)
        left[i] = max(left[i-1], height[i-1]);
    for(int i=sz-2; i>=0; i--)
        right[i] = max(right[i+1], height[i+1]);
    for(int i=0; i<sz; i++){
        if(height[i]<left[i] && height[i]<right[i])
            res += min(left[i], right[i])-height[i];
    }
    return res;
}

int main(){
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    cout<<trap(arr)<<endl;
    return 0;
}
