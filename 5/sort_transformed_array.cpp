/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

#include "header.h"

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> res;
    double mid = -1*b/a/2.0;
    int sz = nums.size();
    int l = 0, r = sz-1;
    while(l<=r){
        double l_dis = abs(nums[l]-mid);
        double r_dis = abs(nums[r]-mid);
        if(l_dis>=r_dis){
            res.push_back(a*nums[l]*nums[l]+b*nums[l]+c);
            l++;
        }
        else{
            res.push_back(a*nums[r]*nums[r]+b*nums[r]+c);
            r--;
        }
    }
    if(a>0) reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> nums = {-4, -2, 2, 4};
    vector<int> res = sortTransformedArray(nums, 1, 3, 5);
    print_vector<int>(res);
    return 0;
}
