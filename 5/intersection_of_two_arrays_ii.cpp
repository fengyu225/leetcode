/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include "header.h"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> s,t;
    vector<int> res;
    for(int i : nums1) s[i]++;
    for(int i : nums2) t[i]++;
    for(auto p : s)
        if(t.find(p.first) != t.end()){
            for(int temp = 0; temp<min(p.second, t[p.first]); temp++)
            res.push_back(p.first);
        }
    return res;
}

int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = intersect(nums1, nums2);
    print_vector<int>(res);
    return 0;
}
