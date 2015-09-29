/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    vector<int> arr(sz, 0);
    arr[1] = max(nums[0], nums[1]);
    arr[0] = nums[0];
    int res = arr[1];
    for(int i=2; i<sz; i++){
        arr[i] = max(arr[i-2]+nums[i], arr[i-1]);
        res = max(res, arr[i]);
    }
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    //int arr[] = {2,1,1,2};
//    int arr[] = {2,7,9,3,1};
//    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    //vector<int> nums(100000,1);
    vector<int> nums = {1, 1, 1};
    cout<<rob(nums)<<endl;
    return 0;
}