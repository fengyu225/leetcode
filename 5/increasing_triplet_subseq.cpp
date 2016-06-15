/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

#include "header.h"

bool increasingTriplet(vector<int>& nums) {
    int sz = nums.size();
    if(sz<3) return false;
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    for(int i : nums){
        if(i<a) a=i;
        else if(i>a && i<b) b = i;
        else if(i>b) return true;
    }
    return a<b && b<c && c!=INT_MAX;
}

int main(){
    vector<int> nums = {1,0,0,2,0,0,-1,-1,-1,-1,3};
    //vector<int> nums = {1, 1, 1, 1};
    //vector<int> nums = {1, 2, 3, 4, 5};
    //vector<int> nums = {5, 4, 3, 2, 1};
    cout<<increasingTriplet(nums)<<endl;
    return 0;
}
