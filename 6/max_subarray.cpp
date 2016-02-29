/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "header.h"

int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    int last = nums[0], res = nums[0];
    for(int i=1; i<sz; i++){
        int curr = max(last+nums[i], nums[i]);
        res = max(res,curr);
        last = curr;
    }
    return res;
}
    
int main(){
    //int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    int res = maxSubArray(arr);
    printf("%d\n", res);
    return 0;
}
