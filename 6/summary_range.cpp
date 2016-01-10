/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include "header.h"

void addRange(vector<string>& res, int a, int b){
    if(b<a) return;
    if(a == b) res.push_back(to_string(a));
    else res.push_back(to_string(a)+"->"+to_string(b));
}

vector<string> summaryRanges(vector<int>& nums){
    int sz = nums.size();
    if(sz == 0) return vector<string>();
    int l = 0, r = 1;
    vector<string> res;
    while(l<sz){
        if(r==sz || nums[r]>nums[r-1]+1){
            addRange(res, nums[l], nums[r-1]);
            l = r++;
        } 
        else r++;
    }
    return res;
}

int main(){
    vector<int> arr = {0, 1, 2, 4, 5, 7};
    //vector<int> arr = {0, 2, 4, 6, 8};
    vector<string> res = summaryRanges(arr);
    print_vector<string>(res);
    return 0;
}