/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include "header.h"

int majorityElement(vector<int>& nums) {
    int sz = nums.size();
    int candidate = nums[0], count = 1;
    for(int i=1; i<sz; i++){
        if(count == 0){
            candidate = nums[i];
            count = 1;
            continue;
        }
        if(nums[i] == candidate) count++;
        else count--;
    }
    return candidate;
}

int main(){
    vector<int> v_arr = {0, 1, 1, 1, 2, 3};
    cout<<majorityElement(v_arr)<<endl;
    return 0;
}