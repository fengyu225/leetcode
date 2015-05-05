#include "header.h"

void search(vector<int>& candidates, int curr_idx, int curr_sum, int target, vector<int>& temp, vector<vector<int> >& res){
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }
    if(curr_sum > target)
        return;
    if(curr_idx >= candidates.size())
        return;
    temp.push_back(candidates[curr_idx]);
    search(candidates,curr_idx,curr_sum+candidates[curr_idx],target,temp,res);
    temp.pop_back();
    int i = curr_idx+1;
    while(i<candidates.size() && candidates[i] == candidates[i-1]) i++;
    search(candidates,i,curr_sum,target,temp,res);
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    if(candidates.size() == 0) return res;
    std::sort(candidates.begin(), candidates.end());
    vector<int> temp;
    search(candidates, 0, 0, target, temp, res);
    return res;
}

int main(){
    int arr[] = {2, 2, 3, 6, 6, 7};
    vector<int> candidates(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = combinationSum(candidates,7);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
