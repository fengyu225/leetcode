/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include "header.h"

int jump(vector<int>& nums) {
    int sz = nums.size();
    if(sz <= 1) return 0;
    int l = 0, r = 0;
    int res = 0;
    while(1){
        int new_r=-1;
        for(int i=l; i<=r; i++) new_r = max(new_r, i+nums[i]);
        res++;
        if(new_r == r) return -1;
        if(new_r>=sz-1) return res;
        l = r+1;
        r = new_r;
    }
    return res;
}

int main(){
    int A[] = {2, 3, 1, 1, 4};
    vector<int> arr(A, A+sizeof(A)/sizeof(A[0]));
    int res = jump(arr);
    printf("%d\n", res);
    return 0;
}
