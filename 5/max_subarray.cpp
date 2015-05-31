/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "header.h"

int maxSubArray(vector<int>& nums){
    return 0;
}

int main(){
    //int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    int res = maxSubArray(arr);
    printf("%d\n", res);
    return 0;
}
