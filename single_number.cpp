/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include "header.h"

/*
return nums.size() == 0 ? 0 : accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
*/

int singleNumber(vector<int>& nums){
    int res = 0;
    for(int i=0; i<nums.size(); i++) res = res^nums[i];
    return res;
}

int main(){
    int A[5] = {2, 2, 3, 3, 10};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    int r = singleNumber(arr);
    printf("%d\n", r);
    return 0;
}
