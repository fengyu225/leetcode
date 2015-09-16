/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

#include "header.h"

int findPeakElement(vector<int>& nums) {

}

int main(){
    int arr[] = {1, 2, 3, 4};
//    int arr[] = {2, 1};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<findPeakElement(v)<<endl;
    return 0;
}