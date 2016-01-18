/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include "header.h"

int maxProduct(vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return 0;
    int largest = nums[0], smallest=  nums[0], res = nums[0];
    for(int i=1; i<sz; i++){
        int o_l = largest, o_s = smallest;
        largest = max(nums[i], max(o_l*nums[i], o_s*nums[i]));
        smallest = min(nums[i], min(o_l*nums[i], o_s*nums[i]));
        res = max(largest,res);
        o_l = largest;
        o_s = smallest;
    }
    return res;
}

int main(){
//    int arr[] = {2, 3, -2, 4};
    //int arr[] = {0,2};
    int arr[] = {-4,-3,-2};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<maxProduct(v)<<endl;
    return 0;
}
