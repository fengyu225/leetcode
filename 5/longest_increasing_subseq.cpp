/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

#include "header.h"

//int lengthOfLIS(vector<int>& nums) {
//    //dp
//    int sz = nums.size(), res = 1;
//    if(sz == 0) return 0;
//    vector<int> arr(sz, 1);
//    for(int i=1; i<sz; i++){
//        int temp = 1;
//        for(int j=0; j<i; j++){
//            if(nums[j]<nums[i]) temp = max(temp, arr[j]+1);
//        }
//        arr[i] = temp;
//        res = max(res, arr[i]);
//    }
//    return res;
//}

int find(vector<int>& nums, vector<int>& m, int i){
    int sz = m.size();
    int l = 0, r = sz-1;
    while(l+1<r){
        int x = l+(r-l)/2;
        if(m[x] == -1 || nums[m[x]]>=nums[i]) r = x-1;
        else l = x;
    }
    return m[r] != -1 && nums[m[r]]<nums[i]?r:l;
}

int lengthOfLIS(vector<int>& nums) {
    //nlogn using binary search
    //http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
    //https://en.wikipedia.org/wiki/Longest_increasing_subsequence
    //m[i]=j means nums[j] is the current minimal ending integers in an non-decreasing array of length i
    int sz = nums.size();
    vector<int> m(sz, -1);
    int res = 1;
    for(int i=0; i<sz; i++){
        if(m[0] == -1 || nums[m[0]]>=nums[i]) m[0] = i;
        else{
            int x = find(nums, m, i);
            m[x+1] = i;
        }
    }         
    for(res=0; res<sz && m[res]!=-1; res++);
    return res;
}

int main(){
    vector<int> nums = {2,2};
//    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//    vector<int> nums = {9, 10};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}