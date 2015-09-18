/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

#include "header.h"

//[-1,-100,3,99], 3
//[-100,3,99,-1]
//[3,99,-1,-100]

/* method 1 */
//void reverse(vector<int>& nums, int l, int r){
//    while(l<r) swap(nums[l++], nums[r--]);
//}
//
//void rotate(vector<int>& nums, int k) {
//    int sz = nums.size();
//    k = k%sz;
//    if(k == 0) return;
//    reverse(nums, 0, sz-1);
//    reverse(nums, 0, k-1);
//    reverse(nums, k, sz-1);
//}

void rotate(vector<int>& nums, int k) {
    int sz = nums.size();
    k = k%sz;
    if(k == 0) return;
}

int main(){
    //int arr[] = {1,2,3,4,5,6,7};
//    int arr[] = {1,2};
    vector<int> nums = {1, 2, 3};
    rotate(nums, 1);
    print_vector<int>(nums);
    return 0;
}