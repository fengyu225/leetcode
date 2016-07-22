/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<int,int>& a, pair<int,int>& b){
            return b.first+b.second > a.first+a.second;            
        }
};

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int> > res;
    int sz1 = nums1.size(), sz2 = nums2.size();
    if(k == 0) return res;
    priority_queue<pair<int,int>, vector<pair<int,int> >, comp> q;
    for(int i=0; i<sz1; i++){
        for(int j=0; j<sz2; j++){
            if(q.size()<k) q.push(make_pair(nums1[i], nums2[j]));
            else if(nums1[i]+nums2[j]<q.top().first+q.top().second){
                q.pop(); 
                q.push(make_pair(nums1[i], nums2[j]));
            }
        }
    }
    for(int i=k-1; i>=0 && q.size() > 0; i--){
        res.push_back(q.top());
        q.pop();
    } 
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    vector<pair<int,int> > res = kSmallestPairs(nums1, nums2, 3);
    for(auto p : res)
        cout<<p.first<<", "<<p.second<<endl;
    return 0;
}
