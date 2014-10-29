/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "header.h"

int threeSumClosest(vector<int> &num, int target) {
    if(num.size()<3) return 0;
    sort(num.begin(), num.end());
    int diff=INT_MAX,res=INT_MAX;
    for(int i=0; i<num.size(); i++){
        int j=i+1,k=num.size()-1;
        while(j<k){
            int sum = num[i]+num[j]+num[k];
            if(sum == target) return sum;
            if(abs(sum-target)<diff){
                diff = abs(sum-target);
                res = sum;
            }
            if(sum<target)
                j++;
            else
                k--;
        }
    }
    return res;
}

int main(){
    int arr[] = {-1, 2, 1, -4};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = threeSumClosest(num, 1);
    printf("%d\n", res);
    return 0;
}
