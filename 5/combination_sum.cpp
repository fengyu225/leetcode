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

vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
    vector<vector<int> > res;
    int sz = candidates.size();
    if(sz == 0) return res;
    vector<int> s;
    sort(candidates.begin(), candidates.end());
    return res;
}

int main(){
    int arr[] = {2, 3, 6, 7};
    vector<int> candidates(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = combinationSum2(candidates,7);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
