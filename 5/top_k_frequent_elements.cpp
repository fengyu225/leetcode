/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include "header.h"

vector<int> topKFrequent(vector<int>& nums, int k) {
    return nums;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    print_vector<int>(res);
    return 0;
}
