/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

#include "header.h"
static bool compair(pair<long,int> i, pair<long,int> j)
{
    return i.first<j.first;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<long,int>> v;
    for(int i=0; i<nums.size(); i++)
        v.push_back(pair<long,int>((long)nums[i],i));
    sort(v.begin(),v.end(),compair);
    int j;
    for(int i=0; i<v.size(); i++)
    {
        j = i+1;
        while(j<v.size() && v[j].first-v[i].first<=t)
        {
            if(abs(v[j].second - v[i].second) <= k) return true;
            j++;
        }
    }
    return false;
}

/*
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
*/

int main(){
    //int arr[] = {1,2,3,1,3};
    int arr[] = {-1, -1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    //cout<<containsNearbyAlmostDuplicate(v_arr,2,1)<<endl;
    cout<<containsNearbyAlmostDuplicate(v_arr,1,0)<<endl;
    return 0;
}