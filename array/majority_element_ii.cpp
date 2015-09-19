/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

#include "header.h"

vector<int> majorityElement(vector<int>& nums) {
    int sz = nums.size();
    vector<int> res;
    if(sz == 0) return res;
    if(sz == 1) return vector<int>(1, nums[0]);
    int l = -1, r = -1, l_cnt = 0, r_cnt = 0;
    for(int i=0; i<sz; i++){
        if(l >=0 && nums[i] == nums[l]){
            l_cnt++;
        }
        else if(r>=0 && nums[i] == nums[r]) r_cnt++;
        else if(l_cnt == 0){
            l = i;
            l_cnt++;
        } 
        else if(r_cnt == 0){
            r = i;
            r_cnt++;
        }
        else{
            l_cnt--;
            r_cnt--;
        }
    }
    int a = 0, b = 0;
    for(int i=0; i<sz; i++){
        if(l>=0 && nums[i] == nums[l]) a++;
        if(r>=0 && nums[i] == nums[r]) b++;
    }
    if(a>sz/3) res.push_back(nums[l]);
    if(b>sz/3) res.push_back(nums[r]);
    return res;
}

int main(){
    //int arr[] = {5, 2, 4, 4, 4, 4, 5, 5, 5};
    //int arr[] = {1,2,3,4,4,4};
    //int arr[] = {0, -1, 2, -1};
    int arr[] = {2,2};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = majorityElement(v_arr);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}