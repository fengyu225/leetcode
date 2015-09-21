/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

#include "header.h"

bool containsNearbyDuplicate(vector<int>& nums, int k){
    int sz = nums.size();
    unordered_set<int> s;
    int l = 0, r = 0;
    k = min(k, sz-1);
    for(;r<=k;r++){
        if(s.find(nums[r]) != s.end()) return true;
        s.insert(nums[r]);
    }
    for(;r<sz;r++){
        cout<<r<<endl;
        s.erase(nums[l++]);
        if(s.find(nums[r]) != s.end()) return true;
        s.insert(nums[r]);
    }
    return false;
}

int main(){
    int arr[] = {1, 0, 1, 1};
//    int arr[] = {1,2,3,1,3};
//    int arr[] = {99,99};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<containsNearbyDuplicate(v_arr, 1)<<endl;
    return 0;
}