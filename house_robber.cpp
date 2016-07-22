/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob(vector<int>& nums) {
    int res = 0;
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    res = max(nums[0], nums[1]);
    int m = 0;
    int a=nums[0], b=res;
    for(int i=2; i<sz; i++){
        m = max(m, a);
        a=b;
        b=m+nums[i];
        res = max(b, res);
    }
    return res;
}

int rob(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    int before_last_res = nums[0], last_res = nums[1], res = max(before_last_res, last_res);
    int before_last = nums[0], last = nums[1];
    for(int i=2; i<sz; i++){
        int curr = before_last_res+nums[i];
        before_last = last;
        last = curr;
        before_last_res = max(before_last_res, before_last);
        last_res = max(last_res,last);
        res = max(res, last_res);
    }
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    //int arr[] = {2,1,1,2};
//    int arr[] = {2,7,9,3,1};
//    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> nums(100000,1);
    cout<<rob(nums)<<endl;
    return 0;
}