#include "header.h"

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

void dfs(vector<int>& num, int curr, int curr_sum, int target, vector<vector<int> >& res, vector<int>& temp){
    if(curr_sum>target) return;
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }
    for(int i=curr;i<num.size();){
        temp.push_back(num[i]);
        dfs(num,i+1,curr_sum+num[i],target,res,temp);
        temp.pop_back();
        do{
            i++;
        }while(num[i] == num[i-1]);
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > res;
    vector<int> temp;
    dfs(num,0,0,target,res,temp);
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
