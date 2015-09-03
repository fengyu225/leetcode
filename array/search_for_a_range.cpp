/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include "header.h"

int find_start(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz == 0) return -1;
    if(sz == 1) return nums[0] == target?0:-1;
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(target == nums[m]) r=m;
        else if(target<nums[m]) r=m-1;
        else l=m+1;
    }
    return nums[l] == target?l:nums[r] == target?r:-1;
}

int find_end(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz == 0) return -1;
    if(sz == 1) return nums[0] == target?0:-1;
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(target == nums[m]) l=m;
        else if(target<nums[m]) r=m-1;
        else l=m+1;
    }
    return nums[r] == target?r:nums[l] == target?l:-1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int l_res = find_start(nums, target);
    int r_res = find_end(nums, target);
    res.push_back(l_res);
    res.push_back(r_res);
    return res;
}

int main(){
    int A[] = {5, 7, 7, 8, 8, 10};
//    int A[] = {2,2};
//    vector<int> res = searchRange(A,sizeof(A)/sizeof(A[0]),10);
    //int A[] = {1, 2, 3};
    vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
    vector<int> res = searchRange(nums,7);
    printf("%d, %d\n", res[0], res[1]);
    return 0;
}
