/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include "header.h"

int majorityElement(vector<int>& nums){
    int res = nums[0];
    int count = 1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == res) count++;
        else{
            if(count == 0){
                res = nums[i];
                count = 1;
            }
            else count--;
        }
    }
    return res;
}

int main(){
    int arr[] = {0, 1, 1, 1, 2, 3};
    vector<int> v_arr(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<majorityElement(v_arr)<<endl;
    return 0;
}