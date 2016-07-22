/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include "header.h"

int maxProduct(vector<int>& nums){
    int sz = nums.size();
    if(sz == 1) return nums[0];
    int res = nums[0];
    vector<int> lp(sz, INT_MAX);
    vector<int> sn(sz, INT_MIN);
    if(nums[0]>=0) lp[0] = nums[0];
    else sn[0] = nums[0];
    for(int i=1; i<sz; i++){
        if(nums[i]>=0){
            lp[i]=lp[i-1]==INT_MAX?nums[i]:max(nums[i],nums[i]*lp[i-1]);
            sn[i]=sn[i-1]==INT_MIN?INT_MIN:min(nums[i],nums[i]*sn[i-1]);
        } 
        else{
            lp[i]=sn[i-1]==INT_MIN?INT_MAX:max(nums[i],nums[i]*sn[i-1]);
            sn[i]=lp[i-1]==INT_MAX?nums[i]:min(nums[i],nums[i]*lp[i-1]);
        }
        if(lp[i] != INT_MAX) res = max(res, lp[i]);
    }
    return res;
}

int main(){
    //int arr[] = {2, 3, -2, 4};
    int arr[] = {0,2};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<maxProduct(v)<<endl;
    return 0;
}
