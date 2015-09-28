/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
*/

#include "header.h"

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for(int i=1; i<sz; i++){
        if(nums[i] == nums[i-1]) return nums[i];
    }
}

int main(){
//    vector<int> nums = {1, 2, 3, 4, 5, 3};
    vector<int> nums = {[2,2,2,2,2]};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}