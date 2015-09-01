/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include "header.h"

int removeDuplicates(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 1) return 1;
    int tail = 0, curr = 1, res = 1;
    while(curr<sz){
        if(nums[curr] == nums[tail]) curr++;
        else{
            nums[++tail] = nums[curr++];
            res++;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 1, 2, 2, 2, 3,3,3,3,3,3,3};
    int res = removeDuplicates(nums);
    for(int i=0; i<res; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}