/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

#include "header.h"

class NumArray {
    int sz;
    vector<int> sums;
    vector<int>* nums_ptr;
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        nums_ptr = &nums;
        sums.assign(sz+1, 0);
        for(int i=1; i<=sz; i++){
            _update(i, nums[i-1]); 
        }
    }

    void _update(int i, int val) {
        while(i<=sz){
            sums[i] += val;
            i += (i & -i);
        } 
    }

    void update(int i, int val){
        _update(i+1, val-(*nums_ptr)[i]);
        (*nums_ptr)[i] = val;
    }

    int _sumRange(int i) {
        int res = 0;
        while(i>0){
            res += sums[i];
            i -= (i & -i);
        } 
        return res;
    }

    int sumRange(int i, int j){
        return i==j?(*nums_ptr)[i]:_sumRange(j+1)-_sumRange(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main(){
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;
    numArray.update(1,2);
    cout<<numArray.sumRange(0, 2)<<endl;
    return 0;
}