/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
*/

#include "header.h"

//int findDuplicate(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    int sz = nums.size();
//    for(int i=1; i<sz; i++){
//        if(nums[i] == nums[i-1]) return nums[i];
//    }
//}

int search(vector<int>& nums, int l, int r){
    if(l == r) return nums[l];
    int tail = l, curr = l+1;
    int min_v = nums[l], max_v = nums[l];
    while(curr<=r){
        if(nums[curr]<min_v) min_v = nums[curr];
        if(nums[curr]>max_v) max_v = nums[curr];
        if(nums[curr] == nums[l] || curr != r && nums[curr] == nums[r]) return nums[curr];
        if(nums[curr]<nums[l]) swap(nums[++tail], nums[curr]);
        curr++;
    }
    swap(nums[tail], nums[l]);
    if(tail == l) return search(nums, l+1, r);
    if(tail == r) return search(nums, l, r-1);
    if(nums[tail]-min_v<tail-l) return search(nums, l, tail);
    else return search(nums, tail, r);
}

int findDuplicate(vector<int>& nums) {
    int sz = nums.size();
    int l = 0, r = sz-1;
    return search(nums, l, r);
}

int main(){
//    vector<int> nums = {1, 2, 3, 4, 5, 3};
//    vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {14,16,12,1,16,17,6,8,5,19,16,13,16,3,11,16,4,16,9,7};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}