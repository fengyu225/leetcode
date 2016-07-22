/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

#include "header.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s, t;
    for(int i : nums1) s.insert(i);
    vector<int> res;
    for(int i : nums2)
        if(s.find(i) != s.end()) t.insert(i);
    for(int i : t) res.push_back(i);
    return res;
}

int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = intersection(nums1, nums2);
    print_vector<int>(res);
    return 0;
}
