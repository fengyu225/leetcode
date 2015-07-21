/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include "header.h"

vector<string> summaryRanges(vector<int>& nums){
    int sz = nums.size();
    vector<string> res;
    if(sz == 0) return res;
    int head = 0, tail = 0;
    for(int i=1; i<sz; i++){
        if(nums[i] == nums[tail]+1) tail++;
        else{
            res.push_back(head==tail?to_string(nums[head]):to_string(nums[head])+"->"+to_string(nums[tail]));
            head = tail = i;
        }
    }
    res.push_back(head==tail?to_string(nums[head]):to_string(nums[head])+"->"+to_string(nums[tail]));
    return res;
}

int main(){
    //int arr[] = {0, 1, 2, 4, 5, 7};
    int arr[] = {0, 2, 4, 6, 8};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<string> res = summaryRanges(v_arr);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}