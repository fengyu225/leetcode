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
    int cnt = 0, tail = -1;
    for(int i=0; i<sz; i++){
        if(nums[i] == 0) continue;
        nums[++tail] = nums[i];
        cnt++;
    }
    for(int i=cnt; i<sz; i++) nums[i] = 0;
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    print_vector<int>(nums);
    return 0;
}