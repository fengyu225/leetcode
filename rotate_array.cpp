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

void reverse(vector<int>& nums, int l, int r){
    if(l<=r) return;
    while(l<r){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
}

void rotate(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz <=1 || k==0 || (k>=sz && k%sz==0)) return;
    k = k%sz;
    if(sz == 2 && k==1) {reverse(nums,0,1);return;}
    reverse(nums,0,sz-1);
    reverse(nums,0,k-1);
    reverse(nums,k,sz-1);
}

int main(){
    //int arr[] = {1,2,3,4,5,6,7};
    int arr[] = {1,2};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    rotate(nums, 1);
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}