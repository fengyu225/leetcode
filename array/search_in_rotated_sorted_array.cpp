/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include "header.h"

int search(vector<int>& nums, int target) {
    int sz = nums.size();
    if(sz  == 0) return -1;
    if(sz == 1) return nums[0] == target?0:-1;
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(nums[m] == target) return m;
        if(nums[m]<nums[l]){
            if(target<nums[m] || target>=nums[l]) r=m-1;
            else l=m+1;
        }
        else{
            //nums[m]>nums[l]
            if(target<nums[m] && target>=nums[l]) r=m-1;
            else l=m+1;
        }
    }
    return target==nums[l]?l:target==nums[r]?r:-1;
}

int main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
//    int A[] = {3,1};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    printf("%d\n", search(arr, 4));
//    printf("%d\n", search(arr, 5));
//    printf("%d\n", search(arr, 2));
//    printf("%d\n", search(arr, 4));
//    printf("%d\n", search(arr, 3));
    return 0;
}
