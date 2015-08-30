/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include "header.h"

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int sz = nums.size();
    if(sz <2) return res;
    unordered_map<int,int> m;
    for(int i=0; i<sz; i++){
        if(m.find(target-nums[i]) != m.end()){
            res.push_back(m[target-nums[i]]+1);
            res.push_back(i+1);
            break;
        }
        m[nums[i]] = i;
    }
    return res;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 9);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}