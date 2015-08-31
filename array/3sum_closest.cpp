/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "header.h"

int threeSumClosest(vector<int>& nums, int target) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int diff = -1, res;
    for(int i=0; i+2<sz; i++){
        int j = i+1, k=sz-1;
        while(j<k){
            int s = nums[i]+nums[j]+nums[k];
            int x = abs(s-target);
            if(x == 0) return s;
            if(diff == -1 || x<diff){
                diff = x;
                res = s;
            } 
            else if(s<target) j++;
            else k--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    cout<<threeSumClosest(nums, 1)<<endl;
    return 0;
}