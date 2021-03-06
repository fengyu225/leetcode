/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include "header.h"

void search(vector<int>& candidates,int curr_idx, int target,int curr_sum, vector<int>& temp, vector<vector<int> >& res){
    int sz = candidates.size();
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }
    if(curr_idx>=sz || curr_sum>target) return;
    vector<int> orig = temp;
    int x = curr_idx+1;
    int orig_sum = curr_sum;
    while(x<sz && candidates[x] == candidates[x-1]) x++;
    for(int i=curr_idx; i<x; i++){
        temp.push_back(candidates[curr_idx]);
        curr_sum += candidates[curr_idx];
        search(candidates,x,target,curr_sum,temp,res);
    }
    temp = orig;
    search(candidates,x,target,orig_sum,temp,res);
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
    int sz = candidates.size();
    vector<vector<int> > res;
    if(sz == 0) return res;
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    int curr_sum = 0;
    search(candidates,0,target,curr_sum,temp,res);
    return res;
}

int main(){
    //int arr[] = {10,1,2,7,6,1,5};
    //int arr[] = {2,1,3,1,4};
    int arr[] = {1,1,2,5,6,7,10};
    //int arr[] = {1,1};
    vector<int> candidates(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = combinationSum2(candidates,10);
//    vector<vector<int> > res = combinationSum2(candidates,8);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
