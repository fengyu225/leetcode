/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

#include "header.h"

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    int sz = nums.size();
    if(sz < 2) return false;
    set<long> set;
    for(int i=0; i<sz; i++){
        if(i>k) set.erase(nums[i-k-1]);
        //-t<=nums[i]-x<=t
        auto x = set.lower_bound((long)nums[i]-(long)t);
        if(x!=set.end() && (*x)<=(long)nums[i]+(long)t) return true;
        set.insert(nums[i]);
    }
    return false;
}

int main(){
    int arr[] = {1,2,3,1,3};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<containsNearbyAlmostDuplicate(v_arr,2,1)<<endl;
    return 0;
}