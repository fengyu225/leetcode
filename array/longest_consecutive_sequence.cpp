/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include "header.h"

int longestConsecutive(vector<int>& nums) {
    int sz = nums.size();
    unordered_map<int,pair<int,int> > m;
    int res = 1;
    for(int i=0; i<sz; i++){
        if(m.find(nums[i]) != m.end()) continue;
        m[nums[i]] = make_pair(0, 0);
        if(m.find(nums[i]-1) != m.end()){
            m[nums[i]].first = m[nums[i]-1].first+1;
            m[nums[i]].second = max(0, m[nums[i]-1].second-1);
            if(m[nums[i]].first != 0)
                m[nums[i]-m[nums[i]].first].second = m[nums[i]].first;
        }
        if(m.find(nums[i]+1) != m.end()){
            m[nums[i]].second = max(m[nums[i]].second, m[nums[i]+1].second+1);
            if(m[nums[i]].second != 0) 
                m[nums[i]+m[nums[i]].second].first = m[nums[i]].second+m[nums[i]].first;
            if(m[nums[i]].first != 0) 
                m[nums[i]-m[nums[i]].first].second = m[nums[i]].first+m[nums[i]].second;
        }
        res = max(res, m[nums[i]].second+m[nums[i]].first+1);
    }
    return res;
}

int main(){
    //vector<int> num = {100, 4, 200, 1, 3, 2};
    vector<int> num = {1, 3, 5, 2, 4};
    printf("%d\n", longestConsecutive(num));
    return 0;
}
