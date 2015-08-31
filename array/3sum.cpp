/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include "header.h"

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for(int i=0; i+2<sz; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k=sz-1;
        vector<int> temp;
        while(j<k){
            int x = nums[i]+nums[j]+nums[k];
            if(x == 0){
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                res.push_back(temp);
                temp.clear();
                j++;
                while(j>i+1 && nums[j] == nums[j-1]) j++;
                k--;
                while(k<sz-1 && nums[k] == nums[k+1]) k--;
            }
            else if(x<0) j++;
            else k--;
        }
    }
    return res;
}

int main(){
    //vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {1, 2, -2, -1};
    vector<vector<int> > res = threeSum(nums);
    for(auto r:res) print_vector<int>(r);
    return 0;
}