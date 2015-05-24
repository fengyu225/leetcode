/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include "header.h"

int removeDuplicates(vector<int>& nums) {
    int sz = nums.size(), curr = 0, next = 1;
    if(sz < 2) return sz;
    while(next<sz){
        if(nums[next] == nums[curr]){
            next++;
            continue;
        }
        nums[++curr] = nums[next++];
    }
    return curr+1;
}

int main(){
    int A[] = {1, 1, 2};
    vector<int> a_arr(A, A+sizeof(A)/sizeof(A[0]));
    int res =removeDuplicates(a_arr);
    printf("%d\n", res);
    for(int i=0; i<res; i++)
        printf("%d ", a_arr[i]);
    printf("\n");
    return 0;
}
