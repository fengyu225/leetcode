#include "header.h"

void dfs(vector<int>& candidates, int sum, int target, vector<vector<int> >& res, vector<int>& temp, int curr_idx){
    if(sum>target) return;
    if(sum == target){
        res.push_back(temp);
        return;
    }
    for(int i=curr_idx; i<candidates.size();){
        temp.push_back(candidates[i]);
        dfs(candidates, sum+candidates[i], target, res, temp, i+1);
        temp.pop_back();
        do{
            i++;
        }while(candidates[i] == candidates[i-1]);
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > res;
    std::sort(num.begin(), num.end());
    vector<int> temp;
    dfs(num, 0, target, res, temp, 0);
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
