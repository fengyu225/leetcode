/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob_1(vector<int>& nums) {
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
    if(sz==0) return 0;
    vector<int> nums_a = nums;
    nums_a.pop_back();
    int a = rob_1(nums_a);
    vector<int> nums_b = nums;
    nums_b.erase(nums_b.begin());
    int b = rob_1(nums_b);
    return max(a,b);
}

int main(){
    int arr[] = {2,7,9,3,1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<rob(nums)<<endl;
    return 0;    
}