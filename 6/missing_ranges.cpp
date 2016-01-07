/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

#include "header.h"

void addRange(vector<string>& res, int a, int b){
    if(a>b) return;
    else if(a == b) res.push_back(to_string(a));
    else res.push_back(to_string(a)+"->"+to_string(b));
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int sz = nums.size();
    vector<string> res;
    if(sz == 0) return vector<string>(1, lower == upper?to_string(lower):(to_string(lower)+"->"+to_string(upper)));
    int begin, end;
    if(nums[0]>lower) addRange(res, lower, nums[0]-1);
    begin = end = nums[0];
    for(int i=1; i<sz; i++){
        if(nums[i]<=end) continue;
        if(nums[i] == end+1) end++;
        else{
            addRange(res, end+1, nums[i]-1);
            begin = end = nums[i];
        }
    }
    if(end == upper) return res;
    addRange(res, end+1, upper);
    return res;
}

int main(){
    //int arr[] = {0, 1, 3, 50, 75};
//    int arr[] = {INT_MAX};
    int arr[] = {-1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
//    vector<string> res = findMissingRanges(v_arr, 0, INT_MAX);
    vector<string> res = findMissingRanges(v_arr, -2, -1);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}