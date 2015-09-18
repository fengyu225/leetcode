/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include "header.h"

// O(n) solution
int minSubArrayLen(int s, vector<int>& nums) {
    int sz = nums.size(); 
    int l = 0, r = 0, res = sz+1, curr_sum = 0;
    for(;r<sz;r++){
        curr_sum += nums[r];
        if(curr_sum<s) continue;
        while(curr_sum>=s) curr_sum -= nums[l++];
        res = min(res, r-l+2);
    }
    return res == sz+1?0:res;
}

int main(){
    int arr[] = {2, 3, 1, 2, 4, 3};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    //cout<<minSubArrayLen(INT_MAX,nums)<<endl;
    cout<<minSubArrayLen(7,nums)<<endl;
    return 0;
}