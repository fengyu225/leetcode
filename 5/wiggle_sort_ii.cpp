/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include "header.h"

void wiggleSort(vector<int>& nums) {
    //https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
    int sz = nums.size();
    if(sz<2) return;
    sort(nums.begin(), nums.end());
    vector<int> temp;
    int m = sz%2 == 0?sz/2-1:sz/2;
    for(int i=m, j=sz-1; i>=0 || j>m; ){
        if(i>=0) temp.push_back(nums[i--]);  
        if(j>m) temp.push_back(nums[j--]);  
    }
    nums = temp;
}

int main(){
    vector<int> nums = {1,3,2,2,2,1,1,3,1,1,2};
    wiggleSort(nums);
    print_vector<int>(nums);
    vector<int> nums_1 = {1, 5, 1, 1, 6, 4};
    wiggleSort(nums_1);
    print_vector<int>(nums_1);
    return 0;
}