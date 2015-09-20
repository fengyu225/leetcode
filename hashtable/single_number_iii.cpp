/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include "header.h"

vector<int> singleNumber(vector<int>& nums){
    int sz = nums.size();
    int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    int n = x&~(x-1);
    vector<int> res(2,0);
    for(int i=0; i<sz; i++){
        if(nums[i]&n) res[0]^=nums[i];
        else res[1]^=nums[i];
    }
    return res;
}

int main(){
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> res = singleNumber(nums);
    for(int c:res) cout<<c<<" ";
    cout<<endl;
    return 0;
}