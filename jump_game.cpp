/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include "header.h"

bool canJump(vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return true;
    int l = -1, r = 0;
    while(r<sz-1){
        int new_r = l;
        for(int i=l+1; i<=r; i++)
            new_r = max(new_r, nums[i]+i);
        int new_l = r;
        if(new_l == new_r) return false;
        l = new_l;r=new_r;
    }
    return true;
}

int main(){
    //int A[] = {2, 3, 1, 1, 4};
    //int A[] = {2, 1, 0, 0};
    int A[] = {0};
    vector<int> arr(A, A+sizeof(A)/sizeof(A[0]));
    bool res = canJump(arr);
    printf("%s\n", res?"true":"false");
    return 0;
}
