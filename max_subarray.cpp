/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "header.h"

/* using dp
*/
int maxSubArray(vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return 0;
    int max_so_far = nums[0], max_ending = nums[0];
    for(int i=1; i<sz; i++){
        max_ending = max(nums[i], max_ending+nums[i]);
        max_so_far = max(max_ending, max_so_far);
    }
    return max_so_far;
}

//int search(vector<int>& nums, int l, int r){
//    if(l>r) return INT_MIN;
//    if(l == r) return nums[l];
//    int m = (l+r)/2;
//    int l_res = search(nums, l, m-1);
//    int r_res = search(nums, m+1, r);
//    int l_max = INT_MIN;
//    int r_max = INT_MIN;
//    int curr = m-1, sum=nums[m];
//    while(curr>=0){
//        sum += nums[curr];
//        l_max=max(sum, l_max);
//        curr--;
//    }
//    curr = m+1, sum=nums[m];
//    while(curr<nums.size()){
//        sum += nums[curr];
//        r_max = max(sum, r_max);
//        curr++;
//    }
//    return max(max(l_res, r_res), l_max+r_max-nums[m]);
//}
//
//int maxSubArray(vector<int>& nums){
//    int sz = nums.size();
//    if(sz == 1) return nums[0];
//    return search(nums, 0, sz-1);
//}
    
int main(){
    //int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    int res = maxSubArray(arr);
    printf("%d\n", res);
    return 0;
}
