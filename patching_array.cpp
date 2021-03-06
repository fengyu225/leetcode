/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
*/

#include "header.h"

int minPatches(vector<int>& nums, int n) {
    int sz = nums.size(), curr = 0;
    long curr_end = 0, res = 0;
    while(curr_end<n){
        if(curr>=sz || (curr<sz && curr_end+1<nums[curr])){
            res++;
            curr_end = 2*curr_end+1; 
        }
        else curr_end += nums[curr++];
    }
    return res;
}

int main(){
//    vector<int> nums = {1, 3};
//    cout<<minPatches(nums, 6)<<endl;
//    vector<int> nums = {1, 5, 10};
//    cout<<minPatches(nums, 20)<<endl;
//    vector<int> nums = {1, 2, 2};
//    cout<<minPatches(nums, 5)<<endl;
//    vector<int> nums = {};
//    cout<<minPatches(nums, 7)<<endl;
    vector<int> nums = {1, 2, 31, 33};
    cout<<minPatches(nums, INT_MAX)<<endl;
    return 0;
}
