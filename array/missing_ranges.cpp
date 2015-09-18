/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

#include "header.h"

void addRange(long l, long r, vector<string>& res){
    if(l>r) return;
    string temp;
    if(l == r) temp = to_string(l);
    if(l<r) temp = to_string(l)+"->"+to_string(r);
    res.push_back(temp);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int sz = nums.size();
    vector<string> res;
    if(sz == 0) return lower == upper?vector<string>(1, to_string(lower)):vector<string>(1, to_string(lower)+"->"+to_string(upper));
    addRange(lower, nums[0]-1, res);
    int from = 0, curr = 1;
    while(curr<sz){
        if(nums[curr] == nums[curr-1]) curr++;
        else{
            addRange(nums[curr-1]+1, nums[curr]-1, res);
            from = curr++;
        }
    }
    addRange((long)nums[sz-1]+1, (long)upper, res);
    return res;
}

int main(){
    //int arr[] = {0, 1, 3, 50, 75};
 //   int arr[] = {INT_MAX};
    //int arr[] = {-1};
   vector<int> v_arr = {INT_MAX};
//    vector<int> v_arr = {0, 1, 3, 50, 75};
//    vector<int> v_arr = {-1};
    vector<string> res = findMissingRanges(v_arr, 1, INT_MAX);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}