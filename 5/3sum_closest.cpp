/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "header.h"

int threeSumClosest(vector<int>& num, int target) {
    sort(num.begin(), num.end());
    int sz = num.size();
    int res = num[0]+num[1]+num[2];
    for(int l=0; l+2<sz; l++){
        if(l>0 && num[l]==num[l-1]) continue;
        int m = l+1, r=sz-1;
        while(m<r){
            int x = num[l]+num[m]+num[r];
            if(x == target) return x;
            if(abs(x-target)<abs(res-target)){
                res = x;
            }
            if(x<target) m++;
            else r--;
        }
    }
    return res;
}

int main(){
    int arr[] = {-1, 2, 1, -4};
    //{-4, -1, 1, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = threeSumClosest(num, 1);
    printf("%d\n", res);
    return 0;
}
