/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include "header.h"

int missingNumber(vector<int>& nums){
    int x = 0;
    int n = nums.size();
    for(int i=0; i<=n; i++) x^=i;
    for(int temp:nums) x^=temp;
    return x;
}

int main(){
    vector<int> nums = {0, 1, 3};
    cout<<missingNumber(nums)<<endl;
    return 0;
}