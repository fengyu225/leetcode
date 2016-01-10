/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

#include "header.h"

vector<int> majorityElement(vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return vector<int>();
    if(sz == 1) return vector<int>(1, nums[0]);
    int c1_cnt = 0, c2_cnt = 0, c1 = -1, c2 = -1;
    for(int i=0; i<sz; i++){
        if(c1>=0 && nums[c1] == nums[i]) c1_cnt++;
        else if(c2>=0 && nums[c2] == nums[i]) c2_cnt++;
        else{
            if(c1_cnt == 0){
                c1 = i;
                c1_cnt++;
            }
            else if(c2_cnt == 0){
                c2 = i;
                c2_cnt++;
            }
            else{
                c1_cnt--;
                c2_cnt--;
            }
        }
    }
    c1_cnt = c2_cnt = 0;
    for(int i:nums){
        if(c1>=0 && nums[c1] == i) c1_cnt++;
        if(c2>=0 && nums[c2] == i) c2_cnt++;
    }
    vector<int> res;
    if(c1_cnt>sz/3) res.push_back(nums[c1]);
    if(c2_cnt>sz/3) res.push_back(nums[c2]);
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