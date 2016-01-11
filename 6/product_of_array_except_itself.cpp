/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include "header.h"

vector<int> productExceptSelf(vector<int>& nums) {
    int sz = nums.size();
    vector<int> res(sz, 1);
    int l = 1, r = 1;
    for(int i=0; i<sz; i++){
        res[i] *= l;
        res[sz-1-i] *= r;
        l *= nums[i];
        r *= nums[sz-1-i];
    }
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4};
//    int arr[] = {1,0};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = productExceptSelf(v_arr);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}