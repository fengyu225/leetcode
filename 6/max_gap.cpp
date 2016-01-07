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
    int l=INT_MAX, r=INT_MIN;
    for(int i=0; i<sz; i++){
        l = min(l, nums[i]);
        r = max(r, nums[i]);
    }
    if(l == r) return 0;
    int gap = (int)ceil((r-l)/(sz-1));
    unordered_map<int,pair<int,int> > m;
    /* m:
     9: 9 9
     7: 8 8
     5: 5 5
     3: -1 -1
     1: 1 2
     */
    cout<<"abc";
    for(int i=0; i<sz; i++){
        int lower = (nums[i]-l)/gap*gap+l;
        if(m.find(lower) == m.end()) m[lower] = make_pair(nums[i], nums[i]);
        else{
            m[lower].first = min(m[lower].first, nums[i]);
            m[lower].second = max(m[lower].second, nums[i]);
        }
    }
    int res = -1;
    int i = l, j = l+gap;
    while(j<=r && m.find(j) == m.end()) j+=gap;
    while(j<=r){
        res = max(res, m[j].first-m[i].second);
        i = j;
        j += gap;
        while(j<=r && m.find(j) == m.end()) j+=gap;
    }
    return res;
}

/*
https://leetcode.com/discuss/34289/pigeon-hole-principle
int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if(n<=1) return 0;
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        double len = double(maxE-minE)/double(n-1);
        vector<int> maxA(n,INT_MIN);
        vector<int> minA(n,INT_MAX);
        for(int i=0; i<n; i++) {
            int index = (nums[i]-minE)/len;
            maxA[index] = max(maxA[index],nums[i]);
            minA[index] = min(minA[index],nums[i]);
        }
        int gap = 0, prev = maxA[0];
        for(int i=1; i<n; i++) {
            if(minA[i]==INT_MAX) continue;
            gap = max(gap,minA[i]-prev);
            prev = maxA[i];
        }
        return gap;
    } 
*/

int main(){
    //vector<int> nums = {8, 1, 5, 9, 2};
    vector<int> nums = {1,1,1,1};
    //1 2 5 8 9
    cout<<maximumGap(nums)<<endl;
    return 0;
}