/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "header.h"

/* using heap */
//class comp{
//    public:
//        bool operator() (int a, int b){
//            return a<b;
//        }
//};
//
//int findKthLargest(vector<int>& nums, int k) {
//    priority_queue<int,vector<int>,comp> q;
//    for(int i:nums) q.push(i);
//    for(int i=0; i<k-1; i++) q.pop();
//    return q.top();
//}

/* quick select */
int findKthLargest(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    int l = 0, r = sz-1, m = k;
    while(l<r){
        int temp=l;
        for(int i=l+1; i<=r; i++)
            if(nums[i]>nums[l]) swap(nums[i], nums[++temp]);
        swap(nums[temp], nums[l]);
        if(temp-l+1 == m) return nums[temp];
        else if(m>temp-l+1){
            m -= temp-l+1;
            l=temp+1;
        }
        else r=temp-1;
    }
    return nums[l];
}

int main(){
//    vector<int> arr = {3, 2, 1, 5, 6, 4};
//    vector<int> v_arr;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 1)<<endl;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 2)<<endl;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 3)<<endl;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 4)<<endl;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 5)<<endl;
//    v_arr = arr;
//    cout<<findKthLargest(v_arr, 6)<<endl;
    vector<int> arr = {7, 6, 5, 4, 3, 2, 1};
    cout<<findKthLargest(arr, 5)<<endl;
    return 0;    
}