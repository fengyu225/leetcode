/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

#include "header.h"

bool containsNearbyDuplicate(vector<int>& nums, int k){
    int sz = nums.size();
    if(sz < 2 || k == 0) return false;
}

int main(){
    int arr[] = {1,2,3,1,3};
//    int arr[] = {99,99};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<containsNearbyDuplicate(v_arr, 3)<<endl;
    return 0;
}