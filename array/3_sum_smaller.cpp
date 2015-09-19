/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Could you solve it in O(n2) runtime?
*/

#include "header.h"

int threeSumSmaller(vector<int>& nums, int target) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i=0; i+3<=sz; i++){
        int j = i+1, k = sz-1;
        while(j<k){
            int temp = nums[i]+nums[j]+nums[k];
            if(temp>=target) k--;
            else{
                res += (k-j);
                j++;
            }
        }
    }
    return res;
}

int main(){
    //vector<int> nums = {-2, 0, 1, 3};
    //cout<<threeSumSmaller(nums, 2)<<endl;
    vector<int> nums = {1, 1, -2};
    cout<<threeSumSmaller(nums, 1)<<endl;
    return 0;
}