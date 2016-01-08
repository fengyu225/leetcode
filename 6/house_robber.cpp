/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob(vector<int>& nums) {
    int sz = nums.size();
    int res = 0;
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    if(sz == 2) return max(nums[0], nums[1]);
//    vector<int> arr(sz, 0);
    int a = nums[0], b = max(nums[0], nums[1]);
    for(int i=2; i<sz; i++){
        int temp = a;
        a = b;
        b = max(temp+nums[i], a);
        res = max(b,res);
//        arr[i] = max(arr[i-2]+nums[i], arr[i-1]);
//        res = max(arr[i], res);
    }
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    vector<int> nums = {2,1,1,2};
//    int arr[] = {2,7,9,3,1};
//    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
//    vector<int> nums(100000,1);
    cout<<rob(nums)<<endl;
    return 0;
}