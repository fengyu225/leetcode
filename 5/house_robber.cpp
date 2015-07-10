/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob(vector<int>& nums) {
    int res = 0;
    int sz = nums.size();
    if(sz == 0) return 0;
    vector<int> temp(sz, 0);
    temp[0] = nums[0];
    if(sz == 1) return temp[0];
    temp[1] = nums[1];
    res = max(temp[0], temp[1]);
    int m = 0 ;
    for(int i=2; i<sz; i++){
        m = max(m, temp[i-2]);
        temp[i] = m+nums[i];
        res = max(temp[i], res);
    }
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {2,1,1,2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<rob(nums)<<endl;
    return 0;
}