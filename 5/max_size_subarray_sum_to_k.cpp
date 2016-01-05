/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

#include "header.h"

int maxSubArrayLen(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz == 0) return 0;
    vector<int> arr(sz, nums[0]);
    for(int i=1; i<sz; i++) arr[i] = arr[i-1]+nums[i];
    unordered_map<int,int> m;
    m[0] = -1;
    int res = 0;
    for(int i=0; i<sz; i++){
        int x = arr[i]-k;
        if(m.find(x) != m.end()) res = max(res, i-m[x]);
        if(m.find(arr[i]) == m.end()) m[arr[i]] = i;
    }
    return res;
}

int main(){
    vector<int> nums = {1, -1, 5, -2, 3};
    cout<<maxSubArrayLen(nums, 3)<<endl;
    return 0;
}