/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

#include "header.h"

void search(vector<int>& candidates, int curr, int curr_sum, int target, vector<int>& temp, vector<vector<int> >& res){
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }
    if(curr_sum>target || curr == candidates.size()) return;
    temp.push_back(candidates[curr]);
    search(candidates, curr, curr_sum+candidates[curr], target, temp, res);
    temp.pop_back();
    search(candidates, curr+1, curr_sum, target, temp, res);
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    int sz = candidates.size();
    vector<vector<int> > res;
    if(sz == 0) return res;
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    search(candidates,0,0,target,temp,res);
    return res;
}

int main(){
    int arr[] = {2, 3, 6, 7};
    vector<int> candidates(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = combinationSum(candidates,7);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
