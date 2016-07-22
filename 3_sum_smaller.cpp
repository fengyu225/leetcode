/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Could you solve it in O(n2) runtime?
*/

#include "header.h"

int threeSumSmaller(vector<int>& nums, int target){
    int sz = nums.size();
    if(sz<3) return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i=0; i+2<sz; i++){
        int l = i+1, r=sz-1;
        while(l<r){
            int temp = nums[i]+nums[l]+nums[r];
            if(temp<target){
                res += (r-l);
                l++;
            }
            else r--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-2, 0, 1, 3};
    cout<<threeSumSmaller(nums, 2)<<endl;
    return 0;
}