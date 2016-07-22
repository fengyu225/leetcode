/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "header.h"

int findKthLargest(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz == 1) return nums[0];
    int l = 0, r = sz-1, tail, curr;
    while(l<r){
        tail = l, curr = l+1;
        while(curr<=r){
            if(nums[curr]>nums[l]) swap(nums[++tail], nums[curr]);
            curr++;
        }
        swap(nums[tail], nums[l]);
        if(tail-l+1 == k) return nums[tail];
        else if(tail-l+1<k){
            k-=(tail-l+1);
            l = tail+1;
        }
        else r=tail;
    }
    return nums[l];
}

int main(){
    int arr[] = {3, 2, 1, 5, 6, 4};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<findKthLargest(v_arr, 1)<<endl;
    return 0;    
}