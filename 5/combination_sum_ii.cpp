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

void search(vector<int>& num, int curr_idx, int curr_sum, int target, vector<int>& temp, vector<vector<int> >& res){
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }
    if(curr_sum > target)
        return;
    if(curr_idx >= num.size())
        return;
    temp.push_back(num[curr_idx]);
    search(num,curr_idx+1,curr_sum+num[curr_idx],target,temp,res);
    temp.pop_back();
    int i = curr_idx+1;
    while(i<num.size() && num[i] == num[i-1]) i++;
    search(num,i,curr_sum,target,temp,res);
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > res;
    if(num.size() == 0) return res;
    std::sort(num.begin(), num.end());
    vector<int> temp;
    search(num,0,0,target,temp,res);
    return res;
}

int main(){
    //int arr[] = {10,1,2,7,6,1,5};
    //int arr[] = {1,1,2,5,6,7,10};
    int arr[] = {1,1};
    vector<int> candidates(arr,arr+sizeof(arr)/sizeof(arr[0]));
    //vector<vector<int> > res = combinationSum2(candidates,8);
    vector<vector<int> > res = combinationSum2(candidates,1);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
