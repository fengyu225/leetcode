/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Show Tags
Show Similar Problems
*/

#include "header.h"

class NumArray {
    vector<int> sums;
    int arr_sz = 0;
public:
    NumArray(vector<int> &nums) {
        arr_sz = nums.size();
        sums.resize(arr_sz);
        if(arr_sz>0){
            sums[0] = nums[0];
            for(int i=1; i<arr_sz; i++) sums[i] = sums[i-1]+nums[i];
        }
        for(int i=0; i<arr_sz; i++) cout<<sums[i]<<" ";
        cout<<endl;
    }

    int sumRange(int i, int j) {
        if(arr_sz == 0) return 0;        
        cout<<sums[i]<<" "<<sums[j]<<endl;
        return sums[j]-(i == 0?0:sums[i-1]);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(){
    vector<int> num = {-2, 0, 3, -5, 2, -1};
    NumArray NumArray(num);
    //cout<<NumArray.sumRange(0, 2)<<endl;
    cout<<NumArray.sumRange(2, 5)<<endl;
    //cout<<NumArray.sumRange(0, 5)<<endl;
    return 0;
}