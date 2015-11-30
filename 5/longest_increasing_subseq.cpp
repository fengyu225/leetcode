/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

#include "header.h"

int lengthOfLIS(vector<int>& nums) {
    //dp
    int sz = nums.size(), res = 1;
    if(sz == 0) return 0;
    vector<int> arr(sz, 1);
    for(int i=1; i<sz; i++){
        int temp = 1;
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]) temp = max(temp, arr[j]+1);
        }
        arr[i] = temp;
        res = max(res, arr[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}