/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include "header.h"

int firstMissingPositive(vector<int>& nums) {
    int sz = nums.size();
    
}

int main(){
    //int arr0[] = {1, 1}; //3
    int arr0[] = {2,1}; //3
//    int arr0[] = {1, 2, 0}; //3
//    int arr0[] = {1000,-1}; //3
    int arr1[] = {3, 4, -1, 1}; //2 
    vector<int> arr0_v(arr0,arr0+sizeof(arr0)/sizeof(arr0[0]));
    vector<int> arr1_v(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]));
    printf("%d\n", firstMissingPositive(arr0_v));
    printf("%d\n", firstMissingPositive(arr1_v));
    return 0;
}
