#include "header.h"

void search(vector<int>& S, int curr_idx, vector<int>& curr_subset, vector<vector<int> >& res){
    if(curr_idx == S.size()){
        res.push_back(curr_subset);
        return;
    }
    curr_subset.push_back(S[curr_idx]);
    search(S,curr_idx+1,curr_subset,res);
    curr_subset.pop_back();
    search(S,curr_idx+1,curr_subset,res);
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > res;
    if(S.size() == 0) return res;
    vector<int> curr_subset;
    search(S,0,curr_subset,res);
}

int main(){
    int arr[] = {1, 2, 3};
    vector<int> S(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = subsets(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
