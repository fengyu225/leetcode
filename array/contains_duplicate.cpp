/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include "header.h"

bool containsDuplicate(vector<int>& nums) {
    int sz = nums.size();
    if(sz<2) return false;
    unordered_set<int> s;
    for(int i=0; i<sz; i++){
        if(s.find(nums[i]) != s.end()) return true;
        s.insert(nums[i]);
    }
    return false;
}

int main(){
    vector<int> v_arr = {0, 1, 1, 2, 3};
    cout<<containsDuplicate(v_arr)<<endl;
    return 0;
}