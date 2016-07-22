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
    int sz = nums.size();
    if(sz == 0) return res;
    if(sz == 1) return vector<int>(nums[0]*nums[0]*a+nums[0]*b+c);
    if(a == 0 && b == 0) return vector<int>(sz, c);
    double mid = a!=0?-1*b/(double)a/2.0:(nums[0]+nums[sz-1])/2.0;
    int l = 0, r = sz-1;
    while(l<=r){
        double l_dis = abs((double)nums[l]-mid);
        double r_dis = abs((double)nums[r]-mid);
        if((a!= 0 && l_dis>=r_dis) || (a==0 && b>0)){
            res.push_back(a*nums[l]*nums[l]+b*nums[l]+c);
            l++;
        }
        else if((a != 0 && l_dis<r_dis) || (a==0 && b<0)){
            res.push_back(a*nums[r]*nums[r]+b*nums[r]+c);
            r--;
        }
    }
    if(a>0) reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> nums = {-95,-95,-93,-92,-89,-89,-88,-82,-81,-79,-71,-71,-66,-66,-65,-65,-62,-61,-60,-54,-54,-51,-50,-48,-47,-45,-43,-37,-35,-35,-32,-32,-29,-24,-24,-22,-20,-20,-17,-14,-13,-12,-12,-4,1,8,11,14,16,16,22,24,26,28,28,28,29,30,31,36,44,46,49,60,60,60,62,64,65,73,76,86,87,89,91,92,93,94,94,96,96,97};
    vector<int> res = sortTransformedArray(nums, 41, 45, -89);
    print_vector<int>(res);
    return 0;
}
