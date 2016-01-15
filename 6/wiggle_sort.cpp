/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

#include "header.h"

void wiggleSort(vector<int>& nums) {
    int sz = nums.size();
    bool no_less = true;
    for(int i=1; i<sz; i++){
        if(no_less && nums[i]<nums[i-1] || !no_less && nums[i]>nums[i-1])
            swap(nums[i], nums[i-1]);
        no_less = !no_less;
    }
}

int main(){
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    wiggleSort(nums);
    print_vector<int>(nums);
    return 0;
}