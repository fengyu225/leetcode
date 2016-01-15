/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include "header.h"

void moveZeroes(vector<int>& nums) {
    int sz = nums.size();
    int l = -1, curr = 0;
    while(curr<sz){
        if(nums[curr] != 0) swap(nums[curr], nums[++l]);
        curr++;
    }
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    print_vector<int>(nums);
    return 0;
}