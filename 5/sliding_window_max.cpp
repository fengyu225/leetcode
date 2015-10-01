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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz<=1 || k == 1) return nums;
    deque<int> q;
    k = min(k, sz);
    for(int i=0; i<k; i++){
        while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
        q.push_back(i);
    }
    vector<int> res;
    res.push_back(nums[q.front()]);
    for(int i=k; i<sz; i++){
        while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front()<i-k+1) q.pop_front();
        res.push_back(nums[q.front()]);
    }
    return res;
}   

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = maxSlidingWindow(v_arr, 3);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}