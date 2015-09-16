/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

 */

#include "header.h"

int findMin(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 1) return nums[0];
    int l = 0, r = sz-1, m;
    
}

int main(){
    //int arr[] = {4, 4, 5, 6, 7, 0, 1, 2, 4};
    int arr[] = {10, 1, 10, 10, 10};
//    int arr[] = {3, 3, 1, 3};
//    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(int));
    cout<<findMin(num)<<endl;
    return 0;
}
