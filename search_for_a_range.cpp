/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include "header.h"

int find_low(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz==0) return -1;
    int l=0, r=sz-1;
    while(l<r){
        int m = (l+r)/2;
        if(target<=nums[m]) r=m;
        else l=m+1;
    }
    return l==r && nums[l] == target?l:-1;
}

int find_high(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz==0) return -1;
    int l=0, r=sz-1;
    while(l<r){
        int m = (l+r+1)/2;
        if(target == nums[m]) l=m;
        else if(target<nums[m]) r=m-1;
        else l=m+1;
    }
    return l==r && nums[l] == target?l:-1;
}

vector<int> searchRange(vector<int>& nums, int target){
    vector<int> res;
    res.push_back(find_low(nums,target));
    res.push_back(find_high(nums,target));
    return res;
}

int main(){
    //int A[] = {5, 7, 7, 8, 8, 10};
    int A[] = {2,2};
//    vector<int> res = searchRange(A,sizeof(A)/sizeof(A[0]),10);
    //int A[] = {1, 2, 3};
    vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
    vector<int> res = searchRange(nums,3);
    printf("%d, %d\n", res[0], res[1]);
    return 0;
}
