/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

#include "header.h"

void count(vector<int>& nums, int a, int b, int& a_cnt, int& b_cnt){
    a_cnt = b_cnt = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == a) a_cnt++;
        if(nums[i] == b) b_cnt++;
    }
}

vector<int> majorityElement(vector<int>& nums){
    vector<int> res;
    int sz = nums.size();
    if(sz == 0) return res;
    int a=-1, b=-1, a_cnt = 0, b_cnt=0;
    for(int i=0; i<sz; i++){
        if(a==nums[i]) a_cnt++;
        else if(b == nums[i]) b_cnt++;
        else if(a_cnt == 0){
            a=nums[i];
            a_cnt++;
        }
        else if(b_cnt == 0){
            b=nums[i];
            b_cnt++;
        }
        else{
            a_cnt--;
            b_cnt--;
        }
    }
    count(nums, a, b, a_cnt, b_cnt);
    if(a_cnt>sz/3) res.push_back(a);
    if(b_cnt>sz/3) res.push_back(b);
    return res;
}

int main(){
    //int arr[] = {5, 2, 4, 4, 4, 4, 5, 5, 5};
    //int arr[] = {1,2,3,4,4,4};
    int arr[] = {0, -1, 2, -1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = majorityElement(v_arr);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}