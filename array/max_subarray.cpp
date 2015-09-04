/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "header.h"

//int maxSubArray(vector<int>& nums) {
//    //dp
//    //O(n) time and space
//    int sz = nums.size();
//    if(sz == 0) return 0;
//    vector<int> arr(sz, 0);
//    arr[0] = nums[0];
//    int res = arr[0];
//    for(int i=1; i<sz; i++){
//        arr[i] = max(arr[i-1]+nums[i], nums[i]);
//        res = max(res, arr[i]);
//    }
//    return res;
//}

int search(vector<int>& nums, int l, int r){
    if(l==r) return nums[l];
    if(l>r) return INT_MIN;
    int m = (l+r)>>1;
    int l_res = search(nums, l, m-1);
    int r_res = search(nums, m+1, r);
    int l_max = nums[m], r_max = nums[m], curr = m;
    int temp = 0;
    for(;curr>=l;curr--){
        temp += nums[curr];
        l_max = max(l_max, temp);
    }
    for(curr=m,temp=0;curr<=r;curr++){
        temp += nums[curr];
        r_max = max(r_max, temp);
    }
    return max(l_max+r_max-nums[m],max(l_res,r_res));
}

int maxSubArray(vector<int>& nums){
    //O(nlogn) time and O(1) space
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    return search(nums, 0, sz-1);
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
