/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

#include "header.h"

void push(vector<string>& res, int lower, int upper){
    if(lower>upper) return;
    if(lower == upper) res.push_back(to_string(lower));
    else res.push_back(to_string(lower)+"->"+to_string(upper));
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper){
    vector<string> res;
    int sz = nums.size();
    if(sz == 0){
        push(res, lower, upper);
        return res;
    }
    if(lower<nums[0]) push(res, lower, nums[0]-1);
    int start = nums[0], end = nums[0];
    for(int i=1; i<sz; i++){
        if(nums[i]-end<2) end = nums[i];
        else{
            push(res, end+1, nums[i]-1);
            start = end = nums[i];
        }
    }
    push(res, end+1, upper);
    return res;
}

int main(){
    int arr[] = {0, 1, 3, 50, 75};
    //int arr[] = {-1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<string> res = findMissingRanges(v_arr, 0, 99);
    //vector<string> res = findMissingRanges(v_arr, -2, -1);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}