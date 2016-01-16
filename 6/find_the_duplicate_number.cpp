/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
*/

#include "header.h"

void search(vector<int>& nums, int& lt, int& gt, int& eq, int m){
    for(int c:nums){
        if(c == m) eq++;
        else if(c<m) lt++;
        else gt++;
    }
}

int findDuplicate(vector<int>& nums) {
    int n = nums.size();    
    n-=1;
    int l = 1, r = n;
    while(l<r){
        int m = l+(r-l)/2;
        int lt = 0, gt=0, eq = 0;
        search(nums, lt, gt, eq, m);
        if(eq>1) return m;
        if(lt>m-1) r=m-1;
        else l=m+1;
    }
    return l;
}

int main(){
//    vector<int> nums = {1, 2, 3, 4, 5, 3};
//    vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {1, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 16, 16, 16, 16, 16, 16, 17, 19};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}