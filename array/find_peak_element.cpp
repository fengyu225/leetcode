/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

#include "header.h"

int findPeakElement(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 1) return 0;
    if(sz == 2) return nums[0]>nums[1]?0:1;
    int l = 0, r = sz-1, m;
    while(l+1<r){
        m = (l+r)/2;
        if(nums[m]>nums[m-1] && nums[m]>nums[m+1]) return m;
        if(nums[m]<nums[m+1]) l = m+1;
        else r = m-1;
    }
    return nums[l]>nums[r]?l:r;
}

int main(){
    int arr[] = {3, 4, 3, 2, 1};
//    int arr[] = {1, 2, 3, 1};
//    int arr[] = {3, 2, 1};
//    int arr[] = {2, 1};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<findPeakElement(v)<<endl;
    return 0;
}