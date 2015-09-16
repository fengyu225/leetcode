/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include "header.h"

int maxProduct(vector<int>& nums) {
    int sz = nums.size();

}

int main(){
    //int arr[] = {2, 3, -2, 4};
    int arr[] = {0,2};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<maxProduct(v)<<endl;
    return 0;
}
