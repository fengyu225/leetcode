/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "header.h"

void swap(vector<int>& nums, int l, int r){
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}

int findKthLargest(vector<int>& nums, int k) {
    int sz = nums.size();
    int l = 0, r = sz-1;
    while(l<r){
        int tail = l, curr = l+1;
        while(curr<=r){
            if(nums[curr]>=nums[l]) swap(nums, ++tail, curr);
            curr++;
        }
        swap(nums, tail, l);
        if(k == tail-l+1) return nums[tail];
        else if(k<tail-l+1) r = tail-1;
        else{
            k -= (tail-l+1);
            l = tail+1;
        }
    }
    return nums[l];
}

int main(){
    int arr[] = {3, 2, 1, 5, 6, 4};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<findKthLargest(v_arr, 6)<<endl;
    return 0;    
}