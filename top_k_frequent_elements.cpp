/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<int,int>& l, pair<int,int>& r){
            return r.second>l.second;          
        }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int,int> m;
    for(int i : nums) m[i]++;
    priority_queue<pair<int,int>, vector<pair<int,int> >, comp> q;
    for(auto p : m) q.push(p);
    for(int i=0; i<k; i++){
        res.push_back(q.top().first);
        q.pop();
    }
    return res;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    print_vector<int>(res);
    return 0;
}
