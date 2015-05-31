/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "header.h"

/* using dp
int maxSubArray(vector<int>& nums){
    int sz = nums.size();
    int arr[sz];
    arr[0] = nums[0];
    int res = INT_MIN;
    for(int i=1; i<sz; i++){
        if(arr[i-1]>=0) arr[i] = arr[i-1]+nums[i];
        else arr[i] = nums[i];
        res = max(arr[i], res);
    }
    return res;
}
*/
int maxSubArray(vector<int>& nums){

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
