/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include "header.h"

bool containsDuplicate(vector<int>& nums) {
    int sz = nums.size();
    if(sz<2) return false;
    unordered_set<int> set;
    for(int i=0; i<nums.size(); i++){
        if(set.find(nums[i]) != set.end()) return true;
        set.insert(nums[i]);
    }
    return false;
}

int main(){
    int arr[] = {0, 1, 1, 2, 3};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<containsDuplicate(v_arr)<<endl;
    return 0;
}