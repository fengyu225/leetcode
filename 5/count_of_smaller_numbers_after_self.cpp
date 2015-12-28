/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0].
*/

#include "header.h"

vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    vecotr<int> res;
    return res;
}

int main(){
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);
    print_vector<int>(res);
    return 0;
}