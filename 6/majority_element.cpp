/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include "header.h"

int majorityElement(vector<int>& nums){
    int sz = nums.size();
    int candidate, count=0;
    for(int i:nums){
        if(count == 0){
            candidate=i;
            count++;
        }
        else if(candidate != i) count--;
        else count++;
    }
    return candidate;
}

int main(){
    int arr[] = {0, 1, 1, 1, 2, 3, 1};
    vector<int> v_arr(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<majorityElement(v_arr)<<endl;
    return 0;
}