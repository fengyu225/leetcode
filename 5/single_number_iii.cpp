/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include "header.h"

//vector<int> singleNumber(vector<int>& nums){
//    //using O(n) space
//    vector<int> res;
//    int sz = nums.size();
//    unordered_map<int,int> m;
//    for(int c:nums) m[c]++;
//    for(int c:nums) if(m[c] == 1) res.push_back(c);
//    return res;
//}

vector<int> singleNumber(vector<int>& nums){
    vector<int> res;
    int sz = nums.size();
    int a_xor_b = nums[0];
    for(int i=1; i<sz; i++) a_xor_b^=nums[i];
    int a=0;
    int i=1;
    for(;i<INT_MAX;i<<=1)
        if(a_xor_b&i) break;
    for(int c:nums) if(c&i) a^=c;
    res.push_back(a);
    res.push_back(a^a_xor_b);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> res = singleNumber(nums);
    for(int c:res) cout<<c<<" ";
    cout<<endl;
    return 0;
}