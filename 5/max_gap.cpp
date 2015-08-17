/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

#include "header.h"

int maximumGap(vector<int>& nums) {
    int sz = nums.size();
    if(sz<2) return 0;
    if(sz == 2) return nums[1]-nums[0];
    int small = -1, large = -1;
    for(int i=0; i<sz; i++){
        if(small == -1 || nums[small]>nums[i]) small = i;
        if(large == -1 || nums[large]<nums[i]) large = i;
    }
    int x = (int)ceil(((double)nums[large]-(double)nums[small])/(sz-1));
    unordered_map<int,pair<int,int> > m;
    for(int i=0; i<sz; i++){
        int idx = (nums[i]-nums[small])/x*x+nums[small];
        if(m.find(idx) == m.end()) m[idx] = make_pair(nums[i], nums[i]);
        else{
            if(nums[i]<m[idx].first) m[idx].first = nums[i];
            else if(nums[i]>m[idx].second) m[idx].second = nums[i];
        }
    }
    int res = INT_MIN;
    int i = nums[small], j=nums[small]+x;
    while(j<=nums[large] && m.find(j) == m.end()) j+=x;
    while(j<=nums[large]){
        res = max(res, m[j].first-m[i].second);
        i = j;
        j += x;
        while(j<=nums[large] && m.find(j) == m.end()) j+=x;
        if(j>nums[large]) break;
    }
    return res;
}

int main(){
    vector<int> nums = {8, 1, 5, 9, 2};
    cout<<maximumGap(nums)<<endl;
    return 0;
}