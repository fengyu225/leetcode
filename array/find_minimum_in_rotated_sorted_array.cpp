/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 You may assume no duplicate exists in the array.
 */

#include "header.h"

int findMin(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 1) return nums[0];
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(nums[l]<nums[r]) return nums[l];
        if(nums[m]>nums[l]) l = m+1;
        else r=m;
    }
    return nums[l]<nums[r]?nums[l]:nums[r];
}

int main(){
    vector<int> num = {4, 5, 6, 7, 0, 1, 2};
//    vector<int> num = {3, 1, 2};
    cout<<findMin(num)<<endl;
    return 0;
}
