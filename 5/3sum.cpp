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

vector<vector<int> > threeSum(vector<int>& nums){
    vector<vector<int> > res;
    int sz = nums.size();
    if(sz<3) return res;
    sort(nums.begin(), nums.end());
    for(int i=0; i+2<sz; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int target = -1*nums[i], l=i+1, r=sz-1;
        while(l<r){
            if(nums[l]+nums[r] == target){
                vector<int> t;
                t.push_back(nums[i]);
                t.push_back(nums[l]);
                t.push_back(nums[r]);
                res.push_back(t);
                l++;
                while(l<sz && l<r && nums[l] == nums[l-1]) l++;
                r--;
                while(r>=0 && l<r && nums[r] == nums[r+1]) r--;
            }
            else if(nums[l]+nums[r] < target) l++;
            else r--;
        }
    }
    return res;
}

int main(){
//    int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {0, 0, 0, 0, 0};
    int arr[] = {-1, -1, -1, 0, 2};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > r = threeSum(num);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
