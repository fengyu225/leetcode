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
public:
    NumArray(vector<int> &nums) {
        
    }

    int sumRange(int i, int j) {
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray NumArray(nums);
    cout<<NumArray.sumRange(0, 1)<<endl;
    cout<<NumArray.sumRange(1, 2)<<endl;
    return 0;
}