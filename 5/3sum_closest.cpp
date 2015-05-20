/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "header.h"

int threeSumClosest(vector<int>& num, int target) {
}

int main(){
    int arr[] = {-1, 2, 1, -4};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = threeSumClosest(num, 1);
    printf("%d\n", res);
    return 0;
}
