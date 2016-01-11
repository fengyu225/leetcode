/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

#include "header.h"

// using deque to maintain a non-increasing seq 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz == 0) return vector<int>();
    int l = 0, r = 1;
    deque<int> q;
    q.push_back(0);
    vector<int> res;
    while(r<sz){
        if(r-l == k) res.push_back(nums[q.front()]); 
        while(!q.empty() && nums[q.back()]<nums[r]) q.pop_back();
        q.push_back(r);
        if(r-l==k){
            while(!q.empty() && q.front()<=l) q.pop_front();
            l++;
        }
        r++;
    }
    if(!q.empty()) res.push_back(nums[q.front()]);
    return res;
}   

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = maxSlidingWindow(v_arr, 1);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}