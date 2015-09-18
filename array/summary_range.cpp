/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include "header.h"

void addRange(int l, int r, vector<string>& res){
    if(l == r) res.push_back(to_string(l));
    else res.push_back(to_string(l)+"->"+to_string(r));
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int sz = nums.size();
    if(sz == 0) return res;
    if(sz == 1) return vector<string>(1, to_string(nums[0]));
    int l = 0, r = 1;
    while(r<sz){
        if(nums[r] == nums[r-1]+1) r++;
        else{
            addRange(nums[l], nums[r-1], res);
            l = r++;
        }
    }
    addRange(nums[l], nums[r-1], res);
    return res;
}

int main(){
    int arr[] = {0, 1, 2, 4, 5, 7};
//    int arr[] = {0, 2, 4, 6, 8};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<string> res = summaryRanges(v_arr);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}