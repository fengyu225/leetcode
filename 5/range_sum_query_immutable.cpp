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

/* naive approach 
class NumArray {
    vector<vector<int> >* sums;
    int arr_sz = 0;
public:
    NumArray(vector<int> &nums) {
        arr_sz = nums.size();
        sums = new vector<vector<int> >(arr_sz, vector<int>(arr_sz, 0));
        if(arr_sz>0){
            for(int i=0;i<arr_sz; i++){
                (*sums)[i][i] = nums[i];
                for(int j=i+1; j<arr_sz; j++) (*sums)[i][j] = (*sums)[i][j-1]+nums[j];
            }
        }
    }

    int sumRange(int i, int j) {
        if(arr_sz == 0) return 0;        
        return (*sums)[i][j];
    }
};
*/

class NumArray {
    vector<vector<int> >* sums;
    int arr_sz = 0;
public:
    NumArray(vector<int> &nums) {
        arr_sz = nums.size();
        sums = new vector<vector<int> >(arr_sz, vector<int>(arr_sz, 0));
        if(arr_sz>0){
            for(int i=0;i<arr_sz; i++){
                (*sums)[i][i] = nums[i];
                for(int j=i+1; j<arr_sz; j++) (*sums)[i][j] = (*sums)[i][j-1]+nums[j];
            }
        }
    }

    int sumRange(int i, int j) {
        if(arr_sz == 0) return 0;        
        return (*sums)[i][j];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(){
    //vector<int> num = {-2, 0, 3, -5, 2, -1};
    vector<int> num = {-2};
    NumArray NumArray(num);
    cout<<NumArray.sumRange(0, 0)<<endl;
    //cout<<NumArray.sumRange(0, 2)<<endl;
    //cout<<NumArray.sumRange(2, 5)<<endl;
    //cout<<NumArray.sumRange(0, 5)<<endl;
    return 0;
}