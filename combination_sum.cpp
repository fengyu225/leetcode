#include "header.h"

void dfs(vector<int>& candidates, int sum, int target, vector<vector<int> >& res, vector<int>& temp, int curr_idx){
    if(sum>target) return;
    if(sum == target){
        res.push_back(temp);
        return;
    }
    for(int i=curr_idx; i<candidates.size(); i++){
        temp.push_back(candidates[i]);
        dfs(candidates, sum+candidates[i], target, res, temp, i);
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    std::sort(candidates.begin(), candidates.end());
    vector<int> temp;
    dfs(candidates, 0, target, res, temp, 0);
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
