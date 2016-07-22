/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include "header.h"

int rob_simple(vector<int>& nums, int from, int to){
    if(from == to) return nums[from];
    int res = max(nums[from], nums[from+1]);
    int a=nums[from], b=res;
    int m = 0;
    for(int i=from+2; i<=to; i++){
        m = max(m, a);
        a = b;
        b = m+nums[i];
        res = max(b, res);
    }
    return res;
}

int rob(vector<int>& nums) {
    int sz = nums.size();
    if(sz==0) return 0;
    if(sz == 1) return nums[0];
    int a = rob_simple(nums, 0, sz-2);
    int b = rob_simple(nums, 1, sz-1);
    return max(a,b);
}

int main(){
    int arr[] = {2,7,9,3,1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<rob(nums)<<endl;
    return 0;    
}