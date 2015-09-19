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
    unordered_map<int,int> m;
    int sz = nums.size();
    for(int i=0; i<sz; i++){
        if(m.find(target-nums[i]) != m.end()){
            res.push_back(m[target-nums[i]]);
            res.push_back(i+1);
            break;
        }
        m[nums[i]] = i+1;
    }
    return res;
}

int main(){
//    int arr[] = {2, 7, 11, 15};
//    int target = 9;
    vector<int> numbers = {0, 4, 3, 0};
    vector<int> r = twoSum(numbers, 0);
    print_vector<int>(r);
    return 0;
}
