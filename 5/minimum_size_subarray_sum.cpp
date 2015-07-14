/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include "header.h"

int getMin(int res, int curr){
    if(res>0) return min(curr,res);
    else return curr;
}

int minSubArrayLen(int s, vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return 0;
    int res = 0;
    int l = 0, r=0, sum = 0;
    while(r<sz){
        sum += nums[r];
        while(l<=r && sum>=s){
            res = getMin(res, r-l+1);
            sum -= nums[l++];
        }
        r++;
    }
    return res;
}

int main(){
    int arr[] = {2, 3, 1, 2, 4, 3};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<minSubArrayLen(7,nums)<<endl;
    return 0;
}