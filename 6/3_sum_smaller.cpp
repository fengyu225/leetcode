/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Could you solve it in O(n2) runtime?
*/

#include "header.h"

int threeSumSmaller(vector<int>& nums, int target){
}

int main(){
    vector<int> nums = {-2, 0, 1, 3};
    cout<<threeSumSmaller(nums, 2)<<endl;
    return 0;
}