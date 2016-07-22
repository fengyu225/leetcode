/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

#include "header.h"

int findPeakElement(vector<int>& nums){
    //log(n) solution
    int sz = nums.size();
    if(sz == 1) return 0;
    int l = 0, r = sz-1, m=(l+r)/2;
    while(l<r){
        m = (l+r)/2;
        if((m == 0 || nums[m-1]<nums[m]) && (m==sz-1 || nums[m+1]<nums[m])) return m;
        else if(nums[m]<nums[m+1]) l = m+1;
        else r=m-1;
    }
    return l;
}

//int findPeakElement(vector<int>& nums){
//    int sz = nums.size();
//    if(sz == 1) return nums[0];
//    vector<bool> arr(sz, false);
//    for(int i=0; i<sz; i++) if(i == 0 || nums[i]>nums[i-1]) arr[i] = true;
//    for(int i=sz-1; i>=0; i--){
//        if(i == sz-1 || nums[i]>nums[i+1]) arr[i] = arr[i]&true;
//        else arr[i] = false;
//    }
//    int res = 0;
//    for(int i=0; i<sz; i++){
//        if(arr[i]){
//            res = i;
//            break;
//        }
//    }
//    return res;
//}

int main(){
    int arr[] = {1, 2, 3, 4};
//    int arr[] = {2, 1};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<findPeakElement(v)<<endl;
    return 0;
}