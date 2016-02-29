/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include "header.h"

int maxProduct(vector<int>& nums){
    int sz = nums.size();
    int large = nums[0], small = nums[0], res = nums[0];
    for(int i=1; i<sz; i++){
        int new_large = max(nums[i], max(large*nums[i], small*nums[i]));
        int new_small = min(nums[i], min(large*nums[i], small*nums[i]));
        res = max(res, new_large);
        large = new_large;
        small = new_small;
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
