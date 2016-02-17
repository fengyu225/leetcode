/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

#include "header.h"

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return (nums[0]<=upper && nums[0]>=lower)?1:0;
    multiset<long> s;
    vector<long> arr(sz, nums[0]);
    for(int i=1; i<sz; i++) arr[i] = arr[i-1]+nums[i];
    int res = (nums[0]<=upper && nums[0]>=lower)?1:0;
    s.insert(nums[0]);
    for(int i=1; i<sz; i++){
        res += (arr[i]<=upper && arr[i]>=lower)?1:0; 
        set<long>::iterator l = s.lower_bound(arr[i]-upper);
        set<long>::iterator u = s.upper_bound(arr[i]-lower);
        if(l != s.end()) res+=distance(l, u);
        s.insert(arr[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {-2, 5, -1};
    cout<<countRangeSum(nums, -2, 2)<<endl;
//    vector<int> nums = {INT_MAX, INT_MIN};
//    cout<<countRangeSum(nums, -1, 0)<<endl;
//    vector<int> nums = {0, 0};
//    cout<<countRangeSum(nums, 0, 0)<<endl;
    return 0;
}