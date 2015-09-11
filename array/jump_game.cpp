/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include "header.h"

bool canJump(vector<int>& nums) {
    int sz = nums.size();
    int l = 0, r = 0;
    while(1){
        int new_r = r;
        for(int i=l; i<=r; i++) new_r = max(new_r, i+nums[i]);
        if(new_r>=nums.size()-1) break; 
        if(new_r == r) return false;
        l = r+1;
        r = new_r;
    }
    return true;
}

int main(){
    vector<int> arr = {2, 3, 1, 1, 4};
    //vector<int> arr = {2, 1, 0, 0};
    //vector<int> arr = {0};
    bool res = canJump(arr);
    printf("%s\n", res?"true":"false");
    return 0;
}
