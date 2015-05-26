/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include "header.h"

int searchInsert(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz == 0) return 0;
    int l=0, r=sz-1;
    while(l<r){
        int m = (l+r)/2;
        if(nums[m] == target) return m;
        if(nums[m]>target) r=m;
        else l=m+1;
    }
    if(nums[l] == target) return l;
    if(l==sz-1) return target<nums[l]?l:sz;
    if(l == 0) return target<nums[l]?0:1;
    return l;
}

int main(){
//   int A[] = {1, 2, 3, 4,5 , 10};
//   int size = sizeof(A)/sizeof(A[0]);
//   cout<<searchInsert(A,size,2)<<endl;
   int A[] = {1, 3, 5, 6};
   int size = sizeof(A)/sizeof(A[0]);
   vector<int> arr(A,A+size);
   cout<<searchInsert(arr,5)<<endl;
   cout<<searchInsert(arr,2)<<endl;
   cout<<searchInsert(arr,7)<<endl;
   cout<<searchInsert(arr,0)<<endl;
    return 0;
}
