/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

#include "header.h"

int maxCoins(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    vector<vector<int> > arr(sz, vector<int>(sz, 0));
    for(int len = 1; len<=sz; len++){
        for(int i=0; i+len<=sz; i++){
            for(int j=i; j<i+len; j++){
                int left = j==i?0:arr[i][j-1];
                int right = j-i+1==len?0:arr[j+1][i+len-1];
                int curr = nums[j]*(i-1>=0?nums[i-1]:1)*(i+len<sz?nums[i+len]:1);
                arr[i][i+len-1] = max(arr[i][i+len-1], left+right+curr);
            }
        }
    }
    return arr[0][sz-1];
}

int main(){
    vector<int> nums = {3, 1, 5, 8};
    cout<<maxCoins(nums)<<endl;
    return 0;
}