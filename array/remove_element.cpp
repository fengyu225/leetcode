/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include "header.h"

int removeElement(vector<int>& nums, int val) {
    int sz = nums.size();
    int tail = -1, curr = 0;
    int res = 0;
    while(curr<sz){
        if(nums[curr] == val) curr++;
        else{
            nums[++tail] = nums[curr++];
            res++;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    int len = removeElement(nums, 3);
    for(int i=0; i<len; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}