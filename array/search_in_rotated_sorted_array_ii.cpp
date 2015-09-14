/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include "header.h"

bool search(vector<int>& nums, int target) {
    int sz = nums.size();
    if(sz == 0) return false;
    int l = 0, r = sz-1, m;
    while(l+1<r){
        m = (l+r)/2;
        if(nums[m] == target) return true;
        if(nums[m] == nums[l]) l=m+1;
        else if(nums[m]>nums[l]){
            if(target>=nums[l] && target<nums[m]) r = m-1;
            else l=m+1;
        }
        else{
            if(target>nums[m] && target<=nums[r]) l=m+1;
            else r=m-1;
        }
    }
    return nums[l] == target || nums[r] == target;
}


int main(){
//    int A[] = {1, 1};
    vector<int> arr = {4, 4, 5, 5, 6, 7, 7, 0, 0, 1, 1, 2};
    printf("%d\n", search(arr, 4));
//    int A[] = {4, 4, 5, 5, 6, 7, 7, 0, 0, 1, 1, 2};
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 5));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 2));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 4));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 3));
    return 0;
}
